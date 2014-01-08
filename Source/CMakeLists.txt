cmake_minimum_required(VERSION 2.6)

SET (CMAKE_CXX_COMPILER
#"/usr/bin/clang++"
"/usr/bin/gcc"
)
SET (CMAKE_CXX_FLAGS                "-Wall -std=c++0x")

project(Monobind)
include_directories(~/mono)
link_directories(
#/home/massa/mono/mono/metadata/.libs
#/home/massa/mono/mono/mini
/usr/local/lib/)
#link_libraries(/home/massa/mono/mono/)
#target_link_libraries(libmonoruntime.a)
#target_link_libraries(libmonoruntime-static.a)
#target_link_libraries(libmonoruntimesgen.a)
#target_link_libraries(libmonoruntimesgen-static.a)
#
#target_link_libraries(libmini.la)
#target_link_libraries(libmini-static.la)

set(CFILES BasicLoader.cpp EdimonRap.cpp Main.cpp Monobind.cpp)
set(HFILES BasicLoader.h   EdimonRap.h   PathUtil.h Monobind.h)
#foreach(f ${CFILES})
#  set()
#endforeach(f)
ADD_EXECUTABLE(Monobind ${CFILES})
target_link_libraries(Monobind libmono-2.0.so)
