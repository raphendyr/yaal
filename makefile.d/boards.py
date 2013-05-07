#!/usr/bin/env python

import csv

def prereader(stream):
    for line in stream:
        line = line.strip()
        if line and line[0] != '#':
            yield ' '.join(line.split())

def reader(filename):
    with open(filename) as f:
        r = csv.reader(prereader(f), delimiter=' ')
        header = r.next()
        for row in r:
            rowd = {}
            for i, v in enumerate(row):
                if v and v != '-':
                    if i < len(header):
                        rowd[header[i]] = v
                    else:
                        rowd.setdefault('_rest_', []).append(v)
            yield rowd

if __name__ == '__main__':
    print """# THIS FILE IS GENERATED, read boards.list for orginal data
# if user has define BOARD we handle that
ifdef BOARD
#======================================
"""
    for board in reader('boards.list'):
        print
        print "ifeq ($(BOARD),{})".format(board['BOARD'])
        for k in sorted((k for k in board.keys() if k not in ('BOARD', '_rest_'))):
            print "  {} ?= {}".format(k, board[k])
        if '_rest_' in board:
            for item in board['_rest_']:
                k, v = item.split('=', 1)
                print "  {} ?= {}".format(k, v)
        print "endif"

    print '''

#======================================

# end: ifdef BOARD
endif


# If user or some ov above have defined ARDUINO_BOARD, add it for yaal to use
ifdef ARDUINO_BOARD
CPPDEFS += -DARDUINO_$(ARDUINO_BOARD)
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
	@echo "all known boards:"'''
    for board in reader('boards.list'):
        print '\t@echo "  {:<20} - {}"'.format(board['BOARD'], board.get('BOARD_NAME', ''))
