#include "stdafx.h"
#include "PathUtil.h"
#include "BasicLoader.h"
#include <string>
#if defined(_WIN32)||defined(_WIN64)
#endif 
int _tmain(int argc, _TCHAR* argv[])
{
  PathUtil::LinuxPath=argv[0];  
  auto pMonoApplication = new BasicLoader((""));

  while(pMonoApplication->Run())
  {

  }

  return 0;
}
