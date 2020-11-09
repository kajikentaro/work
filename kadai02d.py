#kadai02c 19d8104026j kaji kentaro 2000/9/28
days = [30,31,30,31,31]
sm = int(input())-4
sd = int(input())-1
em = int(input())-4
ed = int(input())-1
sum = 0
for i in range(sm,em+1):
	tmp = days[i]
	if i == em:
		tmp = ed
	#print(sum," ",tmp," ",sd)
	sum += tmp-sd
	sd = 0
print(sum)
	
