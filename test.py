def func(errorScore,compP, othQ):
	count=0
	while True:
		count+=1
		for i in range(len(errorScore)):
			errorScore[i] = errorScore[i] - compP
			if errorScore[i]<0:
				errorScore[i]=0

			for k in range(i):
				errorScore[j] = errorScore[j] - othQ
				if errorScore[i]<0:
					errorScore[i]=0

			for j in range(i+1, len(errorScore)):
				errorScore[j] = errorScore[j] - othQ
				if errorScore[i]<0:
					errorScore[i]=0

			if sum(errorScore)==0:
				break


	return count


x = func([6,4,1], 4,1)
print(' '.join([str(i) for i in x]))