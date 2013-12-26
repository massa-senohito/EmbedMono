#ifndef MONO_LOADER_H
#define MONO_LOADER_H
#include <mono/mini/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-debug.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/appdomain.h>
#include <mono/metadata/object.h>
#include <mono/metadata/threads.h>
#include <mono/metadata/environment.h>
#include <mono/metadata/mono-gc.h>
#include <mono/metadata/class.h>
#include <mono/metadata/appdomain.h>
//using std::string;
//typedef 
MonoObject* allocate(bool callCtor,MonoClass* klass);
class BasicLoader
{
public:
	BasicLoader(string);
	~BasicLoader();
    MonoMethod* getMethod(string,int howmanyOverload);
	bool Run();
    void OpenNameSpace(string,string);
    void Free(void*);//mono_string_to_utf8などでポインタを使ったなら破棄しないとリークする
private:
	MonoDomain *m_pRootDomain;
	MonoImage *m_pClassLibraryImage;
    string* namsp;
	MonoClass *m_pClassLibraryManagerClass;
	MonoObject *m_pClassLibraryManager;
};

#endif //MONO_LOADER_H
