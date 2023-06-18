build : src/intento.cpp
	
	g++ -o bin/Lagrange.exe -Iinclude src/intento.cpp -lncurses


run : bin/Lagrange.exe
	
	./bin/Lagrange.exe

clean : /bin

	rm -f Lagrange.exe
