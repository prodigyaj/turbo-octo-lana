from math import *
t = int(raw_input())
while t:
	t-=1
	n = int(raw_input())
	x = n**2
	if sqrt(5*x+4)%1==0 or sqrt(5*x-4)%1==0:
		print "IsFibo"
	else:
		print "IsNotFibo"
