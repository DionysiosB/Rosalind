import sys
from scipy.misc import comb

#Inputs:
n = 1831
m = 898

print(sum([comb(n, k, 1) for k in range(m, n + 1)]) % 1000000)
