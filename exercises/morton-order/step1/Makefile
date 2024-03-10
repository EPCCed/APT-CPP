include ../config.mk

exes = test_matrix_base

all : $(exes)

test_matrix_base : test_matrix_base.o matrix.o

%.o : matrix.hpp

clean :
	-rm -f *.o $(exes)
