#include "yaal/core.hh"
#include "yaal/io.hh"

using namespace yaal;

PortB1 led;
PortF0 sensor;

void setup() {
    led.mode = OUTPUT;

    sensor.mode = INPUT;
    auto adcu = sensor.analog.unit; // Analog Digital Conversion Unit
    adcu.reference = AnalogDigitalConverter::Reference::POWER;
    adcu.prescaler = AnalogDigitalConverter::Prescaler::FAST;
    adcu.enable();
}

void loop() {
    uint16_t value = sensor.analog.read();

    led = value > 512;
}
