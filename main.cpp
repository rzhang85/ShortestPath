//
//  main.cpp
//  SP
//
//  Created by Ru Zhang on 4/11/17.
//  Copyright © 2017 Ru Zhang. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>

#include "main.h"
#include "util.h"
#include "graph.h"
#include "heap.h"

Graph graph;
Heap heap;
int length = 0;

RESULT *resultList;
int vertexs_NUM = 0;
int edges_NUM = 0;


int main() {
    // insert code here...
    
    getInput();
    
    
    
    return 0;
}


void InitializeHeap(int c, int s){
    
    heap = *new Heap(c);
    resultList = new RESULT[vertexs_NUM+1];
    for (int i = 1; i <= vertexs_NUM; i++) {
        resultList[i].distance = INT_MAX;
        resultList[i].parent = INT_MAX;
        resultList[i].position = i;
    }
    heap.setElementDistance(s, 0); // s.d = 0
    HeapSort();
    
}


void HeapSort(){
    
    int size = heap.getSize();
    int start = floor(size/2);
    for(int i = start; i >= 1; i--){
        Heapify(heap, i);
    }
    
}

void ShortestPathQ(int s, int t){
    bool tf = true;
    if(s < 1 || t < 1 || s > vertexs_NUM || t > vertexs_NUM){
        cout << "Invalid index" << endl;
        return;
    }
    InitializeHeap(vertexs_NUM, s);
    
    while (heap.getSize() != 0 && heap.getElementDistance(1) != INT_MAX) {
        int vert = DeleteMin();
        EDGES *temp = graph.getEdges(vert);
        while(temp != NULL){
            if(resultList[temp->v].position != INT_MAX){
                Relax(vert, temp->v, temp->weight);
                HeapSort();
            }
            temp = temp->next;
        }
        //HeapSort();
        //cout << "sort" << endl;
        if(vert == t){
            tf = false;
            if(resultList[t].distance == INT_MAX){
                cout << "There is no route" << endl;
            }
            else{
                cout << resultList[t].distance << endl;
                cout << s;
                printRouteST(t);
                cout << endl;
            }
            printheap();
        }
        
        
        
    }
    if(tf){
        cout << "There is no route" << endl;
    }
    //printRoute();

    
}


void ShortestPath(int s, int t){
    
    if(s < 1 || t < 1 || s > vertexs_NUM || t > vertexs_NUM){
        cout << "Invalid index" << endl;
        return;
    }
    InitializeHeap(vertexs_NUM, s);
    
    while (heap.getSize() != 0 && heap.getElementDistance(1) != INT_MAX) {
        int vert = DeleteMin();
        EDGES *temp = graph.getEdges(vert);
        while(temp != NULL){
            if(resultList[temp->v].position != INT_MAX){
                Relax(vert, temp->v, temp->weight);
                HeapSort();
            }
            temp = temp->next;
        }
        //HeapSort();
        //cout << "sort" << endl;
        if(vert == t){
            //printheap();
        }
        
            
        
    }
    
    //printRoute();
    if(resultList[t].distance == INT_MAX){
        cout << "There is no route" << endl;
    }
    else{
        cout << resultList[t].distance << endl;
        cout << s;
        printRouteST(t);
        cout << endl;
    }
    
}


int DeleteMin(){
    if(heap.getSize() < 1){
        //cout << "Empty heap" << endl;
        return 0;
    }
    else{
        ELEMENT* MIN = heap.getElement(1);  // put min to ELEMENT MIN
        int currentMinName = MIN->name;
        
        // extract min to resultList
        resultList[MIN->name].distance = MIN->distance;
        resultList[MIN->name].parent = MIN->Parent;
        resultList[MIN->name].position = INT_MAX;
        
        
        // set the first ELEMENT to the last one
        heap.setElementDistance(1, heap.getElementDistance(heap.getSize()));
        heap.setElementName(1, heap.getElementName(heap.getSize()));
        heap.setElementParent(1, heap.getElementParent(heap.getSize()));
        heap.sizeDecrease();
        
        resultList[MIN->name].position = 1;
        // sort the array back
        Heapify(heap, 1);

        return  currentMinName;
    }
    
}



void Relax(int u, int v, int w){
    if(heap.getElementDistance(resultList[v].position) > resultList[u].distance + w){
        heap.setElementDistance(resultList[v].position, resultList[u].distance + w); // v.d = u.d + w(u,v)
        heap.setElementParent(resultList[v].position, u);
        
        resultList[v].distance = resultList[u].distance + w;
        resultList[v].parent = u; // v.pi = u
        
        // HeapSort();
        // decreae key
        // *****************
    }
}

void swapReListPos(int i, int j){
    resultList[heap.getElementName(i)].position = i;
    resultList[heap.getElementName(j)].position = j;
}




// PRINT and LOAD functions

void printRouteST(int t){
    if(resultList[t].parent != INT_MAX){
        printRouteST(resultList[t].parent);
        cout << " " << t;
    }
}

void printRoute(){
    for (int i = 1; i <= vertexs_NUM; i++) {
        cout << i << ": distance- " << resultList[i].distance << " parent- " << resultList[i].parent << endl;
    }
}

void printheap(){
    cout << "Heap: ";
    for (int i = 1; i <= heap.getSize(); i++) {
        cout << heap.getElementName(i) << " ";
    }
    cout << endl;
}


bool Load(){
    cout << "Read in txt file: GRAPHinput.txt" << endl;
    
    int u, v, w;
    ifstream myFileVar;
    myFileVar.open("GRAPHinput.txt"); // open file
    if (myFileVar.is_open()) {
        myFileVar >> vertexs_NUM >> edges_NUM;
        graph = *new Graph(vertexs_NUM);    // create graph;
        for (int i = 1; i <= edges_NUM; i++) {
            myFileVar >> u >> v >> w;
            if(u > vertexs_NUM){
                cout << "Invalid Edge in line " << i << ": " << u << " " << v << " " << w << endl;
                myFileVar.close();
                return false;
            }
            graph.InsertEdges(u, v, w);
        }
        myFileVar.close();
        cout << "Read in finished" << endl;
        return true;
    }
    else
        cout << "Can't open file" << endl;
    return false;
}

void Print(){
    
    if(graph.getSize() == 0){
        cout << "There is no graph" << endl;
        return;
    }
    cout << vertexs_NUM << " " << edges_NUM << endl;
    
    for(int i = 1; i<= graph.getSize(); i++){
        cout << i << " : ";
        EDGES *temp = graph.getEdges(i);
        while (temp != NULL) {
            cout << "(" << temp->v << " " << temp->weight << ")";
            temp = temp -> next;
        }
        cout << endl;
    }
    
}
