for i in range(50):
	n = int(input())
	if n == 0:
		break
	s = input()
	a = n//2
	if n % 2 == 0:
		a += 1
	for j in range(1,n):
		if s[j:a-j] == s[a+j:n]:
			ct = j
			j = n
	k = s+s[ct:-1]
	print(k)