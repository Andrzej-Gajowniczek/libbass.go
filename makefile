start: run
	@rm -f run
run: basik.o

	gcc -o run basik.o ./libbass.so
	./run

basik.o: basik.c
	@rm -f basik.o
	gcc -c basik.c
	@rm -f run

