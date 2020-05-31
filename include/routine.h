#ifndef H_ROUTINE
#define H_ROUTINE

#include "util.h"

#define call_list list(BZARG)
#define arg_list L₂
// n is the argument number plus one, since the first list element is the routine number
// I could add a "-1" but that would slow things down
#define arg(n) arg_list(n)
#define call(id, args...) {id,args}→list(BZARG):prgmBZ80

#define RoutineHeader(id) If arg_list(1)=id:Then
// Need the colon here or the preprocessor puts a space in
#define RoutineFooter DelVar arg_list:Return:End

#endif
