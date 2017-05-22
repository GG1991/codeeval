import sys

with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
	a=test.split()
	count=0
	for i in range(int(a[1])):
	    b=str(bin(i+1))
	    b=b.replace("0b","")
	    if b.count("0")==int(a[0]) :
		count+=1
	print count