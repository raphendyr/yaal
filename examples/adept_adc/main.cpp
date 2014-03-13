#include "yaal/core.hh"
#include "yaal/io.hh"

using namespace yaal;

PortB1 led;
PortF0 sensor;

void setup() {
    led.mode = OUTPUT;

    sensor.mode = INPUT;
    auto adcu = sensor.analog.unit; // Analog Digital Conversion Unit
    // FIXME: remove need for decltype()
    adcu.reference = decltype(adcu.reference)::POWER;
    adcu.prescaler = AdcUnit0::Prescaler::FAST;
    adcu.enable();
}

void loop() {
    uint16_t value = sensor.analog.read();

    led = value > 512;
}
