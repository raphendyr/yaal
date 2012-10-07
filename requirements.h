#ifndef __YAAL_REQUIREMENTS_H__
#define __YAAL_REQUIREMENTS_H__ 1

// test
#ifndef __cplusplus
#  error  "This is c++ header. gnu c++ is required."
#endif

// require gnu gcc
#ifndef __GNUC__
#  error  "GNU gcc is required. If this source can be build using other tools, please submit pull request."
#endif

// check gcc is 4.6.0 and if 4.5.0 show warning
#if __GNUC__ < 5
#  if  __GNUC__ == 4 && __GNUC_MINOR__ > 4
#    if __GNUC_MINOR__ == 5
#      warning  "GNU 4.5 is not ntested. Please edit this and submit pull request, if 4.5 is ok."
#    endif
#  else
#    error  "GNU 4.6+ is required. 4.5+ might work."
#  endif
#endif

#endif
