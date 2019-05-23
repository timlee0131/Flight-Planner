#include "DS_String.h"
#include "DSVector.h"
#include "graph.h"
#include "DS_AdjList.h"
#include "DS_AdjNode.h"
#include "DS_Node.h"
#include "DS_Linklist.h"
#include "DS_Stack.h"
#include <iostream>
#include <fstream>
using namespace std;

void graph::parse1(char* file1) {
    ifstream input(file1);

    //getting the size. first line of file1.
    DS_String temp_s;
    Getline(input, temp_s);
    size1 = atoi(temp_s.get_array());

    for(int i = 0; i < size1; i++) {
        DS_String origin = "";
        DS_String destination = "";
        DS_String cost, time_m;

        Getline(input, origin, '|');
        Getline(input, destination, '|');
        Getline(input, cost, '|');
        Getline(input, time_m);
        data_box data_o, data_d;
        data_o.city_name = origin;

        data_d.city_name = destination;
        data_d.cost = cost;
        data_d.time_m = time_m;
        insert(data_o, data_d);

        data_o.cost = cost;
        data_o.time_m = time_m;

        data_d.cost = "";
        data_d.time_m = "";
        insert(data_d, data_o);
    }//end for
}

void graph::parse2(char* file2, char* file3) {
    ifstream input(file2);
    ofstream output(file3);
    DS_String temp_s;
    Getline(input, temp_s);
    size2 = atoi(temp_s.get_array());

    for(int i = 0; i < size2; i++) {
        DS_String origin, destination, opt;
        data_box data_o, data_d;
        opt = "";
        Getline(input, origin, '|');
        Getline(input, destination, '|');
        Getline(input, opt);

        data_o.city_name = origin;
        data_o.cost = "";
        data_o.time_m = "";

        data_d.city_name = destination;
        data_d.cost = "";
        data_d.time_m = "";
        int j = i + 1;
        back_track(data_o, data_d, opt, output, j);
    }
    cout << "Backtracking algorithm finishes without segmentation fault or any other issues..." << endl;
}

void graph::insert(data_box& package1, data_box& package2) {
    if(list.get_head() == nullptr) {
        list.insert_back(package1);
        list.get_head() ->get_edges().insert_back(package2);
    } else {
        if(list.find(package1) == nullptr) {
            list.insert_back(package1);
            list.find(package1) -> get_edges().insert_back(package2);
        } else {
            list.find(package1) -> get_edges().insert_back(package2);
        }
    }//end else
}

