
import sys

a=[]
with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
	test=test.replace('\n','')
        a = test.split(",")
        
        a.sort()
        mayor = int(a[0])
        count=1
        for i in range(len(a)-1):
             if mayor == int(a[i+1]):
                 count = count +1 
             else :
                 if count>len(a)/2:
                    break
                 else :
                    count=1
                    mayor= int(a[i+1])
        if count>len(a)/2:
            print mayor
        else :
            print "None"
      
     