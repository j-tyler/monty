#!/usr/bin/python3
import sys
import re
file = open(sys.argv[1], 'r') 
l = []
for index, line in enumerate(file):
    if (re.findall(r'\s*push\s', line)):
        if not (re.findall(r'\s*push\s*\d', line)):
            print("L{}: usage: push integer".format(index))
            sys.exit(2)
        l.insert(0, int(re.findall(r'\b\d\b', line)[0]))
    elif (re.findall(r'\s*pall\s', line)):
        print('{}'.format('\n'.join([str(i) for i in l])))
    else:
        print("L{}: unknown instruction {}".format(index,
            str(re.findall(r'\b[^\W\d_]+\b', line)[0])))
        sys.exit(1)
sys.exit(0)

