
euler_extended_algorithm:
	gcc euler_extended_algorithm.c -o a.out

clean:
	rm a.out
test:
	./a.out 5472 9703
