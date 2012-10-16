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

