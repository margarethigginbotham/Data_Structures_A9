#ifndef ASSIGNMENT9_H
#define ASSIGNMENT9_H

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

#include <vector>
#include <list>
#include <string>

class graph {
  private:
    int size;
    std::vector <std::list<int>> adj_list;
    std::vector <char> labels;
    void depth_first(int);

    std::vector <char> pos;
    std::string current;

  public:
    graph(const char* filename);
    ~graph();
    int get_size() const;
    void traverse();
    void print() const;
};

#endif
