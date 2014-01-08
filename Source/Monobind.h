#pragma once
class Monobind
{
public:
    Monobind(void);
    ~Monobind(void);
};
#include "mono/metadata/appdomain.h"
namespace mono_security{
void set_core_clr_platform_callback  (MonoCoreClrPlatformCB callback)
;
void enable_core_clr  (void)
;
}



  typedef mono_bool (*MonoCoreClrPlatformCB) (const char *image_name);
namespace mono_get{
MonoClass* exception_class     (void)
;
MonoClass* thread_class        (void)
;
MonoClass* array_class        (void)
;
MonoClass* enum_class         (void)
;
MonoClass* string_class       (void)
;
MonoClass* char_class         (void)
;
MonoClass* double_class       (void)
;
MonoClass* single_class       (void)
;
MonoClass* uint64_class       (void)
;
MonoClass* int64_class        (void)
;
MonoClass* uintptr_class         (void)
;
MonoClass* intptr_class          (void)
;
MonoClass* uint32_class       (void)
;
MonoClass* int32_class        (void)
;
MonoClass* uint16_class       (void)
;
MonoClass* int16_class        (void)
;
MonoClass* sbyte_class        (void)
;
MonoClass* boolean_class      (void)
;
MonoClass* void_class         (void)
;
MonoClass* byte_class         (void)
;
MonoClass* object_class       (void)
;
MonoImage* corlib             (void)
;
}
namespace mono_jit{
MonoMethod* info_get_method  (MonoJitInfo* ji)
;
int info_get_code_size  (MonoJitInfo* ji)
;
void* info_get_code_start  (MonoJitInfo* ji)
;
MonoJitInfo* info_table_find    (MonoDomain *domain, char *addr)
;
}
namespace mono_context{
MonoAppContext* get				    (void)
;
void set				    (MonoAppContext *new_context)
;
void init  				   (MonoDomain *domain)
;
}
namespace mono_domain{
mono_bool owns_vtable_slot  (MonoDomain *domain, void* vtable_slot)
;
MonoReflectionAssembly* try_type_resolve  (MonoDomain *domain, char *name, MonoObject *tb)
;
mono_bool has_type_resolve  (MonoDomain *domain)
;
void free            (MonoDomain *domain, mono_bool force)
;
mono_bool finalize        (MonoDomain *domain, uint32_t timeout)
;
MonoAssembly* assembly_open   (MonoDomain *domain, const char *name)
;
void foreach         (MonoDomainFunc func, void* user_data)
;
MonoDomain* from_appdomain  (MonoAppDomain *appdomain)
;
mono_bool is_unloading    (MonoDomain *domain)
;
void try_unload  (MonoDomain *domain, MonoObject **exc)
;
void unload  (MonoDomain *domain)
;
void set_internal    (MonoDomain *domain)
;
mono_bool set             (MonoDomain *domain, mono_bool force)
;
int32_t get_id          (MonoDomain *domain)
;
MonoDomain* get_by_id       (int32_t domainid)
;
MonoDomain* get             (void)
;
MonoDomain* create_appdomain  (char *friendly_name, char *configuration_file)
;
MonoDomain* create          (void)
;
}
namespace mono_check{
const char* corlib_version  (void)
;
}


#include "mono/mini/jit.h"
 namespace mono_method{
	 mono_bool can_access_method  (MonoMethod *method, MonoMethod *called);
	 mono_bool can_access_field  (MonoMethod *method, MonoClassField *field);
 }
