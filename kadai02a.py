#kadai02a 19d8104026j kaji kentaro 2000/9/28
x = int(input())
sum = 0
for i in range(1,x):
	if i % 3 == 0 or i % 5 == 0:
		sum += i
print(sum)

