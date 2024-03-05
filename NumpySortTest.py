from timeit import default_timer as timer
import numpy as np


for i in range(1, 11):
    f = open(f'test{i}.inp', 'r')
    arr = f.read().split(' ')
    a = [float(val) for val in arr]

    start = timer()
    np.sort(a)
    end = timer()

    print(f'Sort time for test{i}:\t{round((end-start) * 1000)}ms')
