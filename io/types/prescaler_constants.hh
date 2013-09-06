#ifdef __INTERNAL_INCLUDE_ENUM__

#  if F_CPU < 38400000UL

#    if F_CPU >= 25600000UL
        SUPER = 0x7,
#    elif F_CPU >= 19200000UL
        FAST = 0x7,
#    elif F_CPU >= 12800000UL
        SUPER = 0x6,
        FAST = 0x7,
#    elif F_CPU >= 9600000UL
        SLOW = 0x7,
        FAST = 0x6,
#    elif F_CPU >= 6400000UL
        SLOW = 0x7,
        SUPER = 0x5,
        FAST = 0x6,
#    elif F_CPU >= 4800000UL
        SLOW = 0x6,
        FAST = 0x5,
#    elif F_CPU >= 3200000UL
        SLOW = 0x6,
        SUPER = 0x4,
        FAST = 0x5,
#    elif F_CPU >= 2400000UL
        SLOW = 0x5,
        FAST = 0x4,
#    elif F_CPU >= 1600000UL
        SLOW = 0x5,
        SUPER = 0x3,
        FAST = 0x4,
#    elif F_CPU >= 1200000UL
        SLOW = 0x4,
        FAST = 0x3,
#    elif F_CPU >= 800000UL
        SLOW = 0x4,
        SUPER = 0x2,
        FAST = 0x3,
#    elif F_CPU >= 600000UL
        SLOW = 0x3,
        FAST = 0x2,
#    elif F_CPU >= 400000UL
        SLOW = 0x3,
        SUPER = 0x1,
        FAST = 0x2,
#    elif F_CPU >= 300000UL
        SLOW = 0x2,
        FAST = 0x1,
#    elif F_CPU >= 200000UL
        SLOW = 0x2,
        SUPER = 0x0,
        FAST = 0x1,
#    elif F_CPU >= 100000UL
        SLOW = 0x1,
        FAST = 0x0,
#    elif F_CPU >= 50000UL
        SLOW = 0x0,

#    else
#      error "Too slow F_CPU for ADC module"
#    endif
#  else
#    error "Too fast F_CPU for ADC module"
#  endif

#endif

