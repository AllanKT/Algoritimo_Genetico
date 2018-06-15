import matplotlib.pyplot as plt
import numpy as np

with open('ArqGrav.txt', 'r') as arq:
	x, y = [], []

	for linha in arq:
		linha = linha.strip()
		X, Y = linha.split(',')
		x.append(int(X))
		y.append(int(Y))
	s = np.array([6*10**3 for i in range(len(x))])
	
	arq.close()

	plt.scatter(x, y, alpha=0.5, s=s, c=x)

	plt.show()