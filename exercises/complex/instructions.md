# Introductory C++ exercises
## Rupert Nash
## r.nash@epcc.ed.ac.uk

The files for this are on [Github](https://github.com/EPCCed/APT-CPP).

To check out the repository run:

```bash
git clone https://github.com/EPCCed/APT-CPP
cd APT-CPP/exercises/complex
```

## Task

You have been provided with a simple, *partial* implementation of a complex number class and an associated test program. Your task is to alter the complex.cpp/complex.hpp files until the tests compile and run correctly! (Please don't edit the test.cpp program!). To compile, you need a C++17 capable compiler - on Cirrus the default `gcc` module is fine - then just use `make`.

This initial program fails:

```bash
$ module load gcc
$ make
c++ --std=c++17 -I../include   -c -o complex.o complex.cpp
complex.cpp:6:24: error: out-of-line definition of 'real' does not match any declaration in 'Complex'
double const& Complex::real() {
                       ^~~~
./complex.hpp:13:10: note: member declaration does not match because it is const qualified
  double real() const;

```

You need to start tracking down the bugs and fixing them.
