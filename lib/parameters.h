#ifndef _PARAMETERS_H_
  #define _PARAMETERS_H_

  #include <stdlib.h>

  typedef struct {
    char* name;
    char* unit;
    float value;
  } _param;  // typedef struct

  inline _param toParameterObj( char* name, char* unit, float value ){
    _param parameter_obj;
    parameter_obj.name = name;
    parameter_obj.unit = unit;
    parameter_obj.value = value;
    return parameter_obj;
  }



  class parameters {
    private:
      _param* _paramsArray;
      unsigned int _numParams;

      inline unsigned int _get_index_with_name( char* name ){
        unsigned int index;
        for( index=0; ( (index < _numParams) && (*_paramsArray[index].name != *name) ); index++);
        return ( index == _numParams ) ? 0xffff : index;  // returns 65535 if no entry was found.
      }


    public:
      // ***** some constructors and destructors *******************************
      parameters(){
        _paramsArray = NULL;
        _numParams = 0;
      } // constructor()
      ~parameters(){
        free( _paramsArray );
      } // destructor()

      // ***** some class methods **********************************************
      unsigned int getNumParameters(){    return _numParams;    }   // get the number of entries in the list.


      void addParameter( char* name, char* unit, float value ){
        _paramsArray = (_param*)realloc( (void*)_paramsArray, (sizeof(_param) * ++_numParams) );  // reallocate our list and increment our counter.

        // set our new values.
        _paramsArray[ (_numParams-1) ].name = name;
        _paramsArray[ (_numParams-1) ].unit = unit;
        _paramsArray[ (_numParams-1) ].value = value;
      }

      void updateParameterName( int entry_index, char* new_name ){    _paramsArray[entry_index].name = new_name;  }
      void updateParameterName( char* entry_name, char* new_name ){   unsigned int index = _get_index_with_name( entry_name );  _paramsArray[index].name = new_name;    }

      void updateParameterUnit( int entry_index, char* new_unit ){    _paramsArray[entry_index].name = new_unit;  }
      void updateParameterUnit( char* entry_name, char* new_unit ){   unsigned int index = _get_index_with_name( entry_name );  _paramsArray[index].name = new_unit;    }

      void updateParameterValue( int entry_index, float new_value ){    _paramsArray[entry_index].value = new_value;    }
      void updateParameterValue( char* entry_name, float new_value ){   unsigned int index = _get_index_with_name( entry_name );  _paramsArray[index].value = new_value;    }



      _param getParameter( unsigned int index ){
        if( index >= _numParams ) return (_param)*(_param*)NULL;  // no entry was found.
        return _paramsArray[index];
      }
      _param getParameter( char* name ){

        // go through our list and stop if we find an entry whose name attribute matches our method's name argument.
        unsigned int index = _get_index_with_name( name );

        if( index == 0xffff ) return (_param)*(_param*)NULL;  // no entry was found.
        return _paramsArray[index];                           // otherwise, return the entry we found.
      }

  };  // class parameters


#endif  // #ifndef _PARAMETERS_H_x