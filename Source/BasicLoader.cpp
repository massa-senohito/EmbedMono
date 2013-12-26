#include "stdafx.h"
#include "BasicLoader.h"
#include "Monobind.h"
#include "PathUtil.h"
//アプリケーション的になってる部分を切り出そう
//D:\Downloads\dev\mono-master\mono\samples\embed
namespace mono_debug{
  void init (MonoDebugFormat format){
      mono_debug_init (format);
  }
}
MonoObject* allocate(bool callCtor,MonoClass* klass){
    
    //new_fastなんかもある、使うオブジェクトを予約
    auto m_pClassLibraryManager = mono_object_new(mono_domain_get(), klass);

    if(callCtor)mono_runtime_object_init(m_pClassLibraryManager);
    return m_pClassLibraryManager;
}


BasicLoader::BasicLoader(string assem)//とりあえずライブラリーを読み出す
{
    mono_set_dirs(PathUtil::GetLibDirectory().c_str(), PathUtil::GetConfigDirectory().c_str());

    // Required for mdb's to load for detailed stack traces etc.
    mono_debug::init(MONO_DEBUG_FORMAT_MONO);
    m_pRootDomain = mono_jit_init_version("MonoApplication", "v4.0.30319");
    //auto assem="ClassLibrary.dll";
       using namespace mono_domain                                                              //"FsUtil.dll"
        ;auto pMonoAssembly=assembly_open(mono_domain_get(), PathUtil::GetBinDirectory().append(assem).c_str());
    m_pClassLibraryImage = mono_assembly_get_image(pMonoAssembly);
    
    //auto namsp="Lib" ;// "ClassLibraryNamespace";
    //auto klass="Util" ;// "ClassLibraryManager";

}
void BasicLoader::OpenNameSpace(string name,string klass){
    m_pClassLibraryManagerClass= mono_class::from_name(m_pClassLibraryImage,name,klass);

}

//メソッドは取れる,
/*    mono_runtime_invoke(m,obj,params,&exc);

 * MonoMethod *method = ... // MonoMethod* of System.Object.Equals
 * MonoException *ex = NULL;
 * Equals func = mono_method_get_unmanaged_thunk (method);
 * MonoBoolean res = func (thisObj, objToCompare, &ex);例外をハンドルする時の
 * if (ex) {
 *    // handle exception
 * }
 */
MonoMethod* BasicLoader::getMethod(string n,int params){
    auto m= mono_class::get_method_from_name( m_pClassLibraryManagerClass,n,params);
    return m;
}
void Static(MonoMethod* m,void* args){
    //Staticメソッドならobjをnullで呼び出す,
  mono_runtime_invoke(m,NULL,&args,NULL);
  
  //argsにCからの値を渡して、outやrefに出す、
  //プロパティをクラスからひいておいて、get_propertyをオブジェクトに対して指定、
  //  キャストしてMonoString*にするなりして取り出す
  //帰ってきたオブジェクトは値型ならボクシングされているので、unboxしてキャストして取り出す
}


#include <functional>
BasicLoader::~BasicLoader()
{
    //アンロードとフリーがある、さんぷるではクリーンナップ使われてるのでそいつで
    //mono_domain::unload
    mono_jit_cleanup(m_pRootDomain);
}
void getMethods(MonoClass* obj,std::function<void(const char*)> f){
  void* iter;
  //void* args [2];
  //int val;
  MonoMethod* m;
  //auto klass = mono_object::get_class (obj);
  //auto domain = mono_object::get_domain (obj);
  
  /* retrieve all the methods we need */
  iter = NULL;
  while ((m = mono_class::get_methods (obj, &iter))) {
      f(mono_method::get_name (m));
  }
}
bool BasicLoader::Run()
{
    if(true)
    {
        auto ms=     mono_class::num_methods(m_pClassLibraryManagerClass);
	auto fs=     mono_class::num_fields(m_pClassLibraryManagerClass);
        getMethods(m_pClassLibraryManagerClass,
        [](const char* name){printf_s("name= %s\n",name);}
    );
    printf_s("ms=%d fs=%d\n",ms,fs);
        return false;
    }
	return true;
}

#include "mono\metadata\exception.h"
//MonoErrorはメソッドが見当たらないなどのエラー
MonoException* genericHandle(){
    //ハンドルされなかった例外をオブジェクトからとってきている？
    //mono_unhandled_exception(obj);
    
    //メソッドに例外が起こったときにハンドルするオブジェクトを取得できるユーティリティ
    //mono_get_exception_class();
    //mono_get_exception_file_not_found(mono_string_new_wrapper(""));//corlibからFileNotFoundをとってくるヘルパー
    return mono_get_exception_argument("my exc args","exc occured");
    //指定したオブジェクトのハンドルされなかった例外を表示する mono_print_unhandled_exception();
    //例外クラスのargsなどはmono_objectのAPIから取得する
}
