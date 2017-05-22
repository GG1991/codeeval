import sys

with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
      a=int(test)
      if a<=7:
        print "3"
      elif a<=31:
        print "3, 7"
      elif a<=127:
        print "3, 7, 31"
      elif a<= 2047:
        print "3, 7, 31, 127"
      else:
        print "3, 7, 31, 127, 2047"