#ifndef SIMPLEGRAPH_H
#define SIMPLEGRAPH_H
#include <list>
#include <vector>

class Graph {
 private:
  int                          size;
  std::vector<std::list<int> > adj_list;
  std::vector<char>            labels;
  void                         Depthfirst(int vertex);

 public:
  Graph(const char* filename);
  ~Graph();
  int  Getsize() const;
  void Traverse();
  void Print() const;
};

#endif // SIMPLEGRAPH_H