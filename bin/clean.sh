#!/bin/bash

ROOT_DIR="$( pwd )"
APP_LIB_DIR="$ROOT_DIR/lib"
APP_BIN_DIR="$ROOT_DIR/bin"
VST_SDK_DIR="$APP_LIB_DIR/sdk/2.4"

RM_BIN=$( which rm )

# ****************************************************************************
# *
# *    A flat, cross-platform-ish, implementation of a vst skeleton.
# *        * this is the linux cleanup script.
# *
# ****************************************************************************

  if [ ! -z "$1" ];  then   # if no arguments are given, we print out our 'usage' instructions.
    echo
    echo "  Usage:"
    echo "    $0"
    exit 1
  fi

  # delete application workspace.
  $RM_BIN --force $ROOT_DIR/*.o $APP_LIB_DIR/*.o

  # delete sdk workspace.
  $RM_BIN --force $VST_SDK_DIR/public.sdk/source/vst2.x/audioeffectx.o $VST_SDK_DIR/public.sdk/source/vst2.x/audioeffect.o $VST_SDK_DIR/public.sdk/source/vst2.x/vstplugmain.o

  exit 0

