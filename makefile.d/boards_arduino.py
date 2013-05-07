#!/usr/bin/env python

import sys

def prereader(stream):
    for line in stream:
        line = line.strip()
        if line and line[0] != '#':
            yield line

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print "usage: {} arduino_formated_boards.txt".format(sys.argv[0])
        sys.exit(1)

    fn = sys.argv[1]

    tree = {}

    with open(fn) as f:
        for line in prereader(f):
            path, value = line.strip().split('=', 1)
            path = path.strip()
            value = value.strip()

            cur = tree
            path_parts = path.split('.')
            path_levels = len(path_parts) - 1
            for i, p in enumerate(path_parts):
                if i < path_levels:
                    cur = cur.setdefault(p, {})
                else:
                    cur[p] = value

    boards = tree.keys()
    boards.sort()

    print  "BOARD               MCU         F_CLOCK     ARDUINO_BOARD   PROGRAMMER  BOARD_NAME"
    fmt = "{board:<19} {mcu:<11} {f_cpu:<11} {variant:<15} -           \"{name}\""

    for board in boards:
        core = tree[board].get('build', {}).get('core', '').lower()
        if core not in ('arduino', 'teensy'):
            print "# {} - skipped, invalid build.core".format(board)
            continue

        try:
            try:
                f_cpu = tree[board]['build']['f_cpu']
            except KeyError:
                f_cpu = sorted(tree[board]['menu']['speed'].items(), reverse=True, key=lambda x: int(x[0]))[0][1]['build']['f_cpu']
            try:
                variant = tree[board]['build']['variant']
            except KeyError:
                variant = core

            board_name = board.lower()
            if not board_name.startswith(core):
                board_name = core + '_' + board_name

            print fmt.format(board=board_name,
                name=tree[board].get('name', '-').lower(),
                mcu=tree[board]['build']['mcu'].lower(),
                f_cpu=f_cpu.lower().rstrip('ul'),
                variant=variant.lower(),
            )
        except KeyError as e:
            print "# {} - skipped, invalid data: {}".format(board, e)
