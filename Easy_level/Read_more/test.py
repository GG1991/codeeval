import sys

with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
        if len(test)<=55:
           print test