#!/bin/bash

# To avoid you having to download and install Eigen for yourself, I
# have installed it in a custom module. This `module use` command
# needs to be run once per shell.
module use /work/z04/shared/rwn/modules
module load eigen/3.4.0

module load gcc/10.2.0
module load gnuplot/5.4.0

