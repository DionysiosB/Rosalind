import sys
from scipy.misc import comb
from math import log10

#Inputs:
n = 47
n = 2 * n

ans = 1.0;
for k in range(0, n):
    ans = ans - comb(n, k, 1) * pow(0.5, n);
    sys.stdout.write("%.15f\n" % log10(ans))
print("\n");

print(log10(comb(n, 0, 1) * pow(0.5, n)))
print(log10(48 * pow(0.5, n)))
