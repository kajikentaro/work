def myprint(a,b):
	print("f(",a,") = ",b,sep="")
def f(n):
	if n == 0:
		ans = 0
		myprint(n,ans)
		return 0
	elif n == 1:
		ans = 1
		myprint(n,ans)
		return 1
	ans = f(n-1) + f(n-2)
	myprint(n,ans)
	return ans

n = int(input())
ans = f(n-1) + f(n-2)
myprint(n,ans)
print("answer:",ans)
