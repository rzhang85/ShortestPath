run :main.o util.o heap.o graph.o
	g++ -o  run main.o util.o heap.o graph.o
main.o :main.cpp util.h
	g++ -c main.cpp
util.o :util.cpp util.h
	g++ -c util.cpp
heap.o :heap.cpp heap.h
	g++ -c heap.cpp
graph.o :graph.cpp graph.h
	g++ -c graph.cpp
clean :
	rm *.o
cleanAll :
	rm *.o run
