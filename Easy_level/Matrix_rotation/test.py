import sys
import math

t=str()
with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
        # ignore test if it is an empty line
        # 'test' represents the test case, do something with it
        t = test.split( )     
        N = int(math.sqrt(len(t)))
        
        for j in range(N):
          for i in range(N): 
             print t[N*(N-1)-i*N+j],     
        print
