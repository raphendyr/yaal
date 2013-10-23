# THIS FILE IS GENERATED, read boards.list for orginal data
# if user has define BOARD we handle that
ifdef BOARD
#======================================


ifeq ($(BOARD),teensy1)
  ARDUINO_BOARD ?= teensy
  BOARD_NAME ?= teensy 1.0
  F_CLOCK ?= 16000000
  MCU ?= at90usb162
  PROGRAMMER ?= teensy
endif

ifeq ($(BOARD),teensy2)
  ARDUINO_BOARD ?= teensy
  BOARD_NAME ?= teensy 2.0
  F_CLOCK ?= 16000000
  MCU ?= atmega32u4
  PROGRAMMER ?= teensy
endif

ifeq ($(BOARD),teensy++1)
  ARDUINO_BOARD ?= teensy
  BOARD_NAME ?= teensy++ 1.0
  F_CLOCK ?= 16000000
  MCU ?= at90usb646
  PROGRAMMER ?= teensy
endif

ifeq ($(BOARD),teensy++2)
  ARDUINO_BOARD ?= teensy
  BOARD_NAME ?= teensy++ 2.0
  F_CLOCK ?= 16000000
  MCU ?= at90usb1286
  PROGRAMMER ?= teensy
endif

ifeq ($(BOARD),arduino_lilypad328)
  ARDUINO_BOARD ?= standard
  BOARD_NAME ?= lilypad arduino w/ atmega328
  F_CLOCK ?= 8000000
  MCU ?= atmega328p
endif

ifeq ($(BOARD),arduino_lilypad)
  ARDUINO_BOARD ?= standard
  BOARD_NAME ?= lilypad arduino w/ atmega168
  F_CLOCK ?= 8000000
  MCU ?= atmega168
endif

ifeq ($(BOARD),arduino_uno)
  ARDUINO_BOARD ?= standard
  BOARD_NAME ?= arduino uno
  F_CLOCK ?= 16000000
  MCU ?= atmega328p
endif

ifeq ($(BOARD),arduino_pro5v328)
  ARDUINO_BOARD ?= standard
  BOARD_NAME ?= arduino pro or pro mini (5v, 16 mhz) w/ atmega328
  F_CLOCK ?= 16000000
  MCU ?= atmega328p
endif

ifeq ($(BOARD),arduino_pro5v)
  ARDUINO_BOARD ?= standard
  BOARD_NAME ?= arduino pro or pro mini (5v, 16 mhz) w/ atmega168
  F_CLOCK ?= 16000000
  MCU ?= atmega168
endif

ifeq ($(BOARD),arduino_pro328)
  ARDUINO_BOARD ?= standard
  BOARD_NAME ?= arduino pro or pro mini (3.3v, 8 mhz) w/ atmega328
  F_CLOCK ?= 8000000
  MCU ?= atmega328p
endif

ifeq ($(BOARD),arduino_pro)
  ARDUINO_BOARD ?= standard
  BOARD_NAME ?= arduino pro or pro mini (3.3v, 8 mhz) w/ atmega168
  F_CLOCK ?= 8000000
  MCU ?= atmega168
endif

ifeq ($(BOARD),arduino_atmega8)
  ARDUINO_BOARD ?= standard
  BOARD_NAME ?= arduino ng or older w/ atmega8
  F_CLOCK ?= 16000000
  MCU ?= atmega8
endif

ifeq ($(BOARD),arduino_atmega168)
  ARDUINO_BOARD ?= standard
  BOARD_NAME ?= arduino ng or older w/ atmega168
  F_CLOCK ?= 16000000
  MCU ?= atmega168
endif

ifeq ($(BOARD),arduino_ethernet)
  ARDUINO_BOARD ?= standard
  BOARD_NAME ?= arduino ethernet
  F_CLOCK ?= 16000000
  MCU ?= atmega328p
endif

ifeq ($(BOARD),arduino_atmega328)
  ARDUINO_BOARD ?= standard
  BOARD_NAME ?= arduino duemilanove w/ atmega328
  F_CLOCK ?= 16000000
  MCU ?= atmega328p
endif

ifeq ($(BOARD),arduino_diecimila)
  ARDUINO_BOARD ?= standard
  BOARD_NAME ?= arduino diecimila or duemilanove w/ atmega168
  F_CLOCK ?= 16000000
  MCU ?= atmega168
endif

ifeq ($(BOARD),arduino_micro)
  ARDUINO_BOARD ?= micro
  BOARD_NAME ?= arduino micro
  F_CLOCK ?= 16000000
  MCU ?= atmega32u4
endif

ifeq ($(BOARD),arduino_mega)
  ARDUINO_BOARD ?= mega
  BOARD_NAME ?= arduino mega (atmega1280)
  F_CLOCK ?= 16000000
  MCU ?= atmega1280
endif

ifeq ($(BOARD),arduino_mega2560)
  ARDUINO_BOARD ?= mega
  BOARD_NAME ?= arduino mega 2560 or mega adk
  F_CLOCK ?= 16000000
  MCU ?= atmega2560
endif

ifeq ($(BOARD),arduino_lilypadusb)
  ARDUINO_BOARD ?= leonardo
  BOARD_NAME ?= lilypad arduino usb
  F_CLOCK ?= 8000000
  MCU ?= atmega32u4
endif

