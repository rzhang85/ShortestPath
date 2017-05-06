//
//  graph.cpp
//  SP
//
//  Created by Ru Zhang on 4/20/17.
//  Copyright © 2017 Ru Zhang. All rights reserved.
//

#include "graph.h"

#include <stdio.h>
#include <stdlib.h>



Graph::Graph(){
    size = 0;
}

Graph::Graph(int n){
    size = n;
    list = new EDGES*[n+1];
    for (int i = 1; i <= n; i++) {
        list[i] = NULL;
    }
  
}

Graph::~Graph(){
}

void Graph::InsertEdges(int new_u, int new_v, int new_w){
    EDGES *new_edge = new EDGES;
    new_edge->v = new_v;
    new_edge->weight = new_w;
    // to be continued
    if (list[new_u] == NULL) {
        list[new_u] = new_edge;
        new_edge->next = NULL;
    }
    else{
        new_edge->next = list[new_u];
        list[new_u] = new_edge;
    }
    
}

int Graph::getSize(){
    return size;
}

EDGES* Graph::getEdges(int i){
    //if(A[i])
    return list[i];
}




