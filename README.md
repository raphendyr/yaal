Yet another AVR Abstraction Library
===================================

Or yet another AVR Library

We are in **experimental** state.

About
-----

Trying to make avr coding super easy. Result should be able to replace arduino library in usability.

    #include <yaal/io.hh>

    PortB3 led;

    void main() {
      led.output();
      
      for (;;) {
        led.on();
        delay_ms(1000);
        led.off();
        delay_ms(1000);
      }
    }

Those are mainly for directions, but for working examples look into *examples* directory.

Why YAAL?
---------

Why should I use YAAL instead of Arduino. Arduino is so easy to use!

Well. Because of the performance. Read more in [why_yaal.md](https://github.com/raphendyr/yaal/blob/master/why_yaal.md)


Howto start project using yaal?
-------------------------------

Run commands from following (change paths and commends to match your liking).

```sh
mkdir my_project_path
cd my_project_path
git init .
git submodule add https://github.com/raphendyr/yaal.git vendor/yaal
./vendor/yaal/init_project.sh
git commit -m "Project initialization"
```

You should now edit `Makefile` to match your project and start coding into `main.cpp`.

License and using
-----------------

There is no known license in use yet. For now you are allowed to develop, test and contribute to this project.

If you would like to use this project for any commercial use, contact me and we will sort out what type of licensing we are going to use.

Also if you happen to use this project for something, please inform us via email or issue so we can get some feedback how this project worked for you.
