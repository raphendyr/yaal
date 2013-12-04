#include <yaal.hh>

using namespace yaal;

PortB5 led; // D13 on arduino nano
Serial0 serial;

void setup() {
    led.mode = OUTPUT;
    serial.setup(9600, DATA_EIGHT, STOP_ONE, PARITY_DISABLED);
}

void loop() {
    // Print help
    // _T() makes string to be placed on program memory (saves ram)
    // This should be used for all static strings
    serial << _T("Serial terminal. Commands:\n"
                 "  b - begin action\n"
                 "  e - end action\n"
                 "\n"
                 "command: ");
    // Endl would call flush, but it isn't used in above code, so it's called here instead
    serial.flush();

    // read command
    char c = -1;
    serial >> c; // read byte
    serial << endl; // write newline

    switch (c) {
        case ASCII::NUL:
        case ASCII::ENQ:
            // ENQ == ENQUIRY == "Who are you?"
            break;
        case 'b':
            led = true; // turn led on (start action)
            serial << _T("Action has begun") << endl;
            break;
        case 'e':
            led = false; // turn led off (end action)
            serial << _T("Action has ended") << endl;
            break;
        default:
            serial << _T("Invalid command: ") << c << endl;
    }
}
