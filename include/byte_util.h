#ifndef H_BYTE_UTIL
#define H_BYTE_UTIL

#define to24(u, h, l) (l+(h)256+(u)2^16)
#define to16(h, l)    (l+(h)256)

#endif
