//
//  main.h
//  SP
//
//  Created by Ru Zhang on 4/11/17.
//  Copyright © 2017 Ru Zhang. All rights reserved.
//

#ifndef main_h
#define main_h

struct RESULT{
    int distance;
    int parent;
    int position;

    
};

int main();


void ShortestPath(int s, int t);
void ShortestPathQ(int s, int t);

void printRouteST(int t);
void printRoute();
void InitializeHeap(int c, int s);

void Relax(int u, int v, int w);
void swapReListPos(int i, int j);

int DeleteMin();
void HeapSort();

void printheap();
bool Load();
void Print();


#endif /* main_h */
