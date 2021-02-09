all:
	g++ -c src/Arme.cpp -I include/ -o build/arme.o
	g++ -c src/Personnage.cpp -I include/ -o build/Personnage.o
	g++ -c src/main.cpp -I include/ -o build/main.o
	g++ build/*.o -o bin/main

run:
	./bin/main

clean:
	rm build/*
	rm bin/*