// Generated by Haxe 3.4.4
#ifndef INCLUDED_openfl__Vector_AbstractVector
#define INCLUDED_openfl__Vector_AbstractVector

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,_Vector,AbstractVector)
HX_DECLARE_CLASS2(openfl,_Vector,IVector)

namespace openfl{
namespace _Vector{


class HXCPP_CLASS_ATTRIBUTES AbstractVector_obj : public hx::Object
{
	public:
		typedef hx::Object super;
		typedef AbstractVector_obj OBJ_;
		AbstractVector_obj();

	public:
		enum { _hx_ClassId = 0x48735c57 };

		void __construct(::Dynamic data,::cpp::VirtualArray array);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="openfl._Vector.AbstractVector")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return hx::Object::operator new(inSize+extra,true,"openfl._Vector.AbstractVector"); }
		static hx::ObjectPtr< AbstractVector_obj > __new(::Dynamic data,::cpp::VirtualArray array);
		static hx::ObjectPtr< AbstractVector_obj > __alloc(hx::Ctx *_hx_ctx,::Dynamic data,::cpp::VirtualArray array);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AbstractVector_obj();

		HX_DO_RTTI_ALL;
		hx::Val __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		hx::Val __SetField(const ::String &inString,const hx::Val &inValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_HCSTRING("AbstractVector","\x65","\x4f","\x49","\x60"); }

		::Dynamic data;
		 ::Dynamic toJSON();
		::Dynamic toJSON_dyn();

};

} // end namespace openfl
} // end namespace _Vector

#endif /* INCLUDED_openfl__Vector_AbstractVector */ 