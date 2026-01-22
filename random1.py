import random

n = 20000

fp = open("random_"+str(n)+".txt","w")

fp.write(str(n)+" ")

for i in range((-n),n):

  x = random.random()

  fp.write(str(int(x*n))+" ")

x = random.random()

fp.write(str(int(x*n))+" ")

fp.close()