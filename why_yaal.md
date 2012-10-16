# Why YAAL?

Here is normal arduino code. It's really readable, but it will result horribly slow code as digitalWrite is super slow

```c++
int button = 5;
int led = 6;


void setup() {
    pinMode(button, INPUT_PULLUP);
    pinMode(led, OUTPUT);
}

void loop() {
    if (digitalRead(button)) {
        digitalWrite(led, HIGH);
        delay(800);
        digitalWrite(led, LOW);
    }
    delay(800);
}
```
Here is same code using YAAL's arduino compatibility. It will results most oprimized code as it will use assembly instructions sbi, cbi for pin toglling.

This is proof of that we don't need to lose easy to use library to get optimized code!

```c++
D5 button;
D6 led;


void setup() {
    pinMode(button, INPUT_PULLUP);
    pinMode(led, OUTPUT);
}

void loop() {
    if (digitalRead(button)) {
        digitalWrite(led, HIGH);
        delay(800);
        digitalWrite(led, LOW);
    }
    delay(800);
}
```

ps. yaal doesn't have delay() yet, but it's about the same as _delay_ms()
