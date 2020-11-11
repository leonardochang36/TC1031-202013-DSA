#ifndef _GRAPH_H_
#define _GRAPH_H_

#include<iostream> 
#include <list>
#include <vector>
#include <queue>
#include <stack>

template <class T>
class GraphVertex
{
private:
    T val;
    std::vector<int> adj;
public: 
    ~GraphVertex() {};
    GraphVertex() {};
    GraphVertex(T _val) {val = _val;};

    T get_val() {return val;};
    void set_val(T _val) {val = _val;};

    std::vector<int> get_adj() {return adj;};
    void add_to_adj(int idx) {adj.push_back(idx);};
};

// A B C D E F G H
// 0 1 2 3 4 5 6 7
// A: 1, 2, 3
// B: 0
// C: 0, 3


template <class T>
class Graph
{
private:
    std::vector<GraphVertex<T> > nodes;
    bool is_directed;

public:
    ~Graph() {};
    Graph() {is_directed=false;};

    void add_node(T val)
    {
        GraphVertex<T> node(val);
        nodes.push_back(node);
    };

    void add_edge(int src, int dst)
    {
        nodes[src].add_to_adj(dst);
        if (!is_directed)
            nodes[dst].add_to_adj(src);
    };

   
    void BFS(int start_vertex)
    {
        std::vector<bool> visited(nodes.size(), false);

        std::queue<int> queue;

        visited[start_vertex] = true;
        queue.push(start_vertex);

        while (!queue.empty())
        {
            int s = queue.front();
            
            // Do something with the vertex
            std::cout << nodes[s].get_val() << " ";

            queue.pop();
            for (std::vector<int>::iterator i = nodes[s].get_adj().begin();
                 i != nodes[s].get_adj().end(); i++)
            {
                if (!visited[*i])
                {
                    queue.push(*i);
                    visited[*i] = true;
                }
            }            
        }
        std::cout << std::endl;
    };

   
    void DFS(int start_vertex)
    {
        std::vector<bool> visited(nodes.size(), false);

        std::stack<int> stack;
        stack.push(start_vertex);

        while(!stack.empty())
        {
            int s = stack.top();
            stack.pop();

            if (!visited[s])
            {
                visited[s] = true;
                // Do something with the vertex
                std::cout << nodes[s].get_val() << " ";
            }

            for (std::vector<int>::iterator i = nodes[s].get_adj().begin();
                 i != nodes[s].get_adj().end(); i++)
            {
                if (!visited[*i])
                {
                    stack.push(*i);
                }
            }
        } 
        std::cout << std::endl;     
    };
};



#endif