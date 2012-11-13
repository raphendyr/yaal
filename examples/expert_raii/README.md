# RAII usage example for experts

This is little proof of concept of c++ RAII usage in AVR programming.

Consider following circuit for program

```
        LED   R1
      +--|<--###--+--(+) 5V
      |           |
      +----###----+
      |    R2
Pin --+
      |
       [-  Momentary switch, press to close
      |
     (-) 0V
```
