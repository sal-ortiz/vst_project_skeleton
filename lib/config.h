#include "./parameters.h"


#define VST_PLUGIN_NUMBER_OF_AUDIO_OUTPUTS  2
#define VST_PLUGIN_NUMBER_OF_AUDIO_INPUTS   2
#define VST_PLUGIN_UNIQUE_ID                'm347'
#define VST_PLUGIN_PROGRAM_NAME             "meaty_burger_vst"

#define VST_PLUGIN_EFFECT_NAME      "meaty_burger"
#define VST_PLUGIN_PRODUCT_STRING   VST_PLUGIN_EFFECT_NAME
#define VST_PLUGIN_VENDOR_STRING    "ackjockeysl"
#define VST_PLUGIN_VENDOR_VERSION   1000

/* unless you know what what you're doing, leave these commented out */
//#define VST_PLUGIN_DISABLE_REPLACING_OUTPUT
//#define VST_PLUGIN_DISABLE_DOUBLE_REPLACING


#define VST_PLUGIN_PARAMETERS_BLOCK( param_name, param_unit, param_value )    toParameterObj( param_name, param_unit, param_value )
#define VST_PLUGIN_PARAMETERS_BLOCK_PARAM_NAME    0
#define VST_PLUGIN_PARAMETERS_BLOCK_PARAM_UNIT    1
#define VST_PLUGIN_PARAMETERS_BLOCK_PARAM_VALUE   2

#define VST_PLUGIN_NUMBER_OF_PARAMETERS   8


//#define VST_PLUGIN_PARAMETERS_BLOCK( param_name, param_unit, param_value )    toParameterObj( param_name, param_unit, param_value )
_param VST_PLUGIN_PARAMETERS_BLOCK_LIST( unsigned int index ){
  switch( index ){
    case 0:   return toParameterObj( "temp",    "deg C.", 0 );
    case 1:   return toParameterObj( "ketchup", "fl. oz.", 0 );
    case 2:   return toParameterObj( "mustard", "fl. oz.", 0 );
    case 3:   return toParameterObj( "mayo",    "fl. oz.", -10 );
    case 4:   return toParameterObj( "onions",  "oz.", -2 );
    case 5:   return toParameterObj( "lettuce", "oz.", 0 );
    case 6:   return toParameterObj( "tomatoe", "oz.", -4 );
    case 7:   return toParameterObj( "pickle",  "oz.", 3 );
    default:  return (_param)*(_param*)NULL;
  }
}
