// *****************************************************************************
// *  VST Plugin Skeletion
// *
// *    loosely based on Steinberg's VST SDK AGain example 
// *    (© 2006, Steinberg Media Technologies, All Rights Reserved).
// *
// *****************************************************************************

#ifndef _VSTPLUGIN_H_
  #define _VSTPLUGIN_H_

  #include "public.sdk/source/vst2.x/audioeffectx.h"
  #include "./parameters.h"

  //-------------------------------------------------------------------------------------------------------
  class VstPlugin   :public AudioEffectX   {
    public:
  	  VstPlugin (audioMasterCallback audioMaster);
  	  ~VstPlugin ();

    	// Processing
	    virtual void processReplacing (float** inputs, float** outputs, VstInt32 sampleFrames);
  	  virtual void processDoubleReplacing (double** inputs, double** outputs, VstInt32 sampleFrames);

  	  // Program
	    virtual void setProgramName (char* name);
	    virtual void getProgramName (char* name);

  	  // Parameters
	    virtual void setParameter (VstInt32 index, float value);
	    virtual float getParameter (VstInt32 index);
  	  virtual void getParameterLabel (VstInt32 index, char* label);
	    virtual void getParameterDisplay (VstInt32 index, char* text);
	    virtual void getParameterName (VstInt32 index, char* text);

  	  virtual bool getEffectName (char* name);
	    virtual bool getVendorString (char* text);
	    virtual bool getProductString (char* text);
  	  virtual VstInt32 getVendorVersion ();

    protected:
      parameters* effectParameters;   // an object to help us handle an effect's parameters.
	    char programName[kVstMaxProgNameLen + 1];

  };  // class VstPlugin

#endif  // #ifndef _VSTPLUGIN_H_