void graph::back_track(data_box start, data_box end, DS_String opt, ofstream& output, int count) {

    DS_AdjNode<data_box>* temp = list.get_head();
    while(temp != nullptr) {
        temp -> get_edges().resetIter();
        temp = temp -> get_next();
    }//end while

    DS_Stack<data_box> stack_g;
    data_box curr_city, next_city;
    DSVector<DS_Stack<data_box>> path_vector;
    stack_g.push(start);
    int i = 0;
    while(!stack_g.isEmpty()) {
        curr_city.city_name = stack_g.peek().city_name;
        if(curr_city == end) {
            path_vector.DS_push_back(stack_g);
            stack_g.pop();
        } else {
            //when something is not a direct flight
            while(list.find(curr_city) -> get_edges().isIterValid() && stack_g.contains(list.find(curr_city) -> get_edges().getIter())) {
               list.find(curr_city) ->get_edges().stepIter();
            }//end nested while
             if(list.find(curr_city) ->get_edges().isIterValid()) {
                    next_city = list.find(curr_city) ->get_edges().getIter();
                    stack_g.push(next_city);
                    list.find(curr_city) ->get_edges().stepIter();

                }
                else {
                    stack_g.pop();
                    list.find(curr_city) ->get_edges().resetIter();
                }
        }//end nesting else
    }//end nesting while

    cout << start.city_name << ": loop terminates without issues" << endl;

    DSVector<double> time_min, cost;
    DSVector<DS_Linklist<DS_String>> city;
    char flag = opt[0];
    if(flag == 'T') {
        for(int i = 0; i < path_vector.getSize(); i++) {

            DS_Node<data_box>* curr = path_vector[i].get_list().get_head();
            double time_sum = 0.0;
            double cost_sum = 0.0;
            DS_Linklist<DS_String> list;
            while(curr != nullptr) {
                time_sum += atof(curr -> get_data().time_m.get_array());
                cost_sum += atof(curr -> get_data().cost.get_array());
                list.insert_back(curr -> get_data().city_name);
                curr = curr -> get_next();
            }
            time_min.DS_push_back(time_sum);
            cost.DS_push_back(cost_sum);
            city.DS_push_back(list);
        }//end nesting for

        //Sorting algorithm to sort the flight paths.
        int i,j;
        DS_Linklist<DS_String> tmp;
        double temp, temp2;
        for (i = 1; i < time_min.getSize(); i++) {
            j = i;
            while (j > 0 && time_min[j - 1] > time_min[j]) {
                tmp = city[j];
                temp = time_min[j];
                temp2 = cost[j];
                city[j] = city[j - 1];
                time_min[j] = time_min[j - 1];
                cost[j] = cost[j-1];
                city[j - 1] = tmp;
                time_min[j - 1] = temp;
                cost[j-1] = temp2;
                j--;
            }
        }
        if(path_vector.getSize() > 0) {
            output << "Flight " << count << ": " << city[0].get_head() ->get_data() << ", " << city[0].get_tail() ->get_data() << " " << "(Time)" << endl;
            if(time_min.getSize() <= 3) {
                for(int i = 0; i < time_min.getSize(); i++) {
                    DS_Node<DS_String>* curr = city[i].get_head();
                    output << "Path " << i + 1 << ": ";
                    while(curr != nullptr) {
                        if(curr ->get_next() != nullptr)
                            output << curr ->get_data() << " -> ";
                        else
                            output << curr ->get_data() << ". ";
                        curr = curr -> get_next();
                    }
                    output << "Time: " << time_min[i] << " Cost: " << cost[i] << endl;
                }
            output << endl;
            } else {
                for(int i = 0; i < 3; i++) {
                    DS_Node<DS_String>* curr = city[i].get_head();
                    output << "Path " << i + 1 << ": ";
                    while(curr != nullptr) {
                        if(curr ->get_next() != nullptr)
                            output << curr ->get_data() << " -> ";
                        else
                            output << curr ->get_data() << ". ";
                        curr = curr -> get_next();
                    }
                    output << "Time: " << time_min[i] << " Cost: " << cost[i] << endl;
                }
            output << endl;
            }
        } else {
            output << "Flight from " << start.city_name << " to " << end.city_name << " does not exist" << endl << endl;
        }

    } else {
        for(int i = 0; i < path_vector.getSize(); i++) {
            DS_Node<data_box>* curr = path_vector[i].get_list().get_head();
            if(curr ->get_data().city_name == path_vector[i].get_list().get_tail() ->get_data().city_name)
                break;
            double cost_sum = 0.0;
            double time_sum = 0.0;
            DS_Linklist<DS_String> list;
            while(curr != nullptr) {
                cost_sum += atof(curr -> get_data().cost.get_array());
                time_sum += atof(curr -> get_data().time_m.get_array());
                list.insert_back(curr -> get_data().city_name);
                curr = curr -> get_next();
            }
            cost.DS_push_back(cost_sum);
            time_min.DS_push_back(time_sum);
            city.DS_push_back(list);
        }//end nesting for

        //Sorting algorithm
        int i,j;
        DS_Linklist<DS_String> tmp;
        double temp, temp2;
        for (i = 1; i < cost.getSize(); i++) {
            j = i;
            while (j > 0 && cost[j - 1] > cost[j]) {
                tmp = city[j];
                temp = cost[j];
                temp2 = time_min[j];
                city[j] = city[j - 1];
                cost[j] = cost[j-1];
                time_min[j] = time_min[j-1];
                city[j - 1] = tmp;
                cost[j-1] = temp;
                time_min[j-1] = temp2;
                j--;
            }
        }
        if(path_vector.getSize() > 0) {
            output << "Flight " << count << ": " << city[0].get_head() ->get_data() << ", " << city[0].get_tail() ->get_data() << " " << "(Cost)" << endl;
            if(cost.getSize() <= 3) {
                for(int i = 0; i < cost.getSize(); i++) {
                    DS_Node<DS_String>* curr = city[i].get_head();
                    output << "Path " << i + 1 << ": ";
                    while(curr != nullptr) {
                        if(curr ->get_next() != nullptr)
                            output << curr ->get_data() << " -> ";
                        else
                            output << curr ->get_data() << ". ";
                        curr = curr -> get_next();
                    }
                    output << "Time: " << time_min[i] << " Cost: " << cost[i] << endl;
                }//end nesting for
                output << endl;
            } else {
                for(int i = 0; i < 3; i++) {
                    DS_Node<DS_String>* curr = city[i].get_head();
                    output << "Path " << i + 1 << ": ";
                    while(curr != nullptr) {
                        if(curr ->get_next() != nullptr)
                            output << curr ->get_data() << " -> ";
                        else
                            output << curr ->get_data() << ". ";
                        curr = curr -> get_next();
                    }
                    output << "Time: " << time_min[i] << " Cost: " << cost[i] << endl;
                }//end nesting for
                output << endl;
            }
        } else {
            output << "Flight from " << start.city_name << " to " << end.city_name << " does not exist" << endl;
        }
    }//end nesting else
}

void graph::display() {
    DS_AdjNode<data_box>* curr = list.get_head();
    cout << "display()" << endl;
    while(curr != nullptr) {
        cout << curr -> get_data().city_name << "(" << curr -> get_data().cost << "|" << curr -> get_data().time_m << ")" << " -> ";
        DS_Node<data_box>* curr2 = curr -> get_edges().get_head();
        while(curr2 != nullptr) {
            cout << curr2 -> get_data().city_name << "(" << curr2 -> get_data().cost << "|" << curr2 -> get_data().time_m << ")" << " -> ";
            curr2 = curr2 -> get_next();
        }//end nested while
        cout << endl;
        curr = curr -> get_next();
    }//end nesting while
}

