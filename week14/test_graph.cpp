#include "graph.h"
#include <string>

using namespace std;

int main()
{
    Graph<string> graph;
    graph.add_node("A");
    graph.add_node("B");
    graph.add_node("C");
    graph.add_node("D");
    graph.add_node("E");
    graph.add_node("F");
    graph.add_node("G");
    graph.add_node("H");

    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(0, 3);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(3, 5);
    graph.add_edge(3, 6);
    graph.add_edge(5, 6);
    graph.add_edge(5, 7);
    graph.add_edge(4, 7);

    graph.BFS(0);
    graph.DFS(0);
}
