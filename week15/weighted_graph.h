#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream> 
#include <utility> 
#include <limits.h>
#include <vector>
#include <list>
#include <queue>
#include <stack>

template <class T>
class GraphVertexWeighted
{
private:
    T val;
    std::vector<std::pair<int, float> > adj;
public: 
    ~GraphVertexWeighted() {};
    GraphVertexWeighted() {};
    GraphVertexWeighted(T _val) {val = _val;};

    T get_val() {return val;};
    void set_val(T _val) {val = _val;};

    std::vector<std::pair<int, float> > get_adj() {return adj;};
    void add_to_adj(int idx, float weight) {adj.push_back(std::make_pair(idx, weight));};
};


template <class T>
class GraphWeighted
{
private:
    std::vector<GraphVertexWeighted<T> > nodes;
    bool is_directed;

public:
    ~GraphWeighted() {};
    GraphWeighted() {is_directed=false;};

    void add_node(T val)
    {
        GraphVertexWeighted<T> node(val);
        nodes.push_back(node);
    };

    void add_edge(int src, int dst, float weight)
    {
        nodes[src].add_to_adj(dst, weight);
        if (!is_directed)
            nodes[dst].add_to_adj(src, weight);
    };

    T get_node_val(int i)
    {
        return nodes[i].get_val();
    };

    // Dijsktra algorithm implementation
    std::vector<float> shortest_path(int s)
    {
        // create vector for distances from s to every other vertex
        std::vector<float> dist(nodes.size(), INT_MAX);

        // create vector for visited
        std::vector<bool> visited(nodes.size(), false);

        // distance to self vertex is zero
        dist[s] = 0;

        for (size_t ii = 0; ii < nodes.size(); ii++)        
        {
            // find the non-visited vertex with smallest distance estimation
            int sv = -1;
            float mind = INT_MAX;
            for (size_t i = 0; i < nodes.size(); i++)
            {
                if (!visited[i] && dist[i] <= mind)
                    sv = i, mind = dist[i];
            }

            if (sv < 0)
                return dist;

            // Get all adjacent vertices of sv
            // and update distance estimations
            std::vector<std::pair<int, float> >::iterator i;
            for (i = nodes[sv].get_adj().begin(); i != nodes[sv].get_adj().end(); ++i) 
            { 
                // neighbor i index in nodes
                int vi = (*i).first;

                // only update non-visited vertex
                if (visited[vi])
                    continue;

                // update distance estimation for vi    
                dist[vi] = std::min(dist[vi], dist[sv] + (*i).second);
            }
            visited[sv] = true;
        }
        return dist;      
    };
};



#endif