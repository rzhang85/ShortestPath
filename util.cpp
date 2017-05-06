//
//  util.cpp
//  SP
//
//  Created by Ru Zhang on 4/11/17.
//  Copyright © 2017 Ru Zhang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

#include "util.h"
#include "main.h"



void getInput(){
    string ch;
    do {
        getline(cin, ch);
        if(ch.size()==0){
            cout << "Invalid Input" << endl;
        }
        else
            branching(ch);
        
    } while (!(ch.size() == 1 && ch.at(0) == 'S'));

}

void branching(string str){
    int s = 0;
    int t = 0;
    
    if(str.size() == 1){
        char c = str.at(0);
        switch (c) {
            case 'S':
                cout << "Program Stop" << endl;
                break;
                
            case 'R':
                Load();
                break;
                
            case 'W':
                Print();
                break;
                
            default:
                cout << "Invalid Input" << endl;
                break;
        }
    
    }
    else{
        char c = str.at(0);
        str.erase(0,1);
        stringstream stream(str);
        
        switch (c) {
            case 'P':
                if(stream >> s >> t){
                    //cout << "p with " << s << " and " << t << endl;
                    ShortestPath(s, t);
                }
                else
                    cout << "Invalid Input" << endl;
                break;
            
            case 'Q':
                if(stream >> s >> t){
                    //cout << "p with " << s << " and " << t << endl;
                    ShortestPathQ(s, t);
                }
                else
                    cout << "Invalid Input" << endl;
                break;
                
            default:
                cout << "Invalid Input" << endl;
                break;
        }
        
        
    }
    
    
}
