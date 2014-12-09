/* This program was written by Ben Clay.  It may be used without the author's consent for non-profit puproses only. */

#include <string>
#include <iostream>

Graph::Graph(unsigned int numNodes)
{
    adjList.resize(numNodes);
}

/**************************************************************
 Return the cost of the edge from node1 to node2. If there is 
 no edge, return -1.
 **************************************************************/
double Graph::getCost(int node1, int node2)
{
    for (int i = 0; i < adjList.at(node1).edgeList.size(); i++)
    {
        if (adjList.at(node1).edgeList.at(i).dest == node2)
            return adjList.at(node1).edgeList.at(i).cost;
    }
    
    return -1;
}

/**************************************************************
 Add an edge from node1 to node2, and from node2 to node1, with
 the given cost. If the cost is < 0, throw a string exception.
 **************************************************************/
void Graph::addEdge(int node1, int node2, double cost)
{
    try
    {
        if(cost < 0)
            throw std::string ("Cost cannot be negative");
        else
        {
            unsigned long pos = adjList.at(node1).edgeList.size() + 1;
            adjList.at(node1).edgeList.resize(pos);
            adjList.at(node1).edgeList.at(pos-1).cost = cost;
            adjList.at(node1).edgeList.at(pos-1).dest = node2;
            
            pos = adjList.at(node2).edgeList.size() + 1;
            adjList.at(node2).edgeList.resize(pos);
            adjList.at(node2).edgeList.at(pos-1).cost = cost;
            adjList.at(node2).edgeList.at(pos-1).dest = node1;
        }
    }
    catch(std::string s)
    {
        std::cout << s << std::endl;
    }
}

/**************************************************************
 Remove the edge from node1 to node2, and also from node2 to
 node1. If there are no such edges, then don't do anything.
 **************************************************************/
void Graph::removeEdge(int node1, int node2)
{
    for (int i = 0; i < adjList.at(node1).edgeList.size(); i++)
    {
        if (adjList.at(node1).edgeList.at(i).dest == node2)
        {
            adjList.at(node1).edgeList.at(i).dest = -1;
            adjList.at(node1).edgeList.at(i).cost = -1;
        }
    }
    
    for (int i = 0; i < adjList.at(node2).edgeList.size(); i++)
    {
        if (adjList.at(node2).edgeList.at(i).dest == node1)
        {
            adjList.at(node2).edgeList.at(i).dest = -1;
            adjList.at(node2).edgeList.at(i).cost = -1;
        }
    }
}