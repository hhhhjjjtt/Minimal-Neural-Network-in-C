test: min_matrix.o min_nn.o test.o
	gcc min_matrix.o min_nn.o test.o -o test

min_matrix.o: min_matrix.c
	gcc -c min_matrix.c

min_nn.o: min_nn.c
	gcc -c min_nn.c

test.o: test.c
	gcc -c test.c

