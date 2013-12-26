#include "stdafx.h"

#include "MonoApplication.h"

int _tmain(int argc, _TCHAR* argv[])
{
	auto pMonoApplication = new CMonoApplication("");

	while(pMonoApplication->Run())
	{

	}

	return 0;
}