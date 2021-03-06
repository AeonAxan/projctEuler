#
# Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:

# Triangle	 	Tn=n(n+1)/2	 	1, 3, 6, 10, 15, ...
# Pentagonal    Pn=n(3n1)/2	 	1, 5, 12, 22, 35, ...
# Hexagonal	 	Hn=n(2n1)	 	1, 6, 15, 28, 45, ...

# It can be verified that T285 = P165 = H143 = 40755.

# Find the next triangle number that is also pentagonal and hexagonal.
#
# Performance : 4,419ms
# Answer : 1,533,776,805
#

from eulerUtils import hexagonal_n, pentagonal_n, triangular_n
def p45():
    n = 100000

    t = triangular_n(1, n)
    p = pentagonal_n(1, n)
    h = hexagonal_n(1, n)


    return set.intersection(t, p, h)

def init():
    print p45()