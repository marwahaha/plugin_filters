import openfl.display3D.*;
import openfl.errors.*;
import openfl.Vector;

import starling.rendering.*;
import starling.filters.*;
import starling.utils.Color;

import haxegon.*;

@:access(haxegon.Core)
@:access(haxegon.Gfx)
class Filter {
	public static function enable(){
		if (!enabled){
			enabled = true;
			Core.registerplugin("filters", "0.1.0");
      Core.checkrequirement("filters", "haxegon", "0.12.0");
			createfilters();
			
			reset();
			
			Core.extend_endframe(updatefilters);
		}
	}
	
	private static function createfilters(){
		bloomfilter = new CustomFilter(bloomprogram);
		bloomfilter.setfc0(0, 0, 0, 2.5);
		bloomfilter.setfc1(-1.0, 0.0, 1.0, 9.0);
		bloomfilter.setfc2(1.0, 1.0, 1.0, 1.0);
		
		colortransformfilter = new Simplefilter();
	}
	
	private static var colortransformfilter:Simplefilter;
	private static var _hueshift:Float;
	private static var _saturationshift:Float;
	private static var _lightnessshift:Float;
	private static var _contrastshift:Float;
	private static var _invert:Bool;
	private static var _blur:Float;
	private static var _bloom:Float;
	
	/* Turn all filter effects off */
	public static function reset() {
		if (!enabled) enable();
		_blur = 0;
		_bloom = 0;
		_invert = false;
		_hueshift = 0;
		_saturationshift = 0;
		_lightnessshift = 0;
		_contrastshift = 0;
		
		if (Gfx.screen != null){
			if(Gfx.screen.filter != null){
				Gfx.screen.filter.dispose();
			}
			Gfx.screen.filter = null;
		}
	}
	
	public static var hue(get, set):Float;
	static function get_hue():Float { return _hueshift * 360; }
	static function set_hue(_b:Float):Float {
		_hueshift = _b / 360;
		updatefilters();
		
	  return _hueshift;
	}
	
	public static var saturation(get, set):Float;
	static function get_saturation():Float { return _saturationshift; }
	static function set_saturation(_b:Float):Float {
		_saturationshift = _b;
		updatefilters();
		
	  return _saturationshift;
	}
	
	public static var lightness(get, set):Float;
	static function get_lightness():Float { return _lightnessshift; }
	static function set_lightness(_b:Float):Float {
		_lightnessshift = _b;
		updatefilters();
		
	  return _lightnessshift;
	}
	
	public static var contrast(get, set):Float;
	static function get_contrast():Float { return _contrastshift; }
	static function set_contrast(_b:Float):Float {
		_contrastshift = _b;
		updatefilters();
		
	  return _contrastshift;
	}
	
	public static var invert(get, set):Bool;
	static function get_invert():Bool{ return _invert; }
	static function set_invert(inv:Bool):Bool{
		_invert = inv;
		updatefilters();
		
		return _invert;
	}
	
	public static var blur(get, set):Float;
	static function get_blur():Float { return _blur; }
	static function set_blur(_b:Float):Float {
		_blur = _b;
		updatefilters();
		
	  return _blur;
	}
	
	public static var bloom(get, set):Float;
	private static var bloomfilter:CustomFilter;
	static function get_bloom():Float { return _bloom; }
	static function set_bloom(_b:Float):Float {
		_bloom = _b;
		updatefilters();
		
	  return _bloom;
	}
	
