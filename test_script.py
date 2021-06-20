"""
Simple script to replicate extern/mt/mtTest.c and generate the same output file.
"""
import os, sys
sys.path.append(os.path.join(os.getcwd(), "build"))

import pymt

pymt.init_by_array([0x123, 0x234, 0x345, 0x456])

print("1000 outputs of genrand_int32()")
for i in range(1000):
    print("%10lu " % pymt.genrand_int32(), end="")
    if i%5 == 4:
        print()

print("\n1000 outputs of genrand_real2()")
for i in range(1000):
    print("%10.8f " % pymt.genrand_real2(), end="")
    if (i%5 == 4):
        print()
