import sys

a=[", yeah!",
   ", this is crazy, I tell ya.",
   ", can U believe this?",
   ", eh?",
   ", aw yea.",
   ", yo.",
   "? No way!",
   ". Awesome!"]

count = 0
count1 = 0
with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
        b =str(test)
        for i in b:
            #print('%s'%i,end='')
            if (i != "." and i != "!" and i != "?"):
                print("%s" % (i), end='')
            else:
                if (count1 == len(a)):count1 = 0

                if (count % 2) == 1:
                    print(str(a[count1]), end='')
                    count1+=1             
                else:
                    print("%s" % (i), end='')

                count+=1             
                