	private static function updatefilters() {
		if (!enabled) enable();
	  //When a filter changes, call this function internally to update the currently active filter	
		if (Gfx.screen != null){
			Gfx.screen.filter = null;
			
			var filterchain:Array<FragmentFilter> = [];
			
			//Bloom and blur use the same filter object
			if (_bloom > 0) {
				bloomfilter.setfc0(0, Gfx.screenwidth, Gfx.screenheight, 1 / (Geom.clamp((_bloom + 0.5) * 2, 0, 2.5) + _blur));
				bloomfilter.setfc2((_bloom / 2) + 0.5, (_bloom / 2) + 0.5, (_bloom / 2) + 0.5, 1.0);
				
				filterchain.push(bloomfilter);
			}else if (_blur > 0) {
				bloomfilter.setfc0(0, Gfx.screenwidth, Gfx.screenheight, 1 / _blur);
				bloomfilter.setfc2(0.5, 0.5, 0.5, _blur);
				
				filterchain.push(bloomfilter);
			}
			
			//Colour transforms
			colortransformfilter.reset();
			if (_hueshift != 0)	colortransformfilter.adjustHue(_hueshift);
			if (_saturationshift != 0) colortransformfilter.adjustSaturation(_saturationshift);
			if (_lightnessshift != 0)	colortransformfilter.adjustBrightness(_lightnessshift);
			if (_contrastshift != 0) colortransformfilter.adjustContrast(_contrastshift);
			if (_invert) colortransformfilter.invert();
			
			if (_invert || _hueshift != 0 || _saturationshift != 0 || _lightnessshift != 0
			  || _contrastshift != 0){
				filterchain.push(colortransformfilter);
			}
			
			if (filterchain.length == 0){
				Gfx.screen.filter = null;
			}else{
				Gfx.screen.filter = new FilterChain(filterchain);
			}
		}
	}
	
	private static var enabled:Bool = false;
	
	private static inline var bloomprogram:String = 
	  "tex ft0, v0, fs0<2d, clamp, linear, mipnone>  \n" +
		
		//output
		"mov ft1, fc0.xxxx  \n" +
		
		//size
		"mov ft2.x, fc0.y  \n" +
		"mul ft2.x, ft2.x, fc0.w  \n" +
		"div ft2.x, fc1.z, ft2.x  \n" + //rcp isn't working? line should be "rcp ft2.x, ft2.x"
		"mov ft2.y, fc0.z  \n" +
		"mul ft2.y, ft2.y, fc0.w  \n" +
		"div ft2.y, fc1.z, ft2.y  \n" + //rcp isn't working? line should be "rcp ft2.y, ft2.y"
		// START UNWRAPPED LOOP
		
		//1
		"mov ft3.xy, fc1.xx  \n" +
		"mul ft3.xy, ft3.xy, ft2.xy  \n" +
		"add ft3.xy, ft3.xy, v0.xy  \n" +
		"tex ft4, ft3.xy, fs0<2d, clamp, linear, mipnone>  \n" +
		"add ft1, ft1, ft4  \n" +
		
		//2
		"mov ft3.xy, fc1.xy  \n" +
		"mul ft3.xy, ft3.xy, ft2.xy  \n" +
		"add ft3.xy, ft3.xy, v0.xy  \n" +
		"tex ft4, ft3.xy, fs0<2d, clamp, linear, mipnone>  \n" +
		"add ft1, ft1, ft4  \n" +
		
		//3
		"mov ft3.xy, fc1.xz  \n" +
		"mul ft3.xy, ft3.xy, ft2.xy  \n" +
		"add ft3.xy, ft3.xy, v0.xy  \n" +
		"tex ft4, ft3.xy, fs0<2d, clamp, linear, mipnone>  \n" +
		"add ft1, ft1, ft4  \n" +
		
		//4
		"mov ft3.xy, fc1.yx  \n" +
		"mul ft3.xy, ft3.xy, ft2.xy  \n" +
		"add ft3.xy, ft3.xy, v0.xy  \n" +
		"tex ft4, ft3.xy, fs0<2d, clamp, linear, mipnone>  \n" +
		"add ft1, ft1, ft4  \n" +
		
		//5
		"mov ft3.xy, fc1.yy  \n" +
		"mul ft3.xy, ft3.xy, ft2.xy  \n" +
		"add ft3.xy, ft3.xy, v0.xy  \n" +
		"tex ft4, ft3.xy, fs0<2d, clamp, linear, mipnone>  \n" +
		"add ft1, ft1, ft4  \n" +
		
		//6
		"mov ft3.xy, fc1.yz  \n" +
		"mul ft3.xy, ft3.xy, ft2.xy  \n" +
		"add ft3.xy, ft3.xy, v0.xy  \n" +
		"tex ft4, ft3.xy, fs0<2d, clamp, linear, mipnone>  \n" +
		"add ft1, ft1, ft4  \n" +
		
