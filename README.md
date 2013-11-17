Yet another AVR Abstraction Library
===================================

Or yet another AVR Library

We are in **experimental** state.

Associated projects:
 * [yaamake](https://github.com/raphendyr/yaamake) - Independent makefile system to ease project building and programming.

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

Run commands from following (change paths and commands to match your liking).

```sh
mkdir my_project_path
cd my_project_path
git init .
git submodule add https://github.com/raphendyr/yaal.git vendor/yaal
## if you do not want to have yaamake installed (read yaamake's README.md)
#git submodule add https://github.com/raphendyr/yaamake.git vendor/yaamake
#(cd vendor/yaamake && make NO_TEENSY=1)
#./vendor/yaamake/yaamake --init-project --make-initial --yaal=vendor/yaal
yaamake --init-project --make-initial --yaal=vendor/yaal
git commit --amend -m "Project initialization"
```

Last line is optional as yaamake creates you the initial commit. You should edit the message (the last line) to be more suitable to you.

Then start by editing `Makefile` to match your hardware and write test code into `main.cpp`.
After that run `make` to build it and `make program` to flash your chip.

If you are using teensy, remove parameter `NO_TEENSY=1` from above (building `teensy_loader_cli` requires libusb-dev or similar package).

License and using
-----------------

There is no known license in use yet. For now you are allowed to develop, test and contribute to this project.

If you would like to use this project for any commercial use, contact me and we will sort out what type of licensing we are going to use.

Also if you happen to use this project for something, please inform us via email or issue so we can get some feedback how this project worked for you.
