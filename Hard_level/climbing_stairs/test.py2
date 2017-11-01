import sys

def climb(n):
  if(n<4):
    return n
  else:
    if(n % 2 == 0):
      return climb(n/2) * climb(n/2) + climb(n/2-1) * climb(n/2-1)
    else:
      return climb(n/2+1) * climb(n/2) + climb(n/2) * climb(n/2-1)


with open(sys.argv[1], 'r') as test_cases:
  for test in test_cases:
    print climb(int(test))