ifeq ($(BOARD),arduino_leonardo)
  ARDUINO_BOARD ?= leonardo
  BOARD_NAME ?= arduino leonardo
  F_CLOCK ?= 16000000
  MCU ?= atmega32u4
endif

ifeq ($(BOARD),arduino_esplora)
  ARDUINO_BOARD ?= leonardo
  BOARD_NAME ?= arduino esplora
  F_CLOCK ?= 16000000
  MCU ?= atmega32u4
endif

ifeq ($(BOARD),arduino_nano328)
  ARDUINO_BOARD ?= eightanaloginputs
  BOARD_NAME ?= arduino nano w/ atmega328
  F_CLOCK ?= 16000000
  MCU ?= atmega328p
endif

ifeq ($(BOARD),arduino_nano)
  ARDUINO_BOARD ?= eightanaloginputs
  BOARD_NAME ?= arduino nano w/ atmega168
  F_CLOCK ?= 16000000
  MCU ?= atmega168
endif

ifeq ($(BOARD),arduino_mini328)
  ARDUINO_BOARD ?= eightanaloginputs
  BOARD_NAME ?= arduino mini w/ atmega328
  F_CLOCK ?= 16000000
  MCU ?= atmega328p
endif

ifeq ($(BOARD),arduino_mini)
  ARDUINO_BOARD ?= eightanaloginputs
  BOARD_NAME ?= arduino mini w/ atmega168
  F_CLOCK ?= 16000000
  MCU ?= atmega168
endif

ifeq ($(BOARD),arduino_fio)
  ARDUINO_BOARD ?= eightanaloginputs
  BOARD_NAME ?= arduino fio
  F_CLOCK ?= 8000000
  MCU ?= atmega328p
endif

ifeq ($(BOARD),arduino_bt328)
  ARDUINO_BOARD ?= eightanaloginputs
  BOARD_NAME ?= arduino bt w/ atmega328
  F_CLOCK ?= 16000000
  MCU ?= atmega328p
endif

ifeq ($(BOARD),arduino_bt)
  ARDUINO_BOARD ?= eightanaloginputs
  BOARD_NAME ?= arduino bt w/ atmega168
  F_CLOCK ?= 16000000
  MCU ?= atmega168
endif

ifeq ($(BOARD),avr-mt128)
  BOARD_NAME ?= Olimex's AVR-MT128 development board
  F_CLOCK ?= 16000000
  MCU ?= atmega128
endif


#======================================

# end: ifdef BOARD
endif


# If user or some ov above have defined ARDUINO_BOARD, add it for yaal to use
ifdef ARDUINO_BOARD
DEFS += -DARDUINO_$(ARDUINO_BOARD)
endif


.PHONY: info
info:
ifdef BOARD
	@echo "BOARD: $(BOARD)"
endif
ifdef BOARD_NAME
	@echo "BOARD_NAME: $(BOARD_NAME)"
endif
	@echo "MCU: $(MCU)"
	@echo "F_CPU: $(F_CPU)"


.PHONY: boards_list
boards_list:
	@echo "To use board, add 'BOARD = board_name' in Makefile"
	@echo
	@echo "all known boards:"
	@echo "  teensy1              - teensy 1.0"
	@echo "  teensy2              - teensy 2.0"
	@echo "  teensy++1            - teensy++ 1.0"
	@echo "  teensy++2            - teensy++ 2.0"
	@echo "  arduino_lilypad328   - lilypad arduino w/ atmega328"
	@echo "  arduino_lilypad      - lilypad arduino w/ atmega168"
	@echo "  arduino_uno          - arduino uno"
	@echo "  arduino_pro5v328     - arduino pro or pro mini (5v, 16 mhz) w/ atmega328"
	@echo "  arduino_pro5v        - arduino pro or pro mini (5v, 16 mhz) w/ atmega168"
	@echo "  arduino_pro328       - arduino pro or pro mini (3.3v, 8 mhz) w/ atmega328"
	@echo "  arduino_pro          - arduino pro or pro mini (3.3v, 8 mhz) w/ atmega168"
	@echo "  arduino_atmega8      - arduino ng or older w/ atmega8"
	@echo "  arduino_atmega168    - arduino ng or older w/ atmega168"
	@echo "  arduino_ethernet     - arduino ethernet"
	@echo "  arduino_atmega328    - arduino duemilanove w/ atmega328"
	@echo "  arduino_diecimila    - arduino diecimila or duemilanove w/ atmega168"
	@echo "  arduino_micro        - arduino micro"
	@echo "  arduino_mega         - arduino mega (atmega1280)"
	@echo "  arduino_mega2560     - arduino mega 2560 or mega adk"
	@echo "  arduino_lilypadusb   - lilypad arduino usb"
	@echo "  arduino_leonardo     - arduino leonardo"
	@echo "  arduino_esplora      - arduino esplora"
	@echo "  arduino_nano328      - arduino nano w/ atmega328"
	@echo "  arduino_nano         - arduino nano w/ atmega168"
	@echo "  arduino_mini328      - arduino mini w/ atmega328"
	@echo "  arduino_mini         - arduino mini w/ atmega168"
	@echo "  arduino_fio          - arduino fio"
	@echo "  arduino_bt328        - arduino bt w/ atmega328"
	@echo "  arduino_bt           - arduino bt w/ atmega168"
	@echo "  avr-mt128            - Olimex's AVR-MT128 development board"
