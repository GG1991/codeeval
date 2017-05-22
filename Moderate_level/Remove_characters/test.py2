import sys

with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
	a=test.split(",")
	a[1]=a[1].replace("\n","")
	a[1]=a[1].replace(" ","")
	b=list(a[1])
	for i in b:
	    a[0]=a[0].replace(i,"")
	print a[0]
	