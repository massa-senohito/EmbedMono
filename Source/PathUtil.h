#ifndef __PATH_UTIL_H__
#define __PATH_UTIL_H__

#define WIN32_LEAN_AND_MEAN
#if defined(_WIN32)||defined(_WIN64)
  #include <windows.h>
#endif
#include <string>
#include <assert.h>
struct PathUtil
{
  static std::string LinuxPath;
  static std::string GetBinDirectory()
  {

#if defined(_WIN32)||defined(_WIN64)
    TCHAR path[2048];
    GetModuleFileName( NULL, path, 2048 );
#else
  std::string path=PathUtil::LinuxPath;
  assert(path.c_str()!="");
#endif

    std::string sWorkingDirectory(path);
    return sWorkingDirectory.substr
        (0, sWorkingDirectory.find_last_of("\\")).append("\\");
  }

  static std::string GetMonoDirectory()
  {
    return GetBinDirectory().append("Mono\\");
  }

  static std::string GetLibDirectory()
  {
    return GetMonoDirectory().append("lib\\");
  }

  static std::string GetConfigDirectory()
  {
    return GetMonoDirectory().append("etc\\");
  }
};

#endif //__PATH_UTIL_H__
