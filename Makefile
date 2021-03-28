all: krill

krill: vm.o main.o
		g++ -s vm.o main.o -o krill.asm

main.o: vm/src/main.cpp
		g++ -c vm/src/main.cpp

vm.o: vm/src/vm.cpp
		g++ -c vm/src/vm.cpp

clean:
		rm -f *.o krill