arr =  [ 3,2,4] 
mydict = dict()
idx = -1;

target= 6;
for v in arr:
  idx += 1;
  mydict[v] = idx;
  print "inserting  " , v  
  compl = target - v
  if ( v in mydict and compl in mydict and mydict[v] != mydict[compl]):
    print mydict[v] , " " , mydict[compl] 


