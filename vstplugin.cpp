// *****************************************************************************
// *  VST Plugin Skeletion
// *
// *    loosely based on Steinberg's VST SDK AGain example 
// *    (© 2006, Steinberg Media Technologies, All Rights Reserved).
// *
// *****************************************************************************


#include <stdio.h>

#include "./lib/config.h"
#include "./lib/again.h"


// ***** Our entry point *******************************************************
AudioEffect* createEffectInstance (audioMasterCallback audioMaster){    return new VstPlugin (audioMaster);   }



// ***** Some constructors and a desctructor ***********************************
VstPlugin::VstPlugin (audioMasterCallback audioMaster)  : AudioEffectX (audioMaster, 1, VST_PLUGIN_NUMBER_OF_PARAMETERS)  /* 1 program, 1 parameter only */ {
	setNumInputs ( VST_PLUGIN_NUMBER_OF_AUDIO_INPUTS );		// VST_PLUGIN_NUMBER_OF_AUDIO_INPUTS in config.h
	setNumOutputs ( VST_PLUGIN_NUMBER_OF_AUDIO_OUTPUTS );	// VST_PLUGIN_NUMBER_OF_AUDIO_OUTPUTS in config.h
	setUniqueID ( VST_PLUGIN_UNIQUE_ID );	                // VST_PLUGIN_UNIQUE_ID in config.h

  #ifndef VST_PLUGIN_DISABLE_REPLACING_OUTPUT   // VST_PLUGIN_DISABLE_REPLACING_OUTPUT in config.h
    canProcessReplacing (); // supports replacing output
  #endif  // #ifndef VST_PLUGIN_DISABLE_REPLACING_OUTPUT

  #ifndef VST_PLUGIN_DISABLE_DOUBLE_REPLACING   // VST_PLUGIN_DISABLE_DOUBLE_REPLACING in config.h
    canDoubleReplacing ();  // supports double precision processing
  #endif  // #ifndef VST_PLUGIN_DISABLE_DOUBLE_REPLACING

  effectParameters = new parameters;

  unsigned int index;
  for( index=0; index < VST_PLUGIN_NUMBER_OF_PARAMETERS;  index++ ){
    effectParameters->addParameter( VST_PLUGIN_PARAMETERS_BLOCK_LIST(index).name,  \
                                    VST_PLUGIN_PARAMETERS_BLOCK_LIST(index).unit,  \
                                    VST_PLUGIN_PARAMETERS_BLOCK_LIST(index).value  );
  }


	vst_strncpy( programName, VST_PLUGIN_PROGRAM_NAME, kVstMaxProgNameLen );  // default program name: VST_PLUGIN_DEFAULT_PROGRAM_NAME in config.h
} // VstPlugin::VstPlugin ( audioMasterCallback )
VstPlugin::~VstPlugin (){   /* intentionally left blank */    }


// **** Some info getters and setters ******************************************
  bool VstPlugin::getEffectName ( char* name ){   vst_strncpy (name, VST_PLUGIN_EFFECT_NAME, kVstMaxEffectNameLen); return true;    }         // VST_PLUGIN_EFFECT_NAME in config.h
  bool VstPlugin::getProductString (char* text ){   vst_strncpy (text, VST_PLUGIN_PRODUCT_STRING, kVstMaxProductStrLen);  return true;    } // VST_PLUGIN_PRODUCT_STRING in config.h
  bool VstPlugin::getVendorString (char* text ){  vst_strncpy (text, VST_PLUGIN_VENDOR_STRING, kVstMaxVendorStrLen);  return true;    }     // VST_PLUGIN_VENDOR_STRING in config.h
  VstInt32 VstPlugin::getVendorVersion(){   return VST_PLUGIN_VENDOR_VERSION;   }                                                         // VST_PLUGIN_VENDOR_VERSION in config.h

  void VstPlugin::setProgramName( char* name ){   vst_strncpy (programName, name, kVstMaxProgNameLen);    }
  void VstPlugin::getProgramName( char* name ){   vst_strncpy (name, programName, kVstMaxProgNameLen);    }


  void VstPlugin::setParameter( VstInt32 index, float value ){    effectParameters->updateParameterValue( index, value );   }


  float VstPlugin::getParameter( VstInt32 index ){    return effectParameters->getParameter( index ).value;   }

  void VstPlugin::getParameterName( VstInt32 index, char* label ){
    vst_strncpy( label, effectParameters->getParameter( index ).name, kVstMaxParamStrLen );
  }

  void VstPlugin::getParameterDisplay( VstInt32 index, char* text ){
    sprintf( text, "%f", effectParameters->getParameter( index ).value );
  }

  void VstPlugin::getParameterLabel( VstInt32 index, char* label ){
    vst_strncpy( label, effectParameters->getParameter( index ).unit, kVstMaxParamStrLen );
  }



  void VstPlugin::processReplacing( float** inputs, float** outputs, VstInt32 sampleFrames ){
    float* in1  =  inputs[0];
    float* in2  =  inputs[1];
    float* out1 = outputs[0];
    float* out2 = outputs[1];

    while (--sampleFrames >= 0){
      /* the magic happens here! */
    }
  }

  void VstPlugin::processDoubleReplacing( double** inputs, double** outputs, VstInt32 sampleFrames ){
    double* in1  =  inputs[0];
    double* in2  =  inputs[1];
    double* out1 = outputs[0];
    double* out2 = outputs[1];

    while (--sampleFrames >= 0){
      /* the magic happens here! */
    }
  }
