
import sys
import math
import re

with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
	m = re.split(" ",test)
	i,d = divmod(float(m[0]), 1)
	j,k = divmod(d*60, 1)
	l,n = divmod(k*60, 1)
	print str(int(i)) + '.'+ str(int(j)).zfill(2)+'\''+str(int(l)).zfill(2) +'\"'