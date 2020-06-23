ray: ray.cpp
	g++ -std=c++17 -c ray.cpp

barry: barry.cpp
	g++ -std=c++17 -c barry.cpp

convert: convert.cpp
	g++ -std=c++17 -c convert.cpp

steven: steven.cpp
	g++ -std=c++17 -c steven.cpp

hyejin: hyejin.cpp
	g++ -std=c++17 -c hyejin.cpp

all: ray.o barry.o convert.o steven.o hyejin.o
	g++ -o hw5 -std=c++17 main.cpp ray.o barry.o convert.o steven.o hyejin.o pugixml.cpp -lxlnt -lcurl -lstdc++fs 
run: all
	./hw5

clean:
	rm -rf *.o
	rm -rf hw5
	rm -rf trash*
	rm -rf Trash*