#include "stdafx.h"
#include "Monobind.h"


Monobind::Monobind(void)
{
}
//MonoType* égópÇµÇƒÇÕÇ¢ÇØÇ»Ç¢ÅH
//mono_class_inflate_generic_type (MonoType *type, MonoGenericContext *context) /* MONO_DEPRECATED */;

Monobind::~Monobind(void)
{
}

 namespace mono_security{
	 //void set_core_clr_platform_callback  (MonoCoreClrPlatformCB callback)
	 //{
		// mono_security_set_core_clr_platform_callback (MonoCoreClrPlatformCB callback);
	 //}
	 void enable_core_clr  (void)
	 {
		 //mono_security_enable_core_clr ();
	 }
 }
//typedef mono_bool (*MonoCoreClrPlatformCB) (const char *image_name);
namespace mono_get{
	MonoClass* exception_class     (void)
	{
		return mono_get_exception_class    ();
	}
	MonoClass* thread_class        (void)
	{
		return mono_get_thread_class       ();
	}
	MonoClass* array_class        (void)
	{
		return mono_get_array_class       ();
	}
	MonoClass* enum_class         (void)
	{
		return mono_get_enum_class        ();
	}
	MonoClass* string_class       (void)
	{
		return mono_get_string_class      ();
	}
	MonoClass* char_class         (void)
	{
		return mono_get_char_class        ();
	}
	MonoClass* double_class       (void)
	{
		return mono_get_double_class      ();
	}
	MonoClass* single_class       (void)
	{
		return mono_get_single_class      ();
	}
	MonoClass* uint64_class       (void)
	{
		return mono_get_uint64_class      ();
	}
	MonoClass* int64_class        (void)
	{
		return mono_get_int64_class       ();
	}
	MonoClass* uintptr_class         (void)
	{
		return mono_get_uintptr_class        ();
	}
	MonoClass* intptr_class          (void)
	{
		return mono_get_intptr_class         ();
	}
	MonoClass* uint32_class       (void)
	{
		return mono_get_uint32_class      ();
	}
	MonoClass* int32_class        (void)
	{
		return mono_get_int32_class       ();
	}
	MonoClass* uint16_class       (void)
	{
		return mono_get_uint16_class      ();
	}
	MonoClass* int16_class        (void)
	{
		return mono_get_int16_class       ();
	}
	MonoClass* sbyte_class        (void)
	{
		return mono_get_sbyte_class       ();
	}
	MonoClass* boolean_class      (void)
	{
		return mono_get_boolean_class     ();
	}
	MonoClass* void_class         (void)
	{
		return mono_get_void_class        ();
	}
	MonoClass* byte_class         (void)
	{
		return mono_get_byte_class        ();
	}
	MonoClass* object_class       (void)
	{
		return mono_get_object_class      ();
	}
	MonoImage* corlib             (void)
	{
		return mono_get_corlib            ();
	}
}
namespace mono_jit{
	//MonoMethod* info_get_method  (MonoJitInfo* ji)
	//{
	//	return mono_jit_info_get_method (MonoJitInfo* ji);
	//}
	//int info_get_code_size  (MonoJitInfo* ji)
	//{
	//	return mono_jit_info_get_code_size (MonoJitInfo* ji);
	//}
	//void* info_get_code_start  (MonoJitInfo* ji)
	//{
	//	return mono_jit_info_get_code_start (MonoJitInfo* ji);
	//}
	//MonoJitInfo* info_table_find    (MonoDomain *domain, char *addr)
	//{
	//	return mono_jit_info_table_find   (MonoDomain *domain, char *addr);
	//}
}
namespace mono_context{
	//MonoAppContext* get				    (void)
	//{
	//	return mono_context_get				   (void);
	//}
	//void set				    (MonoAppContext *new_context)
	//{
	//	mono_context_set				   (MonoAppContext *new_context);
	//}
	void init (MonoDomain *domain)
	{
		mono_context_init(domain);
	}
}
namespace mono_domain{
	mono_bool owns_vtable_slot  (MonoDomain *domain, void* vtable_slot)
	{
		return mono_domain_owns_vtable_slot (domain,  vtable_slot);
	}
	MonoReflectionAssembly* try_type_resolve  (MonoDomain *domain, char *name, MonoObject *tb)
	{
		return mono_domain_try_type_resolve (domain, name, tb);
	}
	mono_bool has_type_resolve  (MonoDomain *domain)
	{
		return mono_domain_has_type_resolve (domain);
	}
	void free            (MonoDomain *domain, mono_bool force)
	{
		mono_domain_free           (domain, force);
	}
	mono_bool finalize        (MonoDomain *domain, uint32_t timeout)
	{
		return mono_domain_finalize       (domain, timeout);
	}
	MonoAssembly* assembly_open   (MonoDomain *domain, const char *name)
	{
		return mono_domain_assembly_open  (domain, name);
	}
	void foreach         (MonoDomainFunc func, void* user_data)
	{
		mono_domain_foreach        (func, user_data);
	}
	MonoDomain* from_appdomain  (MonoAppDomain *appdomain)
	{
		return mono_domain_from_appdomain (appdomain);
	}
	mono_bool is_unloading    (MonoDomain *domain)
	{
		return mono_domain_is_unloading   (domain);
	}
	void try_unload  (MonoDomain *domain, MonoObject **exc)
	{
		mono_domain_try_unload (domain, exc);
	}
	void unload  (MonoDomain *domain)
	{
		mono_domain_unload (domain);
	}
	void set_internal    (MonoDomain *domain)
	{
		mono_domain_set_internal   (domain);
	}
	mono_bool set(MonoDomain *domain, mono_bool force)
	{
		return mono_domain_set(domain, force);
	}
	int32_t get_id(MonoDomain *domain)
	{
		return mono_domain_get_id (domain);
	}
	MonoDomain* get_by_id(int32_t domainid)
	{
		return mono_domain_get_by_id      (domainid);
	}
	MonoDomain* get (void)
	{
		return mono_domain_get            ();
	}
	MonoDomain* create_appdomain  (char *friendly_name, char *configuration_file)
	{
		return mono_domain_create_appdomain (friendly_name, configuration_file);
	}
	MonoDomain* create (void)
	{
		return mono_domain_create();
	}
}
//namespace mono_check{
//	char* corlib_version  (void)
//	{
//		return mono_check_corlib_version (void);
//	}
//}

namespace mono_stack{
    void walk_no_il    (MonoStackWalk func, void* user_data)
    {
        mono_stack_walk_no_il(func,user_data);
    }
    void walk          (MonoStackWalk func, void* user_data)
    {
        mono_stack_walk(func,user_data);
    }
}
namespace mono_method{
    MonoMethod* get_last_managed   (void)
    {
        return mono_method_get_last_managed();
    }
    mono_bool has_marshal_info  (MonoMethod *method)
    {
        return mono_method_has_marshal_info(method);
    }
    void get_marshal_info  (MonoMethod *method, MonoMarshalSpec **mspecs)
    {
        mono_method_get_marshal_info(method,mspecs);
    }
    uint32_t get_param_token  (MonoMethod *method, int idx)
    {
        return mono_method_get_param_token(method,idx);
    }
    void get_param_names  (MonoMethod *method, const char **names)
    {
        mono_method_get_param_names(method,names);
    }
    uint32_t get_index       (MonoMethod *method)
    {
        return mono_method_get_index(method);
    }
    uint32_t get_flags       (MonoMethod *method, uint32_t *iflags)
    {
        return mono_method_get_flags(method,iflags);
    }
    uint32_t get_token       (MonoMethod *method)
    {
        return mono_method_get_token(method);
    }
    MonoClass* get_class       (MonoMethod *method)
    {
        return mono_method_get_class(method);
    }
    const char* get_name        (MonoMethod *method)
    {
        return mono_method_get_name(method);
    }
    MonoMethodHeader* get_header      (MonoMethod *method)
    {
        return mono_method_get_header(method);
    }
    MonoMethodSignature* signature       (MonoMethod *method)
    {
        return mono_method_signature(method);
    }
    MonoMethodSignature* get_signature   (MonoMethod *method, MonoImage *image, uint32_t token)
    {
        return mono_method_get_signature(method,image,token);
    }
    MonoMethodSignature* get_signature_full  (MonoMethod *method, MonoImage *image, uint32_t token,
        MonoGenericContext *context)
    {
        return mono_method_get_signature_full(method,image,token,context);
    }
}
namespace mono_lookup{
    void* pinvoke_call  (MonoMethod *method, const char **exc_class, const char **exc_arg)
    {
        return mono_lookup_pinvoke_call(method,exc_class,exc_arg);
    }
    const char* icall_symbol  (MonoMethod *m)
    {
        return "";//return mono_lookup_icall_symbol(m);
    }
    void* internal_call  (MonoMethod *method)
    {
        return mono_lookup_internal_call(method);
    }
}
namespace mono_dllmap{
    void insert  (MonoImage *assembly, const char *dll, const char *func, const char *tdll, const char *tfunc)
    {
        mono_dllmap_insert(assembly,dll,func,tdll,tfunc);
    }
}
namespace mono_add{
    void internal_call      (const char *name, const void* method)
    {
        mono_add_internal_call(name,method);
    }
}
//namespace mono_load{
//    MonoImage* image             (const char *fname, MonoImageOpenStatus *status)
//    {
//        return mono_load_image(fname,status);
//    }
//}
//namespace mono_free{
//    void method            (MonoMethod *method)
//    {
//        mono_free_method(method);
//    }
//}
namespace mono_get{
    MonoMethod* method_constrained  (MonoImage *image, uint32_t token, MonoClass *constrained_class,
        MonoGenericContext *context, MonoMethod **cil_method)
    {
        return mono_get_method_constrained(image,token,constrained_class,context,cil_method);
    }
    MonoMethod* method_full         (MonoImage *image, uint32_t token, MonoClass *klass,
        MonoGenericContext *context)
    {
        return mono_get_method_full(image,token,klass,context);
    }
    MonoMethod* method              (MonoImage *image, uint32_t token, MonoClass *klass)
    {
        return mono_get_method(image,token,klass);
    }
}

namespace mono_method{
mono_bool can_access_method  (MonoMethod *method, MonoMethod *called)
{
    return mono_method_can_access_method(method,called);
}
mono_bool can_access_field  (MonoMethod *method, MonoClassField *field)
{
    return mono_method_can_access_field(method,field);
}
}
namespace mono_class{
const char* name_from_token  (MonoImage *image, uint32_t type_token)
{
    return mono_class_name_from_token(image,type_token);
}
MonoMethod* get_method_from_name  (MonoClass *klass, const char *name, int param_count)
{
    return mono_class_get_method_from_name(klass,name,param_count);
}
MonoClass* get_nested_types   (MonoClass* klass, void **iter)
{
return mono_class_get_nested_types(klass,iter);
}
MonoClass* get_interfaces     (MonoClass* klass, void **iter)
{
return mono_class_get_interfaces(klass,iter);
}
MonoEvent* get_events         (MonoClass* klass, void **iter)
{
return mono_class_get_events(klass,iter);
}
MonoProperty* get_properties     (MonoClass* klass, void **iter)
{
return mono_class_get_properties(klass,iter);
}
MonoMethod* get_methods        (MonoClass* klass, void **iter)
{
return mono_class_get_methods(klass,iter);
}
MonoClassField* get_fields         (MonoClass* klass, void **iter)
{
return mono_class_get_fields(klass,iter);
}
int num_events         (MonoClass *klass)
{
return mono_class_num_events(klass);
}
int num_properties     (MonoClass *klass)
{
return mono_class_num_properties(klass);
}
int num_methods        (MonoClass *klass)
{
return mono_class_num_methods(klass);
}
int num_fields         (MonoClass *klass)
{
return mono_class_num_fields(klass);
}
MonoType* get_byref_type     (MonoClass *klass)
{
return mono_class_get_byref_type(klass);
}
uint32_t get_type_token     (MonoClass *klass)
{
return mono_class_get_type_token(klass);
}
MonoType* get_type           (MonoClass *klass)
{
return mono_class_get_type(klass);
}
const char* get_namespace      (MonoClass *klass)
{
return mono_class_get_namespace(klass);
}
const char* get_name           (MonoClass *klass)
{
return mono_class_get_name(klass);
}
uint32_t get_flags          (MonoClass *klass)
{
return mono_class_get_flags(klass);
}
int get_rank           (MonoClass *klass)
{
return mono_class_get_rank(klass);
}
MonoClass* get_nesting_type   (MonoClass *klass)
{
return mono_class_get_nesting_type(klass);
}
MonoClass* get_parent         (MonoClass *klass)
{
return mono_class_get_parent(klass);
}
MonoType* enum_basetype     (MonoClass *klass)
{
return mono_class_enum_basetype(klass);
}
mono_bool is_enum           (MonoClass *klass)
{
return mono_class_is_enum(klass);
}
mono_bool is_valuetype       (MonoClass *klass)
{
return mono_class_is_valuetype(klass);
}
MonoClass* get_element_class  (MonoClass *klass)
{
return mono_class_get_element_class(klass);
}
MonoImage* get_image          (MonoClass *klass)
{
return mono_class_get_image(klass);
}
mono_bool is_assignable_from  (MonoClass *klass, MonoClass *oklass)
{
    return mono_class_is_assignable_from(klass,oklass);
}
mono_bool is_subclass_of  (MonoClass *klass, MonoClass *klassc, 
						   mono_bool check_interfaces)
{
    return mono_class_is_subclass_of(klass,klassc,check_interfaces);
}
MonoClass* from_mono_type   (MonoType *type)
{
return mono_class_from_mono_type(type);
}
int32_t min_align        (MonoClass *klass)
{
return mono_class_min_align(klass);
}
int32_t value_size       (MonoClass *klass, uint32_t *align)
{
    return mono_class_value_size(klass,align);
}
int32_t data_size        (MonoClass *klass)
{
return mono_class_data_size(klass);
}
int32_t array_element_size  (MonoClass *klass)
{
return mono_class_array_element_size(klass);
}
int32_t instance_size    (MonoClass *klass)
{
return mono_class_instance_size(klass);
}
uint32_t get_property_token  (MonoProperty *prop)
{
return mono_class_get_property_token(prop);
}
MonoProperty* get_property_from_name  (MonoClass *klass, const char *name)
{
return mono_class_get_property_from_name(klass,name);
}
uint32_t get_event_token  (MonoEvent *event)
{
return mono_class_get_event_token(event);
}
uint32_t get_field_token  (MonoClassField *field)
{
return mono_class_get_field_token(field);
}
MonoClassField* get_field_from_name  (MonoClass *klass, const char *name)
{
return mono_class_get_field_from_name(klass,name);
}
MonoClassField* get_field        (MonoClass *klass, uint32_t field_token)
{
    return mono_class_get_field(klass,field_token);
}
MonoMethod* inflate_generic_method  (MonoMethod *method, MonoGenericContext *context)
{
    return mono_class_inflate_generic_method(method,context);
}
//MonoClass* from_generic_parameter  (MonoGenericParam *param, MonoImage *image, mono_bool is_mvar)
//{
//return mono_class_from_generic_parameter(param);
//}
//MonoClass* from_typeref     (MonoImage *image, uint32_t type_token)
//{
//return mono_class_from_typeref(image);
//}
//MonoMethod* get_method_from_name_flags  (MonoClass *klass, const char *name, int param_count, int flags)
//{
//return mono_class_get_method_from_name_flags(klass);
//}
MonoClass* from_name_case   (MonoImage *image, const char* name_space, const char *name)
{
    return mono_class_from_name_case(image,name_space,name);
}
MonoClass* from_name        (MonoImage *image, const char* name_space, const char *name)
{
    return mono_class_from_name(image,name_space,name);
}
MonoVTable* vtable           (MonoDomain *domain, MonoClass *klass)
{
    return mono_class_vtable(domain,klass);
}
mono_bool init             (MonoClass *klass)
{
return mono_class_init(klass);
}
MonoClass* get_full         (MonoImage *image, uint32_t type_token, MonoGenericContext *context)
{
    return mono_class_get_full(image,type_token,context);
}
MonoClass* get              (MonoImage *image, uint32_t type_token)
{
    return mono_class_get(image,type_token);
}
}
namespace mono_event{
uint32_t get_flags          (MonoEvent *event)
{
return mono_event_get_flags(event);
}
MonoClass* get_parent         (MonoEvent *event)
{
return mono_event_get_parent(event);
}
MonoMethod* get_raise_method   (MonoEvent *event)
{
return mono_event_get_raise_method(event);
}
MonoMethod* get_remove_method  (MonoEvent *event)
{
return mono_event_get_remove_method(event);
}
MonoMethod* get_add_method     (MonoEvent *event)
{
return mono_event_get_add_method(event);
}
const char* get_name           (MonoEvent *event)
{
return mono_event_get_name(event);
}
}
namespace mono_property{
uint32_t get_flags       (MonoProperty *prop)
{
return mono_property_get_flags(prop);
}
MonoClass* get_parent      (MonoProperty *prop)
{
return mono_property_get_parent(prop);
}
MonoMethod* get_get_method  (MonoProperty *prop)
{
return mono_property_get_get_method(prop);
}
MonoMethod* get_set_method  (MonoProperty *prop)
{
return mono_property_get_set_method(prop);
}
const char* get_name        (MonoProperty *prop)
{
return mono_property_get_name(prop);
}
}
namespace mono_field{
const char* get_data   (MonoClassField *field)
{
return mono_field_get_data(field);
}
uint32_t get_offset   (MonoClassField *field)
{
return mono_field_get_offset(field);
}
uint32_t get_flags   (MonoClassField *field)
{
return mono_field_get_flags(field);
}
MonoClass* get_parent  (MonoClassField *field)
{
return mono_field_get_parent(field);
}
MonoType* get_type    (MonoClassField *field)
{
return mono_field_get_type(field);
}
const char* get_name    (MonoClassField *field)
{
return mono_field_get_name(field);
}
MonoClassField* from_token       (MonoImage *image, uint32_t token, MonoClass **retklass, 
                                  MonoGenericContext *context)
{
return mono_field_from_token(image,token,retklass,context);
}
}
namespace mono_type{
MonoType* get_underlying_type  (MonoType *type)
{
return mono_type_get_underlying_type(type);
}
const char* get_name          (MonoType *type)
{
return mono_type_get_name(type);
}
}
//namespace mono_ldtoken               {
//void* t (MonoImage *image, uint32_t token, MonoClass **retclass, MonoGenericContext *context)
//{
//return mono_ldtokend             (MonoImage *image, uint32_t();
//}
//}
namespace mono_array{
int32_t element_size     (MonoClass *ac)
{
return mono_array_element_size(ac);
}
MonoClass* class_get        (MonoClass *element_class, uint32_t rank)
{
return mono_array_class_get(element_class,rank);
}
}
namespace mono_ptr{
MonoClass* class_get          (MonoType *type)
{
return mono_ptr_class_get(type);
}
}
namespace mono_bounded{
MonoClass* array_class_get  (MonoClass *element_class, uint32_t rank, mono_bool bounded)
{
    return mono_bounded_array_class_get(element_class,rank,bounded);
}
}
namespace mono_get{
MonoMethod* inflated_method  (MonoMethod *method)
{
return mono_get_inflated_method(method);
}
}
