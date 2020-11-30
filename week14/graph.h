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
    GraphVertex(T _val) {
        val = _val;
    };

    T get_val() {return val;};
    void set_val(T _val) {val = _val;};

    std::vector<int> get_adj() {return adj;};
    void add_to_adj(int idx) {adj.push_back(idx);};
};

template <class T>
class Graph
{
private:
    std::vector<GraphVertex<T> > nodes;
    bool is_directed;

public:
    ~Graph() {};
    Graph() {is_directed=false;};
    Graph(bool _is_directed) {is_directed=_is_directed;};

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
        // Create vector for visited flag
        std::vector<bool> visited(nodes.size(), false);
        
        // Create a queue for BFS 
        std::queue<int> queue;
    
        // Mark the current node as visited and enqueue it 
        visited[start_vertex] = true; 
        queue.push(start_vertex);
            
        while(!queue.empty()) 
        { 
            // Dequeue a vertex from queue and print it 
            int s = queue.front(); 
            // Do something with the vertex
            std::cout << nodes[s].get_val() << " "; 
            queue.pop(); 
    
            // Get all adjacent vertices of the dequeued 
            // vertex s. If a adjacent has not been visited,  
            // then mark it visited and enqueue it 
            for (std::vector<int>::iterator i = nodes[s].get_adj().begin(); 
                i != nodes[s].get_adj().end(); ++i) 
            { 
                if (!visited[*i]) 
                { 
                    visited[*i] = true; 
                    queue.push(*i); 
                } 
            }
        } 
        std::cout << std::endl;
    };

    void DFS(int start_vertex)
    {
        // Create vector for visited flag
        std::vector<bool> visited(nodes.size(), false);
        
        // Create a stack for DFS 
        std::stack<int> stack;

        stack.push(start_vertex);
    
            
        while(!stack.empty()) 
        { 
            // Dequeue a vertex from queue and print it 
            int s = stack.top();
            stack.pop();

            if (!visited[s])
            {            
                visited[s] = true;
                // Do something with the vertex
                std::cout << nodes[s].get_val() << " "; 
            }

            // Get all adjacent vertices of the dequeued 
            // vertex s. If a adjacent has not been visited,  
            // then mark it visited and enqueue it 
            for (std::vector<int>::iterator i = nodes[s].get_adj().begin(); 
                i != nodes[s].get_adj().end(); ++i) 
            { 
                if (!visited[*i]) 
                { 
                    stack.push(*i); 
                } 
            }
        } 
        std::cout << std::endl;
    };

    void print()
    {
        for (size_t i = 0; i < nodes.size(); i++)
        {
            std::cout << i << ": " << nodes[i].get_val() << " --> ";
            for (size_t j = 0; j < nodes[i].get_adj().size(); j++)
            {
                std::cout << nodes[i].get_adj()[j] << ", ";
            }
            std::cout << std::endl;
        }        
    }
};

#endif