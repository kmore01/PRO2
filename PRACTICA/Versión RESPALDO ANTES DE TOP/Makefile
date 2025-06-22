OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o Producto.o Ciudad.o Barco.o Rio.o
	g++ -o program.exe program.o Producto.o Ciudad.o Barco.o Rio.o


program.o: program.cc Producto.hh Ciudad.hh Barco.hh Rio.hh
	g++ -c program.cc $(OPCIONS)

Producto.o: Producto.cc Producto.hh
	g++ -c Producto.cc $(OPCIONS)

Ciudad.o: Ciudad.cc Ciudad.hh
	g++ -c Ciudad.cc $(OPCIONS) 

Barco.o: Barco.cc Barco.hh
	g++ -c Barco.cc $(OPCIONS) 

Rio.o: Rio.cc Rio.hh
	g++ -c Rio.cc $(OPCIONS) 

clean:
	rm -f *.o
	rm -f *.exe

tar:
	tar cfv practica.tar program.cc Producto.cc Ciudad.cc Barco.cc Rio.cc Producto.hh Ciudad.hh Barco.hh Rio.hh Makefile