		//7
		"mov ft3.xy, fc1.zx  \n" +
		"mul ft3.xy, ft3.xy, ft2.xy  \n" +
		"add ft3.xy, ft3.xy, v0.xy  \n" +
		"tex ft4, ft3.xy, fs0<2d, clamp, linear, mipnone>  \n" +
		"add ft1, ft1, ft4  \n" +
		
		//8
		"mov ft3.xy, fc1.zy  \n" +
		"mul ft3.xy, ft3.xy, ft2.xy  \n" +
		"add ft3.xy, ft3.xy, v0.xy  \n" +
		"tex ft4, ft3.xy, fs0<2d, clamp, linear, mipnone>  \n" +
		"add ft1, ft1, ft4  \n" +
		
		//9
		"mov ft3.xy, fc1.zz  \n" +
		"mul ft3.xy, ft3.xy, ft2.xy  \n" +
		"add ft3.xy, ft3.xy, v0.xy  \n" +
		"tex ft4, ft3.xy, fs0<2d, clamp, linear, mipnone>  \n" +
		"add ft1, ft1, ft4  \n" +
		
		// END LOOP
		
		// average out
		"div ft1, ft1, fc1.wwww  \n" +
		"add ft1, ft1, ft0  \n" +
		
		// multiply by color
		"mul oc, ft1, fc2";
}

class Simplefilter extends FragmentFilter
{
    // Most of the color transformation math was taken from the excellent ColorMatrix class by
    // Mario Klingemann: http://www.quasimondo.com/archives/000565.php -- THANKS!!!

    private static inline var LUMA_R:Float = 0.299;
    private static inline var LUMA_G:Float = 0.587;
    private static inline var LUMA_B:Float = 0.114;

    // helpers
    private static var sMatrix:Vector<Float> = new Vector<Float>();

    /** Creates a new ColorMatrixFilter instance with the specified matrix.
     *  @param matrix a vector of 20 items arranged as a 4x5 matrix.
     */
    public function new(matrix:Vector<Float>=null)
    {
        super();
        if (matrix != null) colorEffect.matrix = matrix;
    }

    /** @private */
    override private function createEffect():FilterEffect
    {
        return new ColorMatrixEffect();
    }

    // color manipulation

    /** Inverts the colors of the filtered object. */
    public function invert():Void
    {
        concatValues(-1,  0,  0,  0, 255,
                      0, -1,  0,  0, 255,
                      0,  0, -1,  0, 255,
                      0,  0,  0,  1,   0);
    }

    /** Changes the saturation. Typical values are in the range (-1, 1).
     *  Values above zero will raise, values below zero will reduce the saturation.
     *  '-1' will produce a grayscale image. */
    public function adjustSaturation(sat:Float):Void
    {
        sat += 1;

        var invSat:Float  = 1 - sat;
        var invLumR:Float = invSat * LUMA_R;
        var invLumG:Float = invSat * LUMA_G;
        var invLumB:Float = invSat * LUMA_B;

        concatValues((invLumR + sat), invLumG,  invLumB, 0, 0,
                      invLumR, (invLumG + sat), invLumB, 0, 0,
                      invLumR, invLumG, (invLumB + sat), 0, 0,
                      0, 0, 0, 1, 0);
    }

    /** Changes the contrast. Typical values are in the range (-1, 1).
     *  Values above zero will raise, values below zero will reduce the contrast. */
    public function adjustContrast(value:Float):Void
    {
        var s:Float = value + 1;
        var o:Float = 128 * (1 - s);

        concatValues(s, 0, 0, 0, o,
                     0, s, 0, 0, o,
                     0, 0, s, 0, o,
                     0, 0, 0, 1, 0);
    }

    /** Changes the brightness. Typical values are in the range (-1, 1).
     *  Values above zero will make the image brighter, values below zero will make it darker.*/
    public function adjustBrightness(value:Float):Void
    {
        value *= 255;

        concatValues(1, 0, 0, 0, value,
                     0, 1, 0, 0, value,
                     0, 0, 1, 0, value,
                     0, 0, 0, 1, 0);
    }

