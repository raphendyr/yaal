#ifndef __YAAL_MACRO__AVR_h__
#define __YAAL_MACRO__AVR_h__ 1

#ifdef __AVR__
#  define YAAL_INLINE_ASM(codeblock) __asm__ __volatile__ (codeblock)
#else
#  define YAAL_INLINE_ASM(codeblock) static_assert(false, "Inline assembly works only on AVR target")
#endif

#endif
