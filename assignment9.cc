#define ASSIGNMENT9_TEST
#ifdef 	ASSIGNMENT9_TEST

#include "assignment9.h"

//******************************************************************//
//   PROGRAM:    CSCI 340 Assignment 9                              //
//   PROGRAMMER: Margaret Higginbotham                              //
//   LOGON ID:   z1793581                                           //
//   DUE DATE:   May 2, 2018                                        //
//                                                                  //
//   FUNCTION:   Implements several graph algorithms on simple      //
//               graphs. These graphs are implemented with          //
//               adjacency list representation.                     //
//******************************************************************//

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

/***************************************************************
graph::~graph()
Use: destructor
Parameters: none
Returns: nothing
***************************************************************/
graph::~graph(){
}

/***************************************************************
int graph::get_size() const
Use: gets the size of the graph (number of verticies)
Parameters: none
Returns: int- size/number of verticies
***************************************************************/
int graph::get_size() const{
  return size;
}

/***************************************************************
graph::graph(const char* filename)
Use: constructor, reads from input file with adj maxtix and builds list
Parameters: 1. const char* filename- input file of graph
Returns: nothing
***************************************************************/
graph::graph(const char* filename){
  current = "";

  ifstream infile(filename, ios::in);
  string line;
  infile >> size;

  for(int i = 0; i < size; i ++){
    infile >> line;
    labels.push_back(line[0]);
  }

  for(int i = 0; i < size; i ++){
    infile >> line;
    adj_list.push_back(*(new list<int>()));

    for(int j = 0; j < size; j ++){
      int num;
      infile >> num;
      adj_list[i].push_back(num);
    }

  }

}

/***************************************************************
void graph::depth_first(int v)
Use: traverses the graph in depth_first traversal algorithm
Parameters: 1. int v- current vertex
Returns: nothing
***************************************************************/
void graph::depth_first(int v){
  int count = 0;

  cout << labels[v] << " ";

  pos.push_back(v);

  for(list<int>::iterator it = adj_list[v].begin(); it != adj_list[v].end(); it ++){
    if(*it == 1 && find(pos.begin(),pos.end(), count) == pos.end()){
      current += string("(") + labels[v] + string(", ") + labels[count] + string(") ");

      depth_first(count);
    }

    count++;
  }

}

/***************************************************************
void graph::traverse()
Use: traverses the graph and invokes depth_first
Parameters: none
Returns: nothing
***************************************************************/
void graph::traverse(){
  cout << "------ traverse of graph ------" << endl;

  for(int i = 0; i < size; i++){
    if(find(pos.begin(), pos.end(), i) == pos.end())
      depth_first(i);
  }

  cout << endl << current << endl;

  current = "";

  cout << "--------- end of traverse -------" << endl << endl;
}

/***************************************************************
void graph::print() const
Use: prints the adj list for the graph
Parameters: none
Returns: nothing
***************************************************************/
void graph::print() const{
  cout << endl << "Number of verticies in the graph: " << size << endl << endl;
  cout << "------ graph ------" << endl;

  for(int i = 0; i < size; i++){
    cout << labels[i] << "; ";
    int count = 0;

    for(list<int>::const_iterator it = adj_list[i].begin(); it !=adj_list[i].end(); it++){
      if(*it == 1){
        cout << labels[count] << ", ";
      }

      count++;
    }

    cout << endl;
  }

  cout << "------ end of graph ------" << endl << endl;
}

////////////////////////////////////////////////////////////////
//                           MAIN                             //
////////////////////////////////////////////////////////////////
int main(int argc, char** argv){
  if(argc < 2){
    cerr << "args: input-file-name\n";
    return 1;
  }

  graph g(argv[1]);

  g.print();

  g.traverse();

  return 0;
}

#endif
