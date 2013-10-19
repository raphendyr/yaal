2. Basics
=========


Requirements
------------

YAAL is coded using C++ and it relies on GCC compiler with AVR backend. It also needs GCC with support for C++11 standard. When you try to compile your project it will tell you if your compiler isn't ok for YAAL.


Makefile
--------

`Makefile` is definition for your build. This file contains information about your hardware. Most important lines define microcontrollerunit and it's speed.

```Makefile
BOARD = teensy2
MCU = atmega32u4
F_CLOCK = 16MHz
F_CPU = 8MHz

include vendor/yaal/makefile.ext
```

If you know `MCU` and `F_CPU` from previous work with AVR, you should read carefully how YAAL uses `F_CPU` differently.

`BOARD` is special variable which defines board to be used. This is only possible if YAAL knowns your board.  You should check [vendor/yaal/makefile.d/boards.list](https://github.com/raphendyr/yaal/blob/master/makefile.d/boards.list) if your board is there and use it's name as value for this variable. This variable will define `MCU`, `F_CLOCK`, arduino pin names and `PROGRAMMER` (If there is known default). You can overwrite these values in your `Makefile`.

`MCU` defines target microcontrollerunit.

`F_CLOCK` defines crystal speed in your hardware. This can be bigger than `F_CPU` as AVR's have cpu prescaler. If you want to run your mcu with full speed you should define this instead of `F_CPU`.

`F_CPU` defines the speed for the cpu. **YAAL init code will set cpu prescaler based on `F_CLOCK` and `F_CPU` values.** If only `F_CLOCK` is provided, `F_CPU` is set to same value for other avr libraries (eg. delay_ms() requires this).

After editing `Makefile` you can run command `make`. This will build your project. If you want to change value for single build, you can use syntax like `make F_CPU=1MHz`.


main.cpp
--------

This is the main codefile. It will look somthing like this after `init_project.sh`

```cpp
#include <yaal/core.hh>
#include <yaal/io.hh>

using namespace yaal;

void setup() {
}

void loop() {
}
```

First include lines will literally include `yaal/core.hh` and `yaal/io.hh` files. First one has some core stuff like function prototypes for `setup` and `loop` and other things to make program to call these functions. Second one will allow use of types like `PortB4`.

If you are using arduino board and would like to refer ports with arduino names (`D4`, `D5` and so on) you should add line `#include <yaal/arduino.hh>`.

C++ define `using namespace yaal;` is required here so you do not need to write `yaal::PortB4`. No need to know why.

Function `void setup()` is used for things to be done to get your harware up. Like setting port directions and initializing harware subsystems. This function is called even if you use `void main()` (before it ofcourse).

Function `void loop()` is used for main program. Typically in microconroller programs main program is repeated time after tiem, so is this function. This function is called inside never ending loop. Just like you want it.

If you need variables to last to second call of this function, you should use `void main()` in place of loop.

```cpp
void main() {
  // some variable prototypes for following neverending loop
  uint8_t i = 0;

  for (;;) {
    // Stuff you would have done in void loop()
    i++;
  }
}
```

If you write this function `loop` won't be called. So you can use only one.

Lets look more closely howto do something with this in [basic io](3_basic_io.md)
