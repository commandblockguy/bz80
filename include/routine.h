#ifndef H_ROUTINE
#define H_ROUTINE

#include "util.h"

#define arg_list BZARG
// n is the argument number plus one, since the first list element is the routine number
// I could add a "-1" but that would slow things down
#define arg(n) list(arg_list)(n)
#define call(id, args...) {id,args}→list(BZARG):prgmBZ80

#define RoutineHeader(id) If list(arg_list)(1)=id:Then
// Need the colon here or the preprocessor puts a space in
#define RoutineFooter DelVar list(arg_list):Return:End

#endif