    /** Changes the hue of the image. Typical values are in the range (-1, 1). */
    public function adjustHue(value:Float):Void
    {
        value *= Math.PI;

        var cos:Float = Math.cos(value);
        var sin:Float = Math.sin(value);

        concatValues(
            ((LUMA_R + (cos * (1 - LUMA_R))) + (sin * -(LUMA_R))), ((LUMA_G + (cos * -(LUMA_G))) + (sin * -(LUMA_G))), ((LUMA_B + (cos * -(LUMA_B))) + (sin * (1 - LUMA_B))), 0, 0,
            ((LUMA_R + (cos * -(LUMA_R))) + (sin * 0.143)), ((LUMA_G + (cos * (1 - LUMA_G))) + (sin * 0.14)), ((LUMA_B + (cos * -(LUMA_B))) + (sin * -0.283)), 0, 0,
            ((LUMA_R + (cos * -(LUMA_R))) + (sin * -((1 - LUMA_R)))), ((LUMA_G + (cos * -(LUMA_G))) + (sin * LUMA_G)), ((LUMA_B + (cos * (1 - LUMA_B))) + (sin * LUMA_B)), 0, 0,
            0, 0, 0, 1, 0);
    }

    /** Tints the image in a certain color, analog to what can be done in Adobe Animate.
     *
     *  @param color   the RGB color with which the image should be tinted.
     *  @param amount  the intensity with which tinting should be applied. Range (0, 1).
     */
    public function tint(color:UInt, amount:Float=1.0):Void
    {
        var r:Float = Color.getRed(color)   / 255.0;
        var g:Float = Color.getGreen(color) / 255.0;
        var b:Float = Color.getBlue(color)  / 255.0;
        var q:Float = 1 - amount;

        var rA:Float = amount * r;
        var gA:Float = amount * g;
        var bA:Float = amount * b;

        concatValues(
            q + rA * LUMA_R, rA * LUMA_G, rA * LUMA_B, 0, 0,
            gA * LUMA_R, q + gA * LUMA_G, gA * LUMA_B, 0, 0,
            bA * LUMA_R, bA * LUMA_G, q + bA * LUMA_B, 0, 0,
            0, 0, 0, 1, 0);
    }

    // matrix manipulation

    /** Changes the filter matrix back to the identity matrix. */
    public function reset():Void
    {
        matrix = null;
    }

    /** Concatenates the current matrix with another one. */
    public function concat(matrix:Vector<Float>):Void
    {
        colorEffect.concat(matrix);
        setRequiresRedraw();
    }

    /** Concatenates the current matrix with another one, passing its contents directly. */
    public function concatValues(m0:Float, m1:Float, m2:Float, m3:Float, m4:Float,
                                 m5:Float, m6:Float, m7:Float, m8:Float, m9:Float,
                                 m10:Float, m11:Float, m12:Float, m13:Float, m14:Float,
                                 m15:Float, m16:Float, m17:Float, m18:Float, m19:Float):Void
    {
        sMatrix.length = 0;
        sMatrix[0] = m0; sMatrix[1] = m1; sMatrix[2] = m2; sMatrix[3] = m3;
        sMatrix[4] = m4; sMatrix[5] = m5; sMatrix[6] = m6; sMatrix[7] = m7;
        sMatrix[8] = m8; sMatrix[9] = m9; sMatrix[10] = m10; sMatrix[11] = m11;
        sMatrix[12] = m12; sMatrix[13] = m13; sMatrix[14] = m14; sMatrix[15] = m15;
        sMatrix[16] = m16; sMatrix[17] = m17; sMatrix[18] = m18; sMatrix[19] = m19;

        concat(sMatrix);
    }

    /** A vector of 20 items arranged as a 4x5 matrix. */
    public var matrix(get, set):Vector<Float>;
    private function get_matrix():Vector<Float> { return colorEffect.matrix; }
    private function set_matrix(value:Vector<Float>):Vector<Float>
    {
        colorEffect.matrix = value;
        setRequiresRedraw();
        return value;
    }

