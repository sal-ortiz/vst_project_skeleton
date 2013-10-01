@echo off

set ROOT_DIR=.
set VST_SDK_DIR=%ROOT_DIR%\lib\vstsdk2.4
::set VST_SDK_DIR=%ROOT_DIR%\lib\"VST3 SDK



:: ****************************************************************************
:: *
:: *    A flat, cross-platform-ish, implementation of a vst skeleton.
:: *        * this is the windows cleanup script.
:: *
:: ****************************************************************************

  :: if arguments are given, we print out our 'usage' instructions.
  if "%1"=="" goto @MainEntryPoint
    echo:
    echo  Usage:
    echo    %0

  goto @MainExitPoint


:: the fun starts here!
:@MainEntryPoint

  :: clean up our local app worskspace.
  del /f /q %ROOT_dir%\*.o
  del /f /q %ROOT_dir%\*.def
  del /f /q %ROOT_dir%\*.a

  :: clean up our sdk workspace.
  del /f /q %VST_SDK_DIR%\public.sdk\source\vst2.x\*.o



:: close up shop and exit!
:@MainExitPoint
