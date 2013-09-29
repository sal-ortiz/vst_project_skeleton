@echo off

set ROOT_DIR=.
set VST_SDK_DIR=%ROOT_DIR%\lib\sdk/2.4
set CXX_INCLUDES=-I"%VST_SDK_DIR%/pluginterfaces/vst2.x" -I"%VST_SDK_DIR%/public.sdk/source/vst2.x" -I"%VST_SDK_DIR%" -I"%VST_SDK_DIR%/vstgui.sf/vstgui" -I. 
set CXX_FLAGS=%CXX_INCLUDES% -DBUILDING_DLL=1 -mwindows -O3 -m32


set input_file=%1


:: ****************************************************************************
:: *
:: *    A flat, cross-platform-ish, implementation of a vst skeleton.
:: *        * this is the windows build script.
:: *
:: *
:: *    This script assumes the following:
:: *        * that gnu build tools are accessible in the PATH spec.
:: *
:: ****************************************************************************

  :: if no arguments are given, we print out our 'usage' instructions.
  if not "%1"=="" goto @MainEntryPoint
    echo:
    echo  Usage:
    echo    %0 main_input_file [included_file, ...] [compiler_switches]

  goto @MainExitPoint


:: the fun starts here!
:@MainEntryPoint

  g++ -c %input_file% -o %input_file%.o %CXX_FLAGS%

  :: build our dependencies...
  g++ -c %VST_SDK_DIR%/public.sdk/source/vst2.x/audioeffectx.cpp -o %VST_SDK_DIR%/public.sdk/source/vst2.x/audioeffectx.o %CXX_FLAGS%
  g++ -c %VST_SDK_DIR%/public.sdk/source/vst2.x/audioeffect.cpp -o %VST_SDK_DIR%/public.sdk/source/vst2.x/audioeffect.o %CXX_FLAGS%
  g++ -c %VST_SDK_DIR%/public.sdk/source/vst2.x/vstplugmain.cpp -o %VST_SDK_DIR%/public.sdk/source/vst2.x/vstplugmain.o %CXX_FLAGS%

  :: build the actual bin...
  g++ -shared -o %input_file%.dll %input_file%.o %VST_SDK_DIR%/public.sdk/source/vst2.x/audioeffectx.o %VST_SDK_DIR%/public.sdk/source/vst2.x/audioeffect.o %VST_SDK_DIR%/public.sdk/source/vst2.x/vstplugmain.o -Wl,--out-implib,libagain.a -Wl,--output-def,%input_file%.def



:: close up shop and exit!
:@MainExitPoint
