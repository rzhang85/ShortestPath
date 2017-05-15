This is a ShortPath demo in C++ with compiling environment gcc

This project contains four part: main.cpp util.cpp heap.cpp graph.cpp with corresponding header file:

util.cpp handle input command:
	W: print the current graph based on adjacent list
	R: read in file “GRAPHinput.txt” with graph
	P s t: print the shortest path from s to t both distance and route
	Q s t: compute all shortest path from s to any point and stop when it finish compute with t, then print both route and what left in heap
	S: Stop program
graph.cpp as a structure to store graph

heap.cpp as heap functions to maintain O(nlogn) complexity in Dijkstra’s shortest path algorithm


