run: basik.o
	gcc -o run basik.o ./libbass.so
	./run

basik.o: basik.c
	gcc -c basik.c

