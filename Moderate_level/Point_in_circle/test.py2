import sys
import math
import re

with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
        #t = test.split("Center: (")     
        #print t
        t = re.findall(r"[+-]? *(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?", test )
        if float(t[2]) >= math.sqrt( (float(t[0])-float(t[3]))**2 + (float(t[1])-float(t[4]))**2 ):
          print "true"
        else:
          print "false"
       
        