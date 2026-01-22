n=5000

fp = open("ascending_"+str(n)+".txt","w")

fp.write(str(n)+" ")

for i in range(1,n):

   fp.write(str(i)+" ")

fp.write(str(n))

fp.close()