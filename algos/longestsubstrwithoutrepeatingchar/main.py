import sys
seen = [ -1 for x in range(100)]

str = sys.argv[1]
print str
longest=1
curlen = 0
stidx = 0
for i in range(len(str)):
    c = str[i]
    cval = ord(c) - ord(" ")
    #print c, " ", ord(c), " ", ord(c) - ord(" ")
    if( seen[cval] == -1 ):
        curlen += 1
        seen[cval] = i
    else:
        stidx = seen[cval] + 1
        rptidx = seen[cval]
        curlen = i - rptidx
        print "rptidx ", rptidx, " stidx ",stidx, " curlen ", curlen
        if( longest < curlen ):
            longest = curlen
        seen = [ -1 for x in range(100) ]
        for k in range(rptidx, i ):
            c = str[k]
            cval = ord(c) - ord(" " )
            seen[cval] = k

    if( curlen>longest): 
        longest = curlen

print "The longest substring of nonrepeating characters in ", str , " is ", longest, " at " , str[stidx:stidx+longest]
            
