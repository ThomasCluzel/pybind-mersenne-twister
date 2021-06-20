# Mersenne Twister with pybind11

This project uses pybind11 to expose the C implementation of the Mersenne Twister PRNG described [here](http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/MT2002/emt19937ar.html) and available [here](http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/MT2002/CODES/mt19937ar.sep.tgz) to Python.

For more information on Mersenne Twister see: M. Matsumoto and T. Nishimura, "Mersenne Twister: A 623-dimensionally equidistributed uniform pseudorandom number generator", ACM Transactions on Modeling and Computer Simulation Vol. 8, No. 1, January pp.3–30 1998.

For more information on what pybind11 is: [https://github.com/pybind/pybind11](https://github.com/pybind/pybind11)

## Purpose of this project

As described in the [documentation](https://docs.python.org/3.9/library/random.html) Mersenne Twister is the PRNG used by the built-in `random` module under the hood. So, there is no need to use the Python module implemented here in another project.

This project exists only to see how easy (or hard) it would have been to make an existing C code available through Python with pybind11 compared to the official implementation ([see here](https://github.com/python/cpython/blob/main/Lib/random.py)).

--------------------------------------------------------------------------------

Thomas Cluzel - 2021
