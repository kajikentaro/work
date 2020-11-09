#kadai02e 19d8104026j kaji kentaro 2000/9/28
def get_month(x):
	if x % 100 == 0 and x % 400 != 0:
		return 28
	elif x % 4 == 0:
		return 29
	else:
		return 28
days = [31,-1,31,30,31,30,31,31,30,31,30,31]
sy = int(input())
sm = int(input())-1
sd = int(input())-1
ey = int(input())
em = int(input())-1
ed = int(input())-1
sum = 0
for j in range(sy,ey+1):
	#last loop
	if j== ey:
		for i in range(sm,em+1):
			tmp = days[i]
			if tmp == -1:
				tmp = get_month(j)
			if i == em:
				tmp = ed
			#print(sum," ",tmp," ",sd)
			sum += tmp-sd
			sd = 0
			sm = 0
	#default loop
	else:
		for i in range(sm,12):
			tmp = days[i]
			if tmp == -1:
				tmp = get_month(j)
			#print(sum," ",tmp," ",sd)
			sum += tmp-sd
			sm = 0
			sd = 0
print(sum)
