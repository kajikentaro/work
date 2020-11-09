#kadai02c 19d8104026j kaji kentaro 2000/9/28
basic_price = int(input())
child_price = int(basic_price / 2)
senior_price = int(basic_price * 0.8)
people_num = 0
price_sum = 0
while 1:
	age = int(input())
	if age == -1:
		break
	people_num += 1
	if age < 13:
		price_sum += child_price
		continue
	if age < 60:
		price_sum += basic_price
		continue
	else:
		price_sum += senior_price
if people_num > 4:
	price_sum = int(price_sum*0.9)
print(price_sum)
		
		
