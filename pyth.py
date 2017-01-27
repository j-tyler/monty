#!/usr/bin/python3
import sys
import re
file = open(sys.argv[1], 'r') 
l = []
index = 1
for line in file:
    if (re.findall(r'\s*push\s', line)):
        if not (re.findall(r'\s*push\s*\d', line)):
            print("L{:d}: usage: push integer".format(index))
            sys.exit(2)
        l.insert(0, int(re.findall(r'\b\d\b', line)[0]))
    elif (re.findall(r'\s*pall\s', line)):
        print('{}'.format('\n'.join([str(i) for i in l])))
    elif (re.findall(r'\s*pint\s', line)):
        if len(l) == 0:
            print("L{:d}: can't pint, stack empty".format(index))
            sys.exit(3)
        print('{:d}'.format(l[0]))
    elif (re.findall(r'\s*pop\s', line)):
        if len(l) == 0:
            print("L{:d}: can't pop an empty stack".format(index))
            sys.exit(4)
        l.pop(0)
    elif (re.findall(r'\s*swap\s', line)):
        if len(l) < 2:
            print("L{:d}: can't swap, stack too short".format(index))
            sys.exit(5)
        l[0], l[1] = l[1], l[0]
    elif (re.findall(r'\s*add\s', line)):
        if len(l) < 2:
            print("L{:d}: can't add, stack too short".format(index))
            sys.exit(6)
        l[1] += l[0]
        l.pop(0)
    else:
        print("L{}: unknown instruction {}".format(index,
              str(re.findall(r'\b[^\W\d_]+\b', line)[0])))
        sys.exit(1)
    index += 1
sys.exit(0)

