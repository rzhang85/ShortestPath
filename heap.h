//
//  heap.hpp
//  SP
//
//  Created by Jack on 4/22/17.
//  Copyright © 2017 Ru Zhang. All rights reserved.
//

#ifndef heap_h
#define heap_h

struct ELEMENT{
    int name;
    int distance;
    int Parent;
};

class Heap{
private:
    int capacity;
    int size;
    ELEMENT ** H;
    
public:
    Heap();
    Heap(int c);
    ~Heap(void);
    
    
    int getCapacity() {return capacity;}
    int getSize() {return size;}

    int getElementName(int i) {return H[i]->name;}
    int getElementDistance(int i);
    int getElementParent(int i) {return H[i]->Parent;}
    ELEMENT* getElement(int i);
    
    void setElementName(int i, int n) {H[i]->name = n;}
    void setElementDistance(int i, int d);
    void setElementParent(int i, int p);
    
    void swap(int i, int j);
    void sizeDecrease(){size--;}
    
    //void sizeIncrease(){size++;}
    
};

Heap Initialize(int);

void Heapify(Heap& heap, int i);

int Parent(int i);
int Left(int i);
int Right(int i);

#endif /* heap_h */
