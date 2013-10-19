3. Basic input/output
=====================

Types
-----

Normally in typed languages there is basic types like `int`, `float` and so on.
Also you might have used to Arduino's way of doing thins. `int led = 3; digitalWrite(led, HIGH)`. Well we support this to help migration, but you should use it for new code.

AVR controls pins trough ports. That means there is 8 pins in single byte sized register. Thus normal AVR c code looks like `PORTB |= 1 << PB4;`
As thats not very handy when creating libraries. C++ has classes (refered as types). For these types we can define actions on assingment and other operators. So YAAL invents types for pins.
Result is like `PortB4 led; led = HIGH;`
