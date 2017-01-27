#!/usr/bin/python3
import sys
import re
file = open(sys.argv[1], 'r') 
l = []
for line in file:
    if (re.findall(r'\bpush\b', line)):
        l.insert(0, int(re.findall(r'\b\d\b', line)[0]))
    if (re.findall(r'\bpall\b', line)):
        print('{}'.format('\n'.join([str(i) for i in l])))
sys.exit(100)

