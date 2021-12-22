# Flight-Planner

This flight planner program uses an iterative backtracking algorithm to find the most optimal path between two given cities given various paths. There are two input files, "input1.txt" and "input2.txt", and one output file, "output.txt". More information about the respective input files are written below.

input1.txt: This file contains a sequence of city pairs representing 0-stop flights that can be used in preparing a flight plan. For each of these, the file also contains a dollar cost for that leg and a time to travel. Each pair in the file is a bi-directional path.

input2.txt: This file contains a sequence of origin/destination city pairs. For each pair,the program determines if the flight is or is not possible. If it is possible, it outputs to a file the flight plan with the total cost for the flight. If it is not possible, then a suitable message is written to the output file.

output.txt: For each requested flight path, the program outputs 3 most efficient paths. if there are 3 paths or more. If there are less than 3 paths, all paths are printed. If no flight plan can be created (because there is no viable path between the two requested cities), the program outputs a message saying there is no flight path for those given cities. 

All the data structure classes in this program (i.e. Stack, doubly-linkedlist, vector, string) were written from scratch, and not from standard C++ libraries.


