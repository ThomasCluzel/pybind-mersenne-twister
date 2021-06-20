/**
 * \file pymt19937ar.cpp
 * \brief This file wraps the C implementation of Mersenne Twister to expose it to Python thanks to pybind11.
 * \author Thomas Cluzel
 * \version 1.0
 * \date June 20, 2021
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // Python lists to std::vector to raw arrays

extern "C" {
    #include <mt19937ar.h>
}

namespace py = pybind11;

PYBIND11_MODULE(pymt, m) {
    m.doc() = "Mersenne Twister PRNG";

    m.def("init_genrand", &init_genrand, "Initialize MT with an integer seed");
    m.def("init_by_array", [](std::vector<unsigned long> array){ init_by_array(array.data(), array.size()); },
        "Initialize MT with an array of intergers");

    m.def("genrand_int32", &genrand_int32, "Generate a random number on [0,0xffffffff]-interval");
    m.def("genrand_int31", &genrand_int31, "Generate a random number on [0,0x7fffffff]-interval");
    m.def("genrand_real1", &genrand_real1, "Generate a random number on [0,1]-real-interval");
    m.def("genrand_real2", &genrand_real2, "Generate a random number on [0,1)-real-interval");
    m.def("genrand_real3", &genrand_real3, "Generate a random number on (0,1)-real-interval");
    m.def("genrand_res53", &genrand_res53, "Generate a random number on [0,1) with 53-bit resolution");
}
