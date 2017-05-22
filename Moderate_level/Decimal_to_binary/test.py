import sys

with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
	a= str(bin(int(test)))
	a=a.replace("0b","")
	print a