all:
	g++ -c src/calculatrice.cpp -I include/ -o build/calculatrice.o
	g++ -c src/operations.cpp -I include/ -o build/operations.o
	g++ -c src/affichageTextuel.cpp -I include/ -o build/affichageTextuel.o
	g++ build/*.o -o bin/calculatrice

run:
	./bin/calculatrice

clean:
	rm build/*
	rm bin/*