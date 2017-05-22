import sys
import re

a=[]

def numeric_compare(x, y):
  return len(x)-len(y)

with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
        a.append(test.replace("\n", ''))
    num = int(a[0])
    a.sort(cmp=numeric_compare)
    for i in range(num):
       print a[len(a)-i-1]
       
        