import sys

a=['A',".-",'B',"-...",'C',"-.-.",'D',"-..",'E',".",'F',"..-.",'G',"--.", 
    'H',"....",'I',"..",'J',".---",'K',"-.-",'L',".-..",'M',"--",'N',"-.",
    'O',"---",'P',".--.",'Q',"--.-",'R',".-.",'S',"...",'T',"-",'U',"..-",
    'V',"...-",'W',".--",'X',"-..-",'Y',"-.--",'Z',"--..",'1',".----",
    '2',"..---",'3',"...--",'4',"....-",'5',".....",'6',"-....",'7',"--...",
    '8',"---..",'9',"----.",'0',"-----"]
with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
        test=test.replace('\n','')
        msg=test.split("  ")
        for i in range(len(msg)):
            msg1=msg[i].split(" ")
            for j in range(len(msg1)):
                 sys.stdout.write( a[a.index(msg1[j])-1] )
            sys.stdout.write(' ')    
        print 