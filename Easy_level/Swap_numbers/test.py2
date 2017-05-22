import sys
import re

with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases: 
        t = re.split('(\d+)',test)
        for i in range(0,len(t)//4):
            print t[4*i+3]+t[4*i+2]+t[4*i+1], 
        print