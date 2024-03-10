include ../config.mk
exes = test_matrix_base test_matrix_iter

all : $(exes)

test_matrix_base : test_matrix_base.o

test_matrix_iter : test_matrix_iter.o

%.o : matrix.hpp

clean :
	-rm -f *.o $(exes)
