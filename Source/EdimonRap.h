#pragma once
#include "Monobind.h"
typedef std::function<void (const char*)> CharFun;
typedef std::list<string> StringList;
class EdimonRap
{
MonoMethod* createSkillListMethod;//クリーンナップのために必要
public:
    EdimonRap(void);
    void createSkillList(CharFun);
    ~EdimonRap(void);
};

