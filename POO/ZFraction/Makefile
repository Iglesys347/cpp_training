all:
	g++ -c src/ZFraction.cpp -I include/ -o build/ZFraction.o
	g++ -c src/main.cpp -I include/ -o build/main.o
	g++ build/*.o -o bin/main

run:
	./bin/main

clean:
	rm build/*
	rm bin/*