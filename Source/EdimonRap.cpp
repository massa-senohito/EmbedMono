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
//�d�l�̕ω��ɏ_��ɑΉ�����ɂ̓��\�b�h�̕Ԃ�l�𗘗p������A���\�b�h�̕���p����
//�v���p�e�B�Ŏ擾�̕������ɍ��������@�Ԃ�l���ς��Ɠs�x�ăR���p�C�����Ȃ��Ƃ����Ȃ����A
//�L���X�g�Ȃǂ̃o�O�����荞�ދ��ꂪ����
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
