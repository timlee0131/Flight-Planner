#ifndef GRAPH_H
#define GRAPH_H

#include "DS_String.h"
#include "DS_AdjList.h"
#include "DS_Stack.h"
#include "DSVector.h"
using namespace std;

struct data_box {
    DS_String city_name;
    DS_String cost;        //in dollars
    DS_String time_m;        //in minutes

    friend bool operator==(data_box& x, data_box& y) {
        if(x.city_name == y.city_name) {
            return true;
        }   return false;
    }//end == overload
};

// struct path_box {
//     DS_Linklist<DS_String> path_list;
//     double time_sum, cost_sum;
// };

class graph {
private:
    DS_AdjList<data_box> list;
    int size1;
    int size2;
public:
    void parse1(char*);
    void parse2(char*, char*);
    void insert(data_box&, data_box&);
    void display();
    void display_path();
    void back_track(data_box start, data_box end, DS_String, ofstream&, int count);
};
#endif
