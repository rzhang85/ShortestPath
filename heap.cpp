//
//  heap.cpp
//  SP
//
//  Created by Ru Zhang on 4/22/17.
//  Copyright © 2017 Ru Zhang. All rights reserved.
//

#include "heap.h"
#include "main.h"

#include <stdlib.h>
#include <climits>
#include <cmath>

Heap::Heap(int c){
    capacity = c;
    size = c;
    H = new ELEMENT*[capacity+1];
    for (int i = 1; i <= c; i++) {
        H[i] = new ELEMENT;
        H[i]->name = i;
        H[i]->distance = INT_MAX;
        H[i]->Parent = INT_MAX;
    }
}


Heap::Heap(){
    capacity = -1;
}

Heap::~Heap(void){
}


void Heap::swap(int i, int j){
    ELEMENT *temp = new ELEMENT;
    temp -> name = H[j] -> name;
    temp -> distance = H[j] -> distance;
    temp -> Parent = H[j] -> Parent;
    
    H[j] -> name = H[i] -> name;
    H[j] -> distance = H[i] -> distance;
    H[j] -> Parent = H[i] -> Parent;
    
    H[i] -> name = temp -> name;
    H[i] -> distance = temp -> distance;
    H[i] -> Parent = temp -> Parent;

    //resultList[H[i]->name].position = j;
    //resultList[H[j]->name].position = i;
    
    swapReListPos(i, j);
    
    delete temp;
}



int Heap::getElementDistance(int i){
    return H[i] -> distance;
}

ELEMENT* Heap::getElement(int i){
    return H[i];
}

void Heap::setElementDistance(int i, int d){
    H[i] -> distance = d;
}

void Heap::setElementParent(int i, int p){
    H[i] -> Parent = p;
}




void Heapify(Heap& heap, int i){
    int l, r, smallest;
    l = Left(i);
    r = Right(i);
    if(l <= heap.getSize() && heap.getElementDistance(l) < heap.getElementDistance(i))
        smallest = l;
    else
        smallest = i;
    if(r <= heap.getSize() && heap.getElementDistance(r) < heap.getElementDistance(smallest))
        smallest = r;
    if(smallest != i){
        heap.swap(smallest, i);
        Heapify(heap, smallest);
    }
}


int Parent(int i){
    return floor(i/2);
}

int Left(int i){
    return 2*i;
}

int Right(int i){
    return 2*i+1;
}

