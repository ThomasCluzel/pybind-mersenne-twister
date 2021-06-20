# Mersenne Twister with pybind11

This project uses pybind11 to expose the C implementation of the Mersenne Twister PRNG described [here](http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/MT2002/emt19937ar.html) and available [here](http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/MT2002/CODES/mt19937ar.sep.tgz) to Python.

For more information on Mersenne Twister see: M. Matsumoto and T. Nishimura, "Mersenne Twister: A 623-dimensionally equidistributed uniform pseudorandom number generator", ACM Transactions on Modeling and Computer Simulation Vol. 8, No. 1, January pp.3–30 1998.

For more information on what pybind11 is: [https://github.com/pybind/pybind11](https://github.com/pybind/pybind11)

## Purpose of this project

As described in the [documentation](https://docs.python.org/3.9/library/random.html) Mersenne Twister is the PRNG used by the built-in `random` module under the hood. So, there is no need to use the Python module implemented here in another project.

This project exists only to see how easy (or hard) it would have been to make an existing C code available through Python with pybind11 compared to the official implementation ([see here](https://github.com/python/cpython/blob/main/Lib/random.py)).


## Compilation and execution instructions

1. Configure the CMake project
    ```sh
    $ cmake -S . -B build
    # Feel free to use the build system you wish (-G)
    ```
1. Compile the project
    ```sh
    $ cmake --build build
    ```
1. Run the test script
    ```sh
    # Make sure to use the same Python version for the execution as the one used to build the module
    $ python3 test_script.py > test_script.out
    ```
1. Compare the output with the one from M. Matsumoto and T. Nishimura
    ```sh
    $ diff extern/mt/mt19937ar.out test_script.out
    $ echo $?
    # Should print 0
    ```

Tested on _Ubuntu 18.04.5_ with _gcc 7.5.0_, _Python 3.7.5_, _CMake 3.20.4_. It works!

--------------------------------------------------------------------------------

Thomas Cluzel - 2021
