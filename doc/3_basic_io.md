3. Basic input/output
=====================

Types
-----

Normally in typed languages there is basic types like `int`, `float` and so on.
Also you might have used to Arduino's way of doing thins. `int led = 3; digitalWrite(led, HIGH)`. Well we support this to help migration, but you should use it for new code.

AVR controls pins trough ports. That means there is 8 pins in single byte register. Therefore nermal AVR C code looks like `PORTB |= 1 << PB4;`
As thats not very handy when creating libraries and C++ has classes (refered as types) (for these types we can define actions on assingment and other operators), YAAL invents types for pins.
Result is like `PortB4 led; led = HIGH;`

There is also C++ templates present in your coding. For example this makes true/false make other way around: `Reversed<PortB4> led;`.

So basically, first we define type and then make single instace of that type and use it.

```cpp
typedef Reversed<PortB4> LedPin;

LedPin led;

void loop() {
  led.toggle();
}
```

Pins
----

Most basic is to use  GPIO pins (General Purpose Input Output pins). This is the most basic feature of pin in AVR. Pins normally have lot of other functions too (PWM, USART and so on), but we start from the simple things.

We have abstracted multiple pin registers to single type (well actually few, but still). All types like `PortB4` are "ready to use" types of pins (type aliases for templates with correct parameters).

```cpp
PortB4 green_led;
PortD2 red_led;
D7 yellow_led;
```
