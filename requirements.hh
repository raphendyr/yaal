#ifndef __YAAL_REQUIREMENTS_H__
#define __YAAL_REQUIREMENTS_H__ 1

// This is c++ code, need c++ compiler
#  ifndef __cplusplus
#    error  "This is c++ header. gnu c++ is required."
#  else

//   require gnu gcc
#    ifndef __GNUC__
#      error  "GNU gcc is required. If this source can be build using other tools, please submit pull request."
#    else

//     check gcc is atleast 4.6.0
#      if __GNUC__ < 4 || ( __GNUC__ == 4 && __GNUC_MINOR__ < 6 )
#        error  "GNU 4.6+ is required."
#      else

//       requirements are ok
#        define __YAAL__ 1

//       common includes
#        include <stdint.h>
#        include "qualifiers.hh"

#      endif
#    endif
#  endif

#endif
