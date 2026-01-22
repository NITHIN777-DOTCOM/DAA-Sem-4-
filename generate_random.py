import random

n = 1000000    

fp = open("random_" + str(n) + ".txt", "w")
fp.write(str(n) + " ")

for i in range(1, n):
    x = random.random()
    val = int(x * n)

    if random.random() < 0.5:
        val = -val

    fp.write(str(val) + " ")

x = random.random()
val = int(x * n)
if random.random() < 0.5:
    val = -val
fp.write(str(val) + " ")

fp.close()

print("File random_" + str(n) + ".txt created")
