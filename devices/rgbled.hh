#ifndef __YAAL_DEVICES__RGBLED__
#define __YAAL_DEVICES__RGBLED__ 1

namespace yaal {

    template<typename RedPin, typename GreenPin, typename BluePin>
    class BasicRGBLed {
    public:
        struct {
            RedPin red;
            GreenPin green;
            BluePin blue;
        } pins;

        YAAL_INLINE("BasicRGBLed::setup")
        void setup() {
            pins.red.mode = OUTPUT;
            pins.green.mode = OUTPUT;
            pins.blue.mode = OUTPUT;
        }

        YAAL_INLINE("BasicRGBLed::off")
        void off() {
            pins.red = false;
            pins.green = false;
            pins.blue = false;
        }

        YAAL_INLINE("BasicRGBLed::red")
        void red() {
            pins.red = true;
            pins.green = false;
            pins.blue = false;
        }

        YAAL_INLINE("BasicRGBLed::green")
        void green() {
            pins.red = false;
            pins.green = true;
            pins.blue = false;
        }

        YAAL_INLINE("BasicRGBLed::blue")
        void blue() {
            pins.red = false;
            pins.green = false;
            pins.blue = true;
        }

        YAAL_INLINE("BasicRGBLed::yellow")
        void yellow() {
            pins.red = true;
            pins.green = true;
            pins.blue = false;
        }

        YAAL_INLINE("BasicRGBLed::cyan")
        void cyan() {
            pins.red = false;
            pins.green = true;
            pins.blue = true;
        }

        YAAL_INLINE("BasicRGBLed::magenta")
        void magenta() {
            pins.red = true;
            pins.green = false;
            pins.blue = true;
        }

        YAAL_INLINE("BasicRGBLed::white")
        void white() {
            pins.red = true;
            pins.green = true;
            pins.blue = true;
        }
    };


    /* FIXME: This is not working correctly */
    template<typename RedPin, typename GreenPin, typename BluePin>
    class RaiiRGBLed {
        class Active {};

        template<typename ActivePin>
        class Single : public Active {
            ActivePin pin;

        public:
            YAAL_INLINE("BasicRGBLed::Single")
            Single() {
                pin = true;
            }

            YAAL_INLINE("BasicRGBLed::~Single")
            ~Single() {
                pin = false;
            }
        };

        template<typename ActivePin1, typename ActivePin2>
        class Tuple : public Active {
            ActivePin1 pin1;
            ActivePin2 pin2;

        public:
            YAAL_INLINE("BasicRGBLed::Tuple")
            Tuple() {
                pin1 = true;
                pin2 = true;
            }

            YAAL_INLINE("BasicRGBLed::~Tuple")
            ~Tuple() {
                pin1 = false;
                pin2 = false;
            }
        };

        template<typename ActivePin1, typename ActivePin2, typename ActivePin3>
        class Triple : public Active {
            ActivePin1 pin1;
            ActivePin2 pin2;
            ActivePin3 pin3;

        public:
            YAAL_INLINE("BasicRGBLed::Triple")
            Triple() {
                pin1 = true;
                pin2 = true;
                pin3 = true;
            }

            YAAL_INLINE("BasicRGBLed::~Triple")
            ~Triple() {
                pin1 = false;
                pin2 = false;
                pin3 = false;
            }
        };


        Active active;

    public:
        YAAL_INLINE("BasicRGBLed::setup")
        void setup() {
            RedPin().mode = OUTPUT;
            GreenPin().mode = OUTPUT;
            BluePin().mode = OUTPUT;
        }

        YAAL_INLINE("BasicRGBLed::off")
        void off() {
            active = Active();
        }

        YAAL_INLINE("BasicRGBLed::red")
        void red() {
            active = Single<RedPin>();
        }

        YAAL_INLINE("BasicRGBLed::yellow")
        void yellow() {
            active = Tuple<RedPin, GreenPin>();
        }

        YAAL_INLINE("BasicRGBLed::green")
        void green() {
            active = Single<GreenPin>();
        }

        YAAL_INLINE("BasicRGBLed::cyan")
        void cyan() {
            active = Tuple<GreenPin, BluePin>();
        }

        YAAL_INLINE("BasicRGBLed::blue")
        void blue() {
            active = Single<BluePin>();
        }

        YAAL_INLINE("BasicRGBLed::magenta")
        void magenta() {
            active = Tuple<BluePin, RedPin>();
        }

        YAAL_INLINE("BasicRGBLed::white")
        void white() {
            active = Triple<RedPin, GreenPin, BluePin>();
        }
    };

}

#endif