    public var colorEffect(get, never):ColorMatrixEffect;
    private function get_colorEffect():ColorMatrixEffect
    {
        return cast this.effect;
    }
}

class ColorMatrixEffect extends FilterEffect
{
    private var _userMatrix:Vector<Float>;   // offset in range 0-255
    private var _shaderMatrix:Vector<Float>; // offset in range 0-1, changed order

    private static var MIN_COLOR:Vector<Float> = Vector.ofArray([0, 0, 0, 0.0001]);
    private static var IDENTITY:Array<Float> = [1,0,0,0,0,  0,1,0,0,0,  0,0,1,0,0,  0,0,0,1,0];

    // helpers
    private static var sMatrix:Vector<Float> = new Vector<Float>(20, true);

    public function new():Void
    {
        super();

        _userMatrix   = new Vector<Float>();
        _shaderMatrix = new Vector<Float>();

        this.matrix = null;
    }

    override private function createProgram():Program
    {
        var vertexShader:String = FilterEffect.STD_VERTEX_SHADER;
        var fragmentShader:String = [
            FilterEffect.tex("ft0", "v0", 0, texture),      // read texture color
            "max ft0, ft0, fc5              ", // avoid division through zero in next step
            "div ft0.xyz, ft0.xyz, ft0.www  ", // restore original (non-PMA) RGB values
            "m44 ft0, ft0, fc0              ", // multiply color with 4x4 matrix
            "add ft0, ft0, fc4              ", // add offset
            "mul ft0.xyz, ft0.xyz, ft0.www  ", // multiply with alpha again (PMA)
            "mov oc, ft0                    "  // copy to output
        ].join("\n");

        return Program.fromSource(vertexShader, fragmentShader);
    }

    override private function beforeDraw(context:Context3D):Void
    {
        super.beforeDraw(context);

        context.setProgramConstantsFromVector(Context3DProgramType.FRAGMENT, 0, _shaderMatrix);
        context.setProgramConstantsFromVector(Context3DProgramType.FRAGMENT, 5, MIN_COLOR);
    }

    // matrix manipulation

    public function reset():Void
    {
        matrix = null;
    }

    /** Concatenates the current matrix with another one. */
    public function concat(matrix:Vector<Float>):Void
    {
        var i:Int = 0;

        for (y in 0...4)
        {
            for (x in 0...5)
            {
                sMatrix[i+x] = matrix[i    ] * _userMatrix[x     ] +
                               matrix[i + 1] * _userMatrix[x +  5] +
                               matrix[i + 2] * _userMatrix[x + 10] +
                               matrix[i + 3] * _userMatrix[x + 15] +
                               (x == 4 ? matrix[i + 4] : 0);
            }

            i += 5;
        }

        copyMatrix(sMatrix, _userMatrix);
        updateShaderMatrix();
    }

    private function copyMatrix(from:Vector<Float>, to:Vector<Float>):Void
    {
        for (i in 0...20)
            to[i] = from[i];
    }

    private function updateShaderMatrix():Void
    {
        // the shader needs the matrix components in a different order,
        // and it needs the offsets in the range 0-1.

        _shaderMatrix.length = 0;
        _shaderMatrix.push(_userMatrix[0 ]); _shaderMatrix.push(_userMatrix[ 1]); _shaderMatrix.push(_userMatrix[ 2]); _shaderMatrix.push(_userMatrix[ 3]);
        _shaderMatrix.push(_userMatrix[5 ]); _shaderMatrix.push(_userMatrix[ 6]); _shaderMatrix.push(_userMatrix[ 7]); _shaderMatrix.push(_userMatrix[ 8]);
        _shaderMatrix.push(_userMatrix[10]); _shaderMatrix.push(_userMatrix[11]); _shaderMatrix.push(_userMatrix[12]); _shaderMatrix.push(_userMatrix[13]);
        _shaderMatrix.push(_userMatrix[15]); _shaderMatrix.push(_userMatrix[16]); _shaderMatrix.push(_userMatrix[17]); _shaderMatrix.push(_userMatrix[18]);
        _shaderMatrix.push(_userMatrix[ 4] / 255.0); _shaderMatrix.push(_userMatrix[9] / 255.0); _shaderMatrix.push(_userMatrix[14] / 255.0);
        _shaderMatrix.push(_userMatrix[19] / 255.0);
    }

