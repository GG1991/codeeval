import sys
import re

with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
	print sum(test[i:].startswith("<--<<") | test[i:].startswith(">>-->") for i in range(len(test)))
	