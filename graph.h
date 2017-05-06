//
//  graph.hpp
//  SP
//
//  Created by Ru Zhang on 4/20/17.
//  Copyright © 2017 Ru Zhang. All rights reserved.
//

#ifndef graph_h
#define graph_h



struct EDGES {
    int v;
    int weight;
    struct EDGES * next;
};

class Graph{

private:
    int size;
    EDGES **list;

public:
    Graph();
    Graph(int n);
    ~Graph(void);
    void InsertEdges(int new_u, int new_v, int w);
    int getSize();
    EDGES* getEdges(int i);
};



#endif /* graph_h */
