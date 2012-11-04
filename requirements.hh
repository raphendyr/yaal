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

// check gcc is atleast 4.6.0
#if __GNUC__ < 4 || ( __GNUC__ == 4 && __GNUC_MINOR__ < 6 )
#  error  "GNU 4.6+ is required."
#endif

#endif
