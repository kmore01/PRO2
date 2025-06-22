# MAKEFILE: emplearemos esta utilidad para preparar ejecutables en los que 
# intervienen varias clases, de forma que con una unica instruccion 
# se compilan o linkan los ficheros estrictamente necesarios.
#
# Si en el directorio solo hay un proyecto y un makefile, para ejecutar este
# simplemente se escribe "make"
#
# Nuestros makefile se componen de una creación de variables seguida de
# una serie de instrucciones con la estructura:
#
#           fichero1":" lista de ficheros 
#           "tabulador" instrucción de compilación o linkado	
#
#           fichero2":" lista de ficheros 
#           "tabulador" instrucción de compilación o linkado	
#        
#           etc
#
# Esto significa: para obtener el fichero1 es necesario que existan todos
# los ficheros de su lista; si no existe o es más antiguo que alguno de
# ellos, se obtiene o actualiza con su instruccion; si no existe alguno de
# los ficheros de la lista, el proceso acaba con error; lo mismo para el
# fichero2, etc
# 
# Mediante este esquema, cada uno de nuestros makefile ha de contener todas
# las instrucciones que sean necesarias para obtener los .o y .exe del
# proyecto correspondiente.
#
# Ejemplos:
#
# La siguiente instruccion define una variable de entorno local, para compilar
# con las opciones habituales: 
#
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers
#
# La siguiente instruccion significa:
# para obtener pro2_especif.exe es necesario que exista pro2_especif.o;
# si pro2_especif.exe no existe o es mas antiguo que pro2_especif.o,
# se obtiene con el g++ -o ... (el tabulador antes de g++ es necesario)
#
pro2_especif.exe: main.o Producto.o Ciudad.o Barco.o Rio.o
	g++ -o main.exe main.o Producto.o Ciudad.o Barco.o Rio.o
#
# La siguiente instruccion significa:
# para obtener pro2_especif.o es necesario que exista pro2_especif.cc;
# si pro2_especif.o no existe o es mas antiguo que pro2_especif.cc,
# se obtiene con el g++ -c ... 
#
main.o: main.cc Producto.hh Ciudad.hh Barco.hh Rio.hh
	g++ -c main.cc $(OPCIONS)

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

# Defino los archivos que quiero incluir en el archivo .tar
ARCHIVOS_TAR = main.cc Producto.cc Ciudad.cc Barco.cc Rio.cc main.hh Producto.hh Ciudad.hh Barco.hh Rio.hh Makefile

# Nombre del archivo .tar que se creará
NOMBRE_TAR = PRACTICA_PRO2.tar

tar:
	tar -cf $(NOMBRE_TAR) $(ARCHIVOS_TAR)
