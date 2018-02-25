// Generated by Haxe 3.4.4
#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxegon_HaxegonChannel
#include <haxegon/HaxegonChannel.h>
#endif
#ifndef INCLUDED_haxegon_HaxegonSound
#include <haxegon/HaxegonSound.h>
#endif
#ifndef INCLUDED_haxegon_Sound
#include <haxegon/Sound.h>
#endif
#ifndef INCLUDED_openfl_Lib
#include <openfl/Lib.h>
#endif
#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_media_Sound
#include <openfl/media/Sound.h>
#endif
#ifndef INCLUDED_openfl_media_SoundChannel
#include <openfl/media/SoundChannel.h>
#endif
#ifndef INCLUDED_openfl_media_SoundTransform
#include <openfl/media/SoundTransform.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_807ea0814ee6c299_8_new,"haxegon.HaxegonChannel","new",0x3a713523,"haxegon.HaxegonChannel.new","haxegon/Sound.hx",8,0xc71b57be)
HX_LOCAL_STACK_FRAME(_hx_pos_807ea0814ee6c299_13_setto,"haxegon.HaxegonChannel","setto",0x82020920,"haxegon.HaxegonChannel.setto","haxegon/Sound.hx",13,0xc71b57be)
HX_LOCAL_STACK_FRAME(_hx_pos_807ea0814ee6c299_27_play,"haxegon.HaxegonChannel","play",0xe9f4f3d1,"haxegon.HaxegonChannel.play","haxegon/Sound.hx",27,0xc71b57be)
HX_LOCAL_STACK_FRAME(_hx_pos_807ea0814ee6c299_44_oncomplete,"haxegon.HaxegonChannel","oncomplete",0xbd512275,"haxegon.HaxegonChannel.oncomplete","haxegon/Sound.hx",44,0xc71b57be)
HX_LOCAL_STACK_FRAME(_hx_pos_807ea0814ee6c299_52_changevolume,"haxegon.HaxegonChannel","changevolume",0xbbbbda27,"haxegon.HaxegonChannel.changevolume","haxegon/Sound.hx",52,0xc71b57be)
HX_LOCAL_STACK_FRAME(_hx_pos_807ea0814ee6c299_57_changepan,"haxegon.HaxegonChannel","changepan",0x5b351ef0,"haxegon.HaxegonChannel.changepan","haxegon/Sound.hx",57,0xc71b57be)
HX_LOCAL_STACK_FRAME(_hx_pos_807ea0814ee6c299_65_get_position,"haxegon.HaxegonChannel","get_position",0x29e3bf8f,"haxegon.HaxegonChannel.get_position","haxegon/Sound.hx",65,0xc71b57be)
HX_LOCAL_STACK_FRAME(_hx_pos_807ea0814ee6c299_72_set_position,"haxegon.HaxegonChannel","set_position",0x3edce303,"haxegon.HaxegonChannel.set_position","haxegon/Sound.hx",72,0xc71b57be)
HX_LOCAL_STACK_FRAME(_hx_pos_807ea0814ee6c299_88_get_length,"haxegon.HaxegonChannel","get_length",0xc9130e4c,"haxegon.HaxegonChannel.get_length","haxegon/Sound.hx",88,0xc71b57be)
HX_LOCAL_STACK_FRAME(_hx_pos_807ea0814ee6c299_97_stop,"haxegon.HaxegonChannel","stop",0xebf6b5df,"haxegon.HaxegonChannel.stop","haxegon/Sound.hx",97,0xc71b57be)
HX_LOCAL_STACK_FRAME(_hx_pos_807ea0814ee6c299_110_updatefade,"haxegon.HaxegonChannel","updatefade",0x4b157da2,"haxegon.HaxegonChannel.updatefade","haxegon/Sound.hx",110,0xc71b57be)
namespace haxegon{

void HaxegonChannel_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_807ea0814ee6c299_8_new)
HXLINE(   9)		this->free = true;
HXLINE(  10)		this->fading = (int)0;
            	}

