#include "simplegraph.h"
#include <fstream>
#include <iostream>
#include <list>
#include <vector>


using namespace std;

vector<bool> visited;   // global vector to store bools
list<int> verticies;     // global list to hold vertices
vector< pair <int,int> > edges;     // global vector to hold pairs of ints



Graph::Graph(const char* filename)
{
    // declaring ifstream variable
    ifstream is1;

    //opening specified file
    is1.open(filename);

    // error checking
    if(is1.fail())
    {
        cout << "COULD NOT OPEN FILE";
        exit(EXIT_FAILURE);
    }

    // first thing in the file will be the size, so set Graph.size = to that number
    is1 >> size;


    // storing labels into labels vector
    for(int i = 0; i < size; ++i)
    {
        // character variable
        char c;

        // set data from input stream as value of char variable
        is1 >> c;

        // push that value into labels vector
        labels.push_back(c);
    }

    list<int> edges; // list to hold edges

    char vertexname;    // going to read the first letter and store it in here so we can get to numbers

    int edgenum;    // will be the int value associated with the edge between 2 vertices

    for(int i =0; i < size; ++i)    // going to have size-1 rows
    {
        is1 >> vertexname;  // lets put the letter into here to bypass it

        for(int index = 0; index < size; ++ index)  // will have size-1 columns
        {
            is1 >> edgenum; // store the edge number in here

            edges.push_back(edgenum);   // push into our int list
        }

        adj_list.push_back(edges);  // when done push that list into our vector

        edges.clear();          // clear the list so we don't keep previous numbers
    }

    is1.close();        // close file as we are done reading from it

}

Graph::~Graph()
{
    labels.clear(); // clear labels and adj_list
    adj_list.clear();


    size = 0;       // not sure if this is needed but I felt I should clear size out as well
}

void Graph::Depthfirst(int vertex)
{
    if(visited[vertex] == false) // this when used with traverse will push all vertices onto the vertices vector
    {
        verticies.push_back(vertex);
    }

    visited[vertex] = true; // set to true so we now know we've visted this element

    list<int>::const_iterator itr = adj_list[vertex].begin();  //beginning of index called vertex of adj_list
    int i = 0;

    for(; itr != adj_list[vertex].end(); ++itr, ++i) // until we reach the end, increase itr and i
    {
        if(visited[i]  == false && *itr == 1)
        {
            edges.push_back(make_pair(vertex,i));    // if we haven't visited this vertex and itr value = 1
                                                // make pair of origial vertex , and corresponding vertex i
            Depthfirst(i);                      // perfrom depth first with vertex i 
        }
    }

}

int Graph::Getsize() const
{
    return size;
}

void Graph::Traverse()
{
    visited = *new vector<bool>(size,false);    // vector of bools, size = number of vertices
                                                // and all values set to false as we have no visited
                                                // any of them yet

    for(int i =0; i < size; ++i)                // for every vertex
    {
        if(visited[i] == false)                 // if we haven't visited, perform Depthfirst
        {
            Depthfirst(i);
        }
    }

    cout << "\n---------- traverse of graph ---------" << endl;

    list<int>::const_iterator itr = verticies.begin();

    for(; itr != verticies.end(); ++itr)    // do until we reach the end
    {
        cout << labels[*itr] << " ";        // printing every vertex
    }

    cout << endl;

    for(int i = 0; i < edges.size(); ++i)       // do this for everything in edges
    {
        cout << "(" << labels[edges[i].first] << ", ";  // using first value of pair as an element of labels to print corresponding letter
        cout << labels[edges[i].second] << ") ";        // same logic but with the second value
    }

    cout << endl;

    cout << "\n---------- end of traverse ---------" << endl;

}

void Graph::Print() const
{
     cout << "\nNumber of verticies in graph: " << size << endl << endl;
     cout << "\n---------- graph ---------" << endl;


     vector<char> printvec;     // I will store vertices that have an edge with a specific vertex
                                // in here, and will then print it so that we don't have an extra comma
                                // the extra comma is bothering me so I'm getting rid of it

     
    for(int i =0; i < size; ++i)
    {
        cout << labels[i] << ": ";          // print the label
        list<int> temp = adj_list[i];       // temporary list =  ith element in adj_list

        list<int>::iterator itr = temp.begin();     // start at beginning of list

        int labels_index = 0;    

        while(itr != temp.end())      // until we reach the end
        {
            if(*itr == 1)               // if the value at the iterator is 1 then print the index value associated with labels
            {
                printvec.push_back(labels[labels_index]);
            }

            ++labels_index;          // increase  index to traverse entire list
            ++itr;                   // increase itr to traverse list
        }


        vector<char>::iterator print_itr = printvec.begin();    // start at beginning of this vector

        while(print_itr < printvec.end() - 1)   // go until we are at second to last value
        {                                      
            cout << *print_itr << ", ";         // print value followed by a comma
            ++print_itr;                        // increase so keep traversing
        }

        // now at this point print_itr will be the last value in the vector so I will print
        // but without the comma

        cout << *print_itr;

        //now I will clear printvec so that we do not carry over the previous values
        //from the last time it was used

        printvec.clear();

        cout << endl;
   
     
    }

    cout << "----------- end of graph ----------" << endl << endl;
}

int main() 
{
  Graph g("simplegraph.input");

  g.Print();

  g.Traverse();

  return 0;
}