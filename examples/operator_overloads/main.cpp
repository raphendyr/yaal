#include "yaal/io.hh"
#include <util/delay.h>

using namespace yaal;

PortB ledMatrixRow;
PortB1 led;

int main(void) {

    ledMatrixRow.output();
    ledMatrixRow = 0xff;

    //led.output();

    while (1) {
        //led = true;
        //_delay_ms(800);
        //led = false;
        //_delay_ms(800);
    }

}
