import sys

with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
	a=test.split(",")
	a[1]=a[1].replace("\n","")
	if a[0].count(a[1])>0:
	    print 1
	else:
	    print 0