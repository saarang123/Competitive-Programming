l = [1,4,53,2,43,34, 78]
count = 0
def beams(l, count):
    if len(l)>2:
        def largest(l):
            global greatest,index
            greatest = l[0]
            for i in range(0,len(l)):
                    if greatest < l[i]:
                        greatest = l[i]
                        index = i
        largest(l)
        
        if len(l)-index >= index:
            count+=1
            del l[index:len(l)]
            print ("count is: " + str(count))
            print (l)
            beams(l, count)
        else:
            count+=1
            del l[0:index+1]
            print ("count is: " + str(count))
            print (l)
            beams(l,count)
    elif len(l)==1 or len(l)==2:
        count+=1
        print ("count is: " + str(count) )
        print (l)
    return count
beams(l, count)

        
        
