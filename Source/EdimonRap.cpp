#include "stdafx.h"
#include "EdimonRap.h"

class MonoLoaderBase{
public:
    MonoLoaderBase();
    virtual ~MonoLoaderBase()=0;
};

MonoLoaderBase::MonoLoaderBase(){
    //set mono emv
}
//仕様の変化に柔軟に対応するにはメソッドの返り値を利用するより、メソッドの副作用から
//プロパティで取得の方が割に合うかも　返り値が変わると都度再コンパイルしないといけないし、
//キャストなどのバグが入り込む恐れがある
void EdimonRap::createSkillList(CharFun fun){
    auto array=(MonoArray*)mono_runtime_invoke(createSkillListMethod,nullptr,nullptr,nullptr);
    auto length=mono_array_length(array);
    for (decltype(mono_array_length(array)) i = 0; i < length; i++)
    {
        auto item=mono_array_get(array,string,i);
        fun(item);
    }

}
 StringList& createSkillList(){
     auto temp=new StringList();
     
     return *temp;
}
EdimonRap::EdimonRap(void)
{
    //mono_
}


EdimonRap::~EdimonRap(void)
{
}