Dynamic HaxegonChannel_obj::__CreateEmpty() { return new HaxegonChannel_obj; }

void *HaxegonChannel_obj::_hx_vtable = 0;

Dynamic HaxegonChannel_obj::__Create(hx::DynamicArray inArgs)
{
	hx::ObjectPtr< HaxegonChannel_obj > _hx_result = new HaxegonChannel_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool HaxegonChannel_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x36ccf3bb;
}

void HaxegonChannel_obj::setto(::String _soundname,hx::Null< Float >  __o__offsettime,hx::Null< Float >  __o__fadeintime,hx::Null< bool >  __o__loop,hx::Null< Float >  __o__volume,hx::Null< Float >  __o__panning){
Float _offsettime = __o__offsettime.Default(0);
Float _fadeintime = __o__fadeintime.Default(0);
bool _loop = __o__loop.Default(false);
Float _volume = __o__volume.Default(1);
Float _panning = __o__panning.Default(0);
            	HX_STACKFRAME(&_hx_pos_807ea0814ee6c299_13_setto)
HXLINE(  14)		this->free = false;
HXLINE(  15)		this->fading = (int)0;
HXLINE(  16)		this->soundname = _soundname;
HXLINE(  17)		this->offsettime = _offsettime;
HXLINE(  18)		this->fadeintime = _fadeintime;
HXLINE(  19)		this->panning = _panning;
HXLINE(  20)		this->looping = _loop;
HXLINE(  21)		this->volume = _volume;
HXLINE(  23)		this->play(this->soundname,this->offsettime,this->fadeintime,this->volume,this->panning);
HXLINE(  24)		this->channel->addEventListener(HX_("soundComplete",a8,30,e6,1c),this->oncomplete_dyn(),null(),null(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC6(HaxegonChannel_obj,setto,(void))

void HaxegonChannel_obj::play(::String _soundname,hx::Null< Float >  __o__offsettime,hx::Null< Float >  __o__fadeintime,hx::Null< Float >  __o__volume,hx::Null< Float >  __o__panning){
Float _offsettime = __o__offsettime.Default(0);
Float _fadeintime = __o__fadeintime.Default(0);
Float _volume = __o__volume.Default(1);
Float _panning = __o__panning.Default(0);
            	HX_GC_STACKFRAME(&_hx_pos_807ea0814ee6c299_27_play)
HXLINE(  28)		::Array< ::Dynamic> s = ::haxegon::Sound_obj::soundfile;
HXDLIN(  28)		 ::haxegon::HaxegonSound s1 = s->__get(( (int)(::haxegon::Sound_obj::soundindex->get(_soundname)) )).StaticCast<  ::haxegon::HaxegonSound >();
HXLINE(  29)		 ::openfl::media::Sound s2 = s1->asset;
HXDLIN(  29)		this->channel = s2->play((_offsettime * (int)1000),null(),null());
HXLINE(  31)		if ((_fadeintime <= (int)0)) {
HXLINE(  32)			 ::openfl::media::SoundChannel _hx_tmp = this->channel;
HXDLIN(  32)			Float _hx_tmp1 = ::Math_obj::min((int)1,::Math_obj::max((this->volume * ::haxegon::Sound_obj::_mastervolume),(int)0));
HXDLIN(  32)			_hx_tmp->set_soundTransform( ::openfl::media::SoundTransform_obj::__alloc( HX_CTX ,_hx_tmp1,::Math_obj::min((int)1,::Math_obj::max(_panning,(int)-1))));
            		}
            		else {
HXLINE(  34)			this->fading = (int)-1;
HXDLIN(  34)			this->fadevolume = _volume;
HXLINE(  35)			this->fadestarttime = ::openfl::Lib_obj::getTimer();
HXLINE(  36)			Float _hx_tmp2 = this->fadestarttime;
HXDLIN(  36)			this->fadeendtime = (_hx_tmp2 + (_fadeintime * (int)1000));
HXLINE(  37)			this->changevolume((int)0);
HXLINE(  39)			 ::openfl::media::SoundChannel _hx_tmp3 = this->channel;
HXDLIN(  39)			Float _hx_tmp4 = ::Math_obj::min((int)1,::Math_obj::max((this->volume * ::haxegon::Sound_obj::_mastervolume),(int)0));
HXDLIN(  39)			_hx_tmp3->set_soundTransform( ::openfl::media::SoundTransform_obj::__alloc( HX_CTX ,_hx_tmp4,::Math_obj::min((int)1,::Math_obj::max(_panning,(int)-1))));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC5(HaxegonChannel_obj,play,(void))

void HaxegonChannel_obj::oncomplete( ::openfl::events::Event e){
            	HX_STACKFRAME(&_hx_pos_807ea0814ee6c299_44_oncomplete)
HXDLIN(  44)		if (this->looping) {
HXLINE(  45)			this->play(this->soundname,(int)0,(int)0,this->volume,this->panning);
HXLINE(  46)			this->channel->addEventListener(HX_("soundComplete",a8,30,e6,1c),this->oncomplete_dyn(),null(),null(),null());
            		}
            		else {
HXLINE(  48)			this->free = true;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(HaxegonChannel_obj,oncomplete,(void))

void HaxegonChannel_obj::changevolume(Float newvol){
            	HX_GC_STACKFRAME(&_hx_pos_807ea0814ee6c299_52_changevolume)
HXLINE(  53)		this->volume = newvol;
HXLINE(  54)		 ::openfl::media::SoundChannel _hx_tmp = this->channel;
HXDLIN(  54)		_hx_tmp->set_soundTransform( ::openfl::media::SoundTransform_obj::__alloc( HX_CTX ,::Math_obj::min((int)1,::Math_obj::max((this->volume * ::haxegon::Sound_obj::_mastervolume),(int)0)),::Math_obj::min((int)1,::Math_obj::max(this->panning,(int)-1))));
            	}


HX_DEFINE_DYNAMIC_FUNC1(HaxegonChannel_obj,changevolume,(void))

void HaxegonChannel_obj::changepan(Float newpan){
            	HX_GC_STACKFRAME(&_hx_pos_807ea0814ee6c299_57_changepan)
HXLINE(  58)		this->panning = newpan;
HXLINE(  59)		 ::openfl::media::SoundChannel _hx_tmp = this->channel;
HXDLIN(  59)		_hx_tmp->set_soundTransform( ::openfl::media::SoundTransform_obj::__alloc( HX_CTX ,::Math_obj::min((int)1,::Math_obj::max((this->volume * ::haxegon::Sound_obj::_mastervolume),(int)0)),::Math_obj::min((int)1,::Math_obj::max(this->panning,(int)-1))));
            	}


HX_DEFINE_DYNAMIC_FUNC1(HaxegonChannel_obj,changepan,(void))

Float HaxegonChannel_obj::get_position(){
            	HX_STACKFRAME(&_hx_pos_807ea0814ee6c299_65_get_position)
HXDLIN(  65)		if (this->free) {
HXLINE(  66)			return (int)0;
            		}
            		else {
HXLINE(  68)			return ((Float)this->channel->get_position() / (Float)(int)1000);
            		}
HXLINE(  65)		return ((Float)0.);
            	}


HX_DEFINE_DYNAMIC_FUNC0(HaxegonChannel_obj,get_position,return )

Float HaxegonChannel_obj::set_position(Float newposition){
            	HX_STACKFRAME(&_hx_pos_807ea0814ee6c299_72_set_position)
HXLINE(  73)		if (!(this->free)) {
HXLINE(  74)			this->_position = (newposition * (int)1000);
HXLINE(  79)			this->channel->set_position(this->_position);
            		}
HXLINE(  82)		return this->_position;
            	}


HX_DEFINE_DYNAMIC_FUNC1(HaxegonChannel_obj,set_position,return )

Float HaxegonChannel_obj::get_length(){
            	HX_STACKFRAME(&_hx_pos_807ea0814ee6c299_88_get_length)
HXDLIN(  88)		if (this->free) {
HXLINE(  89)			return (int)0;
            		}
            		else {
HXLINE(  91)			::Array< ::Dynamic> _hx_tmp = ::haxegon::Sound_obj::soundfile;
HXDLIN(  91)			return ((Float)_hx_tmp->__get(( (int)(::haxegon::Sound_obj::soundindex->get(this->soundname)) )).StaticCast<  ::haxegon::HaxegonSound >()->asset->get_length() / (Float)(int)1000);
            		}
HXLINE(  88)		return ((Float)0.);
            	}


HX_DEFINE_DYNAMIC_FUNC0(HaxegonChannel_obj,get_length,return )

void HaxegonChannel_obj::stop(hx::Null< Float >  __o_fadeout){
Float fadeout = __o_fadeout.Default(0);
            	HX_STACKFRAME(&_hx_pos_807ea0814ee6c299_97_stop)
HXDLIN(  97)		if ((fadeout <= (int)0)) {
HXLINE(  98)			this->channel->stop();
HXLINE(  99)			this->channel->removeEventListener(HX_("soundComplete",a8,30,e6,1c),this->oncomplete_dyn(),null());
HXLINE( 100)			this->free = true;
HXLINE( 101)			this->fading = (int)0;
            		}
            		else {
HXLINE( 103)			this->fading = (int)1;
HXDLIN( 103)			this->fadevolume = this->volume;
HXLINE( 104)			this->fadestarttime = ::openfl::Lib_obj::getTimer();
HXLINE( 105)			Float _hx_tmp = this->fadestarttime;
HXDLIN( 105)			this->fadeendtime = (_hx_tmp + (fadeout * (int)1000));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(HaxegonChannel_obj,stop,(void))

void HaxegonChannel_obj::updatefade(){
            	HX_STACKFRAME(&_hx_pos_807ea0814ee6c299_110_updatefade)
HXDLIN( 110)		if ((this->fading != (int)0)) {
HXLINE( 111)			Float now = ::openfl::Lib_obj::getTimer();
HXLINE( 112)			Float newvol = (this->fadeendtime - this->fadestarttime);
HXDLIN( 112)			Float newvol1 = (newvol - (now - this->fadestarttime));
HXDLIN( 112)			Float newvol2 = ((Float)newvol1 / (Float)(this->fadeendtime - this->fadestarttime));
HXLINE( 113)			Float _hx_tmp;
HXDLIN( 113)			if ((this->fading == (int)1)) {
HXLINE( 113)				_hx_tmp = (newvol2 * this->fadevolume);
            			}
            			else {
HXLINE( 113)				_hx_tmp = (((int)1 - newvol2) * this->fadevolume);
            			}
HXDLIN( 113)			this->changevolume(_hx_tmp);
HXLINE( 115)			if ((now >= this->fadeendtime)) {
HXLINE( 116)				if ((this->fading == (int)1)) {
HXLINE( 117)					this->stop(null());
            				}
            				else {
HXLINE( 119)					this->fading = (int)0;
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(HaxegonChannel_obj,updatefade,(void))


hx::ObjectPtr< HaxegonChannel_obj > HaxegonChannel_obj::__new() {
	hx::ObjectPtr< HaxegonChannel_obj > __this = new HaxegonChannel_obj();
	__this->__construct();
	return __this;
}

hx::ObjectPtr< HaxegonChannel_obj > HaxegonChannel_obj::__alloc(hx::Ctx *_hx_ctx) {
	HaxegonChannel_obj *__this = (HaxegonChannel_obj*)(hx::Ctx::alloc(_hx_ctx, sizeof(HaxegonChannel_obj), true, "haxegon.HaxegonChannel"));
	*(void **)__this = HaxegonChannel_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

HaxegonChannel_obj::HaxegonChannel_obj()
{
}

void HaxegonChannel_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HaxegonChannel);
	HX_MARK_MEMBER_NAME(_position,"_position");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(_length,"_length");
	HX_MARK_MEMBER_NAME(soundname,"soundname");
	HX_MARK_MEMBER_NAME(offsettime,"offsettime");
	HX_MARK_MEMBER_NAME(fadeintime,"fadeintime");
	HX_MARK_MEMBER_NAME(panning,"panning");
	HX_MARK_MEMBER_NAME(volume,"volume");
	HX_MARK_MEMBER_NAME(looping,"looping");
	HX_MARK_MEMBER_NAME(channel,"channel");
	HX_MARK_MEMBER_NAME(fadestarttime,"fadestarttime");
	HX_MARK_MEMBER_NAME(fadeendtime,"fadeendtime");
	HX_MARK_MEMBER_NAME(fadevolume,"fadevolume");
	HX_MARK_MEMBER_NAME(fading,"fading");
	HX_MARK_MEMBER_NAME(free,"free");
	HX_MARK_END_CLASS();
}

void HaxegonChannel_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_position,"_position");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(_length,"_length");
	HX_VISIT_MEMBER_NAME(soundname,"soundname");
	HX_VISIT_MEMBER_NAME(offsettime,"offsettime");
	HX_VISIT_MEMBER_NAME(fadeintime,"fadeintime");
	HX_VISIT_MEMBER_NAME(panning,"panning");
	HX_VISIT_MEMBER_NAME(volume,"volume");
	HX_VISIT_MEMBER_NAME(looping,"looping");
	HX_VISIT_MEMBER_NAME(channel,"channel");
	HX_VISIT_MEMBER_NAME(fadestarttime,"fadestarttime");
	HX_VISIT_MEMBER_NAME(fadeendtime,"fadeendtime");
	HX_VISIT_MEMBER_NAME(fadevolume,"fadevolume");
	HX_VISIT_MEMBER_NAME(fading,"fading");
	HX_VISIT_MEMBER_NAME(free,"free");
}

hx::Val HaxegonChannel_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"play") ) { return hx::Val( play_dyn() ); }
		if (HX_FIELD_EQ(inName,"stop") ) { return hx::Val( stop_dyn() ); }
		if (HX_FIELD_EQ(inName,"free") ) { return hx::Val( free ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"setto") ) { return hx::Val( setto_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return hx::Val( inCallProp == hx::paccAlways ? get_length() : length ); }
		if (HX_FIELD_EQ(inName,"volume") ) { return hx::Val( volume ); }
		if (HX_FIELD_EQ(inName,"fading") ) { return hx::Val( fading ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_length") ) { return hx::Val( _length ); }
		if (HX_FIELD_EQ(inName,"panning") ) { return hx::Val( panning ); }
		if (HX_FIELD_EQ(inName,"looping") ) { return hx::Val( looping ); }
		if (HX_FIELD_EQ(inName,"channel") ) { return hx::Val( channel ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { if (inCallProp == hx::paccAlways) return hx::Val( get_position() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"changepan") ) { return hx::Val( changepan_dyn() ); }
		if (HX_FIELD_EQ(inName,"_position") ) { return hx::Val( _position ); }
		if (HX_FIELD_EQ(inName,"soundname") ) { return hx::Val( soundname ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"oncomplete") ) { return hx::Val( oncomplete_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_length") ) { return hx::Val( get_length_dyn() ); }
		if (HX_FIELD_EQ(inName,"updatefade") ) { return hx::Val( updatefade_dyn() ); }
		if (HX_FIELD_EQ(inName,"offsettime") ) { return hx::Val( offsettime ); }
		if (HX_FIELD_EQ(inName,"fadeintime") ) { return hx::Val( fadeintime ); }
		if (HX_FIELD_EQ(inName,"fadevolume") ) { return hx::Val( fadevolume ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"fadeendtime") ) { return hx::Val( fadeendtime ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"changevolume") ) { return hx::Val( changevolume_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_position") ) { return hx::Val( get_position_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_position") ) { return hx::Val( set_position_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"fadestarttime") ) { return hx::Val( fadestarttime ); }
	}
	return super::__Field(inName,inCallProp);
}

hx::Val HaxegonChannel_obj::__SetField(const ::String &inName,const hx::Val &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"free") ) { free=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"volume") ) { volume=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fading") ) { fading=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_length") ) { _length=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"panning") ) { panning=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"looping") ) { looping=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"channel") ) { channel=inValue.Cast<  ::openfl::media::SoundChannel >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { if (inCallProp == hx::paccAlways) return hx::Val( set_position(inValue.Cast< Float >()) ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_position") ) { _position=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"soundname") ) { soundname=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"offsettime") ) { offsettime=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fadeintime") ) { fadeintime=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fadevolume") ) { fadevolume=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"fadeendtime") ) { fadeendtime=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"fadestarttime") ) { fadestarttime=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HaxegonChannel_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("position","\xa9","\xa0","\xfa","\xca"));
	outFields->push(HX_HCSTRING("_position","\x08","\x98","\x90","\x12"));
	outFields->push(HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"));
	outFields->push(HX_HCSTRING("_length","\x85","\xa6","\x7e","\x0d"));
	outFields->push(HX_HCSTRING("soundname","\x9a","\x12","\xf4","\x68"));
	outFields->push(HX_HCSTRING("offsettime","\x20","\x29","\x3b","\x5e"));
	outFields->push(HX_HCSTRING("fadeintime","\xee","\x78","\x5a","\xe9"));
	outFields->push(HX_HCSTRING("panning","\x11","\x49","\x1b","\x99"));
	outFields->push(HX_HCSTRING("volume","\xda","\x29","\x53","\x5f"));
	outFields->push(HX_HCSTRING("looping","\xfe","\x7c","\x7d","\x20"));
	outFields->push(HX_HCSTRING("channel","\xc3","\x00","\xd2","\xcc"));
	outFields->push(HX_HCSTRING("fadestarttime","\x73","\xd4","\x94","\x03"));
	outFields->push(HX_HCSTRING("fadeendtime","\x6c","\x8b","\x52","\x70"));
	outFields->push(HX_HCSTRING("fadevolume","\x56","\x24","\x24","\xaa"));
	outFields->push(HX_HCSTRING("fading","\xb9","\x75","\xae","\xe4"));
	outFields->push(HX_HCSTRING("free","\xac","\x9c","\xc2","\x43"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo HaxegonChannel_obj_sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(HaxegonChannel_obj,_position),HX_HCSTRING("_position","\x08","\x98","\x90","\x12")},
	{hx::fsFloat,(int)offsetof(HaxegonChannel_obj,length),HX_HCSTRING("length","\xe6","\x94","\x07","\x9f")},
	{hx::fsFloat,(int)offsetof(HaxegonChannel_obj,_length),HX_HCSTRING("_length","\x85","\xa6","\x7e","\x0d")},
	{hx::fsString,(int)offsetof(HaxegonChannel_obj,soundname),HX_HCSTRING("soundname","\x9a","\x12","\xf4","\x68")},
	{hx::fsFloat,(int)offsetof(HaxegonChannel_obj,offsettime),HX_HCSTRING("offsettime","\x20","\x29","\x3b","\x5e")},
	{hx::fsFloat,(int)offsetof(HaxegonChannel_obj,fadeintime),HX_HCSTRING("fadeintime","\xee","\x78","\x5a","\xe9")},
	{hx::fsFloat,(int)offsetof(HaxegonChannel_obj,panning),HX_HCSTRING("panning","\x11","\x49","\x1b","\x99")},
	{hx::fsFloat,(int)offsetof(HaxegonChannel_obj,volume),HX_HCSTRING("volume","\xda","\x29","\x53","\x5f")},
	{hx::fsBool,(int)offsetof(HaxegonChannel_obj,looping),HX_HCSTRING("looping","\xfe","\x7c","\x7d","\x20")},
	{hx::fsObject /*::openfl::media::SoundChannel*/ ,(int)offsetof(HaxegonChannel_obj,channel),HX_HCSTRING("channel","\xc3","\x00","\xd2","\xcc")},
	{hx::fsFloat,(int)offsetof(HaxegonChannel_obj,fadestarttime),HX_HCSTRING("fadestarttime","\x73","\xd4","\x94","\x03")},
	{hx::fsFloat,(int)offsetof(HaxegonChannel_obj,fadeendtime),HX_HCSTRING("fadeendtime","\x6c","\x8b","\x52","\x70")},
	{hx::fsFloat,(int)offsetof(HaxegonChannel_obj,fadevolume),HX_HCSTRING("fadevolume","\x56","\x24","\x24","\xaa")},
	{hx::fsInt,(int)offsetof(HaxegonChannel_obj,fading),HX_HCSTRING("fading","\xb9","\x75","\xae","\xe4")},
	{hx::fsBool,(int)offsetof(HaxegonChannel_obj,free),HX_HCSTRING("free","\xac","\x9c","\xc2","\x43")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *HaxegonChannel_obj_sStaticStorageInfo = 0;
#endif

static ::String HaxegonChannel_obj_sMemberFields[] = {
	HX_HCSTRING("setto","\x9d","\xad","\x2f","\x7a"),
	HX_HCSTRING("play","\xf4","\x2d","\x5a","\x4a"),
	HX_HCSTRING("oncomplete","\xd8","\x18","\xcd","\x83"),
	HX_HCSTRING("changevolume","\x4a","\x6f","\xec","\x11"),
	HX_HCSTRING("changepan","\xed","\x45","\x1b","\x1e"),
	HX_HCSTRING("_position","\x08","\x98","\x90","\x12"),
	HX_HCSTRING("get_position","\xb2","\x54","\x14","\x80"),
	HX_HCSTRING("set_position","\x26","\x78","\x0d","\x95"),
	HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"),
	HX_HCSTRING("_length","\x85","\xa6","\x7e","\x0d"),
	HX_HCSTRING("get_length","\xaf","\x04","\x8f","\x8f"),
	HX_HCSTRING("stop","\x02","\xf0","\x5b","\x4c"),
	HX_HCSTRING("updatefade","\x05","\x74","\x91","\x11"),
	HX_HCSTRING("soundname","\x9a","\x12","\xf4","\x68"),
	HX_HCSTRING("offsettime","\x20","\x29","\x3b","\x5e"),
	HX_HCSTRING("fadeintime","\xee","\x78","\x5a","\xe9"),
	HX_HCSTRING("panning","\x11","\x49","\x1b","\x99"),
	HX_HCSTRING("volume","\xda","\x29","\x53","\x5f"),
	HX_HCSTRING("looping","\xfe","\x7c","\x7d","\x20"),
	HX_HCSTRING("channel","\xc3","\x00","\xd2","\xcc"),
	HX_HCSTRING("fadestarttime","\x73","\xd4","\x94","\x03"),
	HX_HCSTRING("fadeendtime","\x6c","\x8b","\x52","\x70"),
	HX_HCSTRING("fadevolume","\x56","\x24","\x24","\xaa"),
	HX_HCSTRING("fading","\xb9","\x75","\xae","\xe4"),
	HX_HCSTRING("free","\xac","\x9c","\xc2","\x43"),
	::String(null()) };

static void HaxegonChannel_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HaxegonChannel_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void HaxegonChannel_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HaxegonChannel_obj::__mClass,"__mClass");
};

#endif

hx::Class HaxegonChannel_obj::__mClass;

void HaxegonChannel_obj::__register()
{
	hx::Object *dummy = new HaxegonChannel_obj;
	HaxegonChannel_obj::_hx_vtable = *(void **)dummy;
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("haxegon.HaxegonChannel","\xb1","\x67","\x89","\xf3");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = HaxegonChannel_obj_sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(HaxegonChannel_obj_sMemberFields);
	__mClass->mCanCast = hx::TCanCast< HaxegonChannel_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = HaxegonChannel_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = HaxegonChannel_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = HaxegonChannel_obj_sStaticStorageInfo;
#endif
	hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace haxegon