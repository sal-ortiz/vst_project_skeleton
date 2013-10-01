#!/bin/bash

GPP_BIN=$( which g++ )
GCC_BIN=$( which gcc )
SH_BIN=$( which sh )

ROOT_DIR="$( pwd )"
APP_LIB_DIR="$ROOT_DIR/lib"
APP_BIN_DIR="$ROOT_DIR/bin"
VST_SDK_DIR="$APP_LIB_DIR/sdk/2.4"
#CXX_INCLUDES="-I\"$VST_SDK_DIR/pluginterfaces/vst2.x\" -I\"$VST_SDK_DIR/public.sdk/source/vst2.x\" -I\"$VST_SDK_DIR\" -I\"$VST_SDK_DIR/vstgui.sf/vstgui\" -I."
#CXX_FLAGS="$CXX_INCLUDES -DBUILDING_DLL=1 -Wall -O3 -m32"
CXX_FLAGS="-fPIC -I$VST_SDK_DIR -D__cdecl=\"\" -DBUILDING_DLL=0"

input_file=$1
output_file=${input_file%.*}.so


# ****************************************************************************
# *
# *    A flat, cross-platform-ish, implementation of a vst skeleton.
# *        * this is the linux build script.
# *
# ****************************************************************************
  if [ -z "$1" ];  then   # if no arguments are given, we print out our 'usage' instructions.
    echo
    echo "  Usage:"
    echo "    $0 main_input_file [included_file, ...] [compiler_switches]"
    exit 1
  fi


  # build our dependencies...
  $GPP_BIN -fPIC -I$VST_SDK_DIR -D__cdecl="" -c $input_file -o $input_file.o
  $GPP_BIN -fPIC -I$VST_SDK_DIR -D__cdecl="" -c $VST_SDK_DIR/public.sdk/source/vst2.x/audioeffectx.cpp -o $VST_SDK_DIR/public.sdk/source/vst2.x/audioeffectx.o
  $GPP_BIN -fPIC -I$VST_SDK_DIR -D__cdecl="" -c $VST_SDK_DIR/public.sdk/source/vst2.x/audioeffect.cpp -o $VST_SDK_DIR/public.sdk/source/vst2.x/audioeffect.o
  $GPP_BIN -fPIC -I$VST_SDK_DIR -D__cdecl="" -c $VST_SDK_DIR/public.sdk/source/vst2.x/vstplugmain.cpp -o $VST_SDK_DIR/public.sdk/source/vst2.x/vstplugmain.o

  # link up the actual bin...
  $GCC_BIN -shared -o $output_file *.o

  # clean up the workspace...
  if [ -e $APP_BIN_DIR/clean.sh ];  then $SH_BIN $APP_BIN_DIR/clean.sh; fi

  # close up shop and exit!
  exit 0
