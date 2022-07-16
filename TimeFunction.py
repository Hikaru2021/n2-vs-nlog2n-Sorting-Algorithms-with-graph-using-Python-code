import matplotlib.pyplot as pp
import numpy as np
data = np.loadtxt(fname='lab2_2.txt', delimiter=',')
inputSize = []
bubble = []
insertion = []
selection = []
merge = []
quick = []
for i in range(len(data)):
    for j in range(6):
        if j==0:
            inputSize.append(data[i][j])
        if j== 1:
            bubble.append(data[i][j])
        if j== 2:
            insertion.append(data[i][j])
        if j== 3:
            selection.append(data[i][j])
        if j== 4:
            merge.append(data[i][j])
        if j== 5:
            quick.append(data[i][j])
pp.plot(inputSize,bubble,label='Bubble Sort')
pp.plot(inputSize,insertion,label='Insertion Sort')
pp.plot(inputSize,selection,label='Selection Sort')
pp.plot(inputSize,merge,label='Merge Sort')
pp.plot(inputSize,quick,label='Quick Sort')

pp.xlabel('Size of Input')
pp.ylabel('Running Time in seconds')
pp.title('Running Time of Sorting Algo')
pp.legend()
pp.show()