namespace mono_class{
	const char* name_from_token  (MonoImage *image, uint32_t type_token);
	MonoMethod* get_method_from_name  (MonoClass *klass, const char *name, int param_count);
	MonoClass* get_nested_types   (MonoClass* klass, void **iter);
	MonoClass* get_interfaces     (MonoClass* klass, void **iter);
	MonoEvent* get_events         (MonoClass* klass, void **iter);
	MonoProperty* get_properties     (MonoClass* klass, void **iter);
	MonoMethod* get_methods        (MonoClass* klass, void **iter);
	MonoClassField* get_fields         (MonoClass* klass, void **iter);
	int num_events         (MonoClass *klass);
	int num_properties     (MonoClass *klass);
	int num_methods        (MonoClass *klass);
	int num_fields         (MonoClass *klass);
	MonoType* get_byref_type     (MonoClass *klass);
	uint32_t get_type_token     (MonoClass *klass);
	MonoType* get_type           (MonoClass *klass);
	const char* get_namespace      (MonoClass *klass);
	const char* get_name           (MonoClass *klass);
	uint32_t get_flags          (MonoClass *klass);
	int get_rank           (MonoClass *klass);
	MonoClass* get_nesting_type   (MonoClass *klass);
	MonoClass* get_parent         (MonoClass *klass);
	MonoType* enum_basetype     (MonoClass *klass);
	mono_bool is_enum           (MonoClass *klass);
	mono_bool is_valuetype       (MonoClass *klass);
	MonoClass* get_element_class  (MonoClass *klass);
	MonoImage* get_image          (MonoClass *klass);
	mono_bool is_assignable_from  (MonoClass *klass, MonoClass *oklass);
	mono_bool is_subclass_of  (MonoClass *klass, MonoClass *klassc, 
			mono_bool check_interfaces);
	MonoClass* from_mono_type   (MonoType *type);
	int32_t min_align        (MonoClass *klass);
	int32_t value_size       (MonoClass *klass, uint32_t *align);
	int32_t data_size        (MonoClass *klass);
	int32_t array_element_size  (MonoClass *klass);
	int32_t instance_size    (MonoClass *klass);
	uint32_t get_property_token  (MonoProperty *prop);
	MonoProperty* get_property_from_name  (MonoClass *klass, const char *name);
	uint32_t get_event_token  (MonoEvent *event);
	uint32_t get_field_token  (MonoClassField *field);
	MonoClassField* get_field_from_name  (MonoClass *klass, const char *name);
	MonoClassField* get_field        (MonoClass *klass, uint32_t field_token);
	MonoMethod* inflate_generic_method  (MonoMethod *method, MonoGenericContext *context);
	MonoClass* from_generic_parameter  (MonoGenericParam *param, MonoImage *image, mono_bool is_mvar);
	MonoClass* from_typeref     (MonoImage *image, uint32_t type_token);
	MonoMethod* get_method_from_name_flags  (MonoClass *klass, const char *name, int param_count, int flags);
	MonoClass* from_name_case   (MonoImage *image, const char* name_space, const char *name);
	MonoClass* from_name        (MonoImage *image, const char* name_space, const char *name);
	MonoVTable* vtable           (MonoDomain *domain, MonoClass *klass);
	mono_bool init             (MonoClass *klass);
	MonoClass* get_full         (MonoImage *image, uint32_t type_token, MonoGenericContext *context);
	MonoClass* get              (MonoImage *image, uint32_t type_token);
}
namespace mono_event{
	uint32_t get_flags          (MonoEvent *event);
	MonoClass* get_parent         (MonoEvent *event);
	MonoMethod* get_raise_method   (MonoEvent *event);
	MonoMethod* get_remove_method  (MonoEvent *event);
	MonoMethod* get_remove_method  (MonoEvent *event);
	MonoMethod* get_add_method     (MonoEvent *event);
	const char* get_name           (MonoEvent *event);
}
namespace mono_property{
	uint32_t get_flags       (MonoProperty *prop);
	MonoClass* get_parent      (MonoProperty *prop);
	MonoMethod* get_get_method  (MonoProperty *prop);
	MonoMethod* get_set_method  (MonoProperty *prop);
	const char* get_name        (MonoProperty *prop);
}
namespace mono_field{
	const char* get_data   (MonoClassField *field);
	uint32_t get_offset   (MonoClassField *field);
	uint32_t get_flags   (MonoClassField *field);
	MonoClass* get_parent  (MonoClassField *field);
	MonoType* get_type    (MonoClassField *field);
	const char* get_name    (MonoClassField *field);
	MonoClassField* from_token       (MonoImage *image, uint32_t token, MonoClass **retklass, MonoGenericContext *context);
}
namespace mono_type{
	MonoType* get_underlying_type  (MonoType *type);
	const char* get_name          (MonoType *type);
}
//namespace mono_ldtoken               (MonoImage *image, uint32{
//		void* t  token, MonoClass **retclass, MonoGenericContext *context);
//}
namespace mono_array{
	int32_t element_size     (MonoClass *ac);
	MonoClass* class_get        (MonoClass *element_class, uint32_t rank);
}
namespace mono_ptr{
	MonoClass* class_get          (MonoType *type);
}
namespace mono_bounded{
	MonoClass* array_class_get  (MonoClass *element_class, uint32_t rank, mono_bool bounded);
}
namespace mono_get{
	MonoMethod* inflated_method  (MonoMethod *method);
}
#include "mono/metadata/loader.h"
namespace mono_stack{
    //ilのオフセットいらないならno_ilが使える、高速
    void walk_no_il    (MonoStackWalk func, void* user_data);
    void walk          (MonoStackWalk func, void* user_data);
}
namespace mono_method{
    MonoMethod* get_last_managed   (void);
    mono_bool has_marshal_info  (MonoMethod *method);
    void get_marshal_info  (MonoMethod *method, MonoMarshalSpec **mspecs);
    uint32_t get_param_token  (MonoMethod *method, int idx);
    void get_param_names  (MonoMethod *method, const char **names);
    uint32_t get_index       (MonoMethod *method);
    uint32_t get_flags       (MonoMethod *method, uint32_t *iflags);
    uint32_t get_token       (MonoMethod *method);
    MonoClass* get_class       (MonoMethod *method);
    const char* get_name        (MonoMethod *method);
    MonoMethodHeader* get_header      (MonoMethod *method);
    MonoMethodSignature* signature       (MonoMethod *method);
    MonoMethodSignature* get_signature   (MonoMethod *method, MonoImage *image, uint32_t token);
    MonoMethodSignature* get_signature_full  (MonoMethod *method, MonoImage *image, uint32_t token,
        MonoGenericContext *context);
}
namespace mono_lookup{
    void* pinvoke_call  (MonoMethod *method, const char **exc_class, const char **exc_arg);
    const char* icall_symbol  (MonoMethod *m);
    void* internal_call  (MonoMethod *method);
}
namespace mono_dllmap{
    void insert  (MonoImage *assembly, const char *dll, const char *func, const char *tdll, const char *tfunc);
}
namespace mono_add{
    void internal_call      (const char *name, const void* method);
}
//namespace mono_load{
//    MonoImage* image             (const char *fname, MonoImageOpenStatus *status);
//}
//namespace mono_free{
//    void method            (MonoMethod *method);
//}
namespace mono_get{
    MonoMethod* method_constrained  (MonoImage *image, uint32_t token, MonoClass *constrained_class,
        MonoGenericContext *context, MonoMethod **cil_method);
    MonoMethod* method_full         (MonoImage *image, uint32_t token, MonoClass *klass,
        MonoGenericContext *context);
    MonoMethod* method              (MonoImage *image, uint32_t token, MonoClass *klass);
}