    // properties

    public var matrix(get, set):Vector<Float>;
    private function get_matrix():Vector<Float> { return _userMatrix; }
    private function set_matrix(value:Vector<Float>):Vector<Float>
    {
        if (value != null && value.length != 20)
            throw new ArgumentError("Invalid matrix length: must be 20");

        if (value == null)
        {
            _userMatrix.length = 0;
            for (val in IDENTITY)
            {
                _userMatrix.push(val);
            }
        }
        else
        {
            copyMatrix(value, _userMatrix);
        }

        updateShaderMatrix();
        return value;
    }
}

@:access(Filter)
@:access(CustomEffect)
class CustomFilter extends FragmentFilter{
	public function new(_fragmentshader:String){
		fragmentshader = _fragmentshader;
		super();
		
		actualeffect = new CustomEffect(fragmentshader);
	}
	
	/** @private */
	override private function createEffect():FilterEffect{
		return cast(actualeffect, FilterEffect);
	}
	
	public function setfc0(a:Float, b:Float, c:Float, d:Float){
		actualeffect.fc0[0] = a; actualeffect.fc0[1] = b; actualeffect.fc0[2] = c; actualeffect.fc0[3] = d;
		actualeffect.usefc0 = true;
	}
	
	public function setfc1(a:Float, b:Float, c:Float, d:Float){
		actualeffect.fc1[0] = a; actualeffect.fc1[1] = b; actualeffect.fc1[2] = c; actualeffect.fc1[3] = d;
		actualeffect.usefc1 = true;
	}
	
	public function setfc2(a:Float, b:Float, c:Float, d:Float){
		actualeffect.fc2[0] = a; actualeffect.fc2[1] = b; actualeffect.fc2[2] = c; actualeffect.fc2[3] = d;
		actualeffect.usefc2 = true;
	}
	
	public function setfc3(a:Float, b:Float, c:Float, d:Float){
		actualeffect.fc3[0] = a; actualeffect.fc3[1] = b; actualeffect.fc3[2] = c; actualeffect.fc3[3] = d;
		actualeffect.usefc3 = true;
	}
	
	private var fragmentshader:String;
	private var actualeffect:CustomEffect;
}

class CustomEffect extends FilterEffect {
	private var fc0:Vector<Float>; private var usefc0:Bool;
	private var fc1:Vector<Float>; private var usefc1:Bool;
	private var fc2:Vector<Float>; private var usefc2:Bool;
	private var fc3:Vector<Float>; private var usefc3:Bool;
	public var fragmentshader:String;
	
  public function new(shader:String) {
	  super();
		
		usefc0 = false; fc0 = Vector.ofArray(cast [0, 0, 0, 0]);
		usefc1 = false; fc1 = Vector.ofArray(cast [0, 0, 0, 0]);
		usefc2 = false; fc2 = Vector.ofArray(cast [0, 0, 0, 0]);
		usefc3 = false; fc3 = Vector.ofArray(cast [0, 0, 0, 0]);
		
		fragmentshader = shader;
	}
	
	override private function createProgram():Program {
    return Program.fromSource(FilterEffect.STD_VERTEX_SHADER, fragmentshader);
  }
	
	override private function beforeDraw(context:Context3D):Void {
		super.beforeDraw(context);
    
		if (usefc0) context.setProgramConstantsFromVector(Context3DProgramType.FRAGMENT, 0, fc0);
		if (usefc1) context.setProgramConstantsFromVector(Context3DProgramType.FRAGMENT, 1, fc1);
		if (usefc2) context.setProgramConstantsFromVector(Context3DProgramType.FRAGMENT, 2, fc2);
		if (usefc3) context.setProgramConstantsFromVector(Context3DProgramType.FRAGMENT, 3, fc3);
  }
}