#include "weighted_graph.h"
#include <string>

using namespace std;

int main()
{
    GraphWeighted<string> graph;
    graph.add_node("Hotel Nacional");
    graph.add_node("Capitolio");
    graph.add_node("El Morro");
    graph.add_node("La Catedral");
    graph.add_node("La Rampa");
    graph.add_node("Plaza Vieja");
    graph.add_node("Floridita");
    graph.add_node("El Prado");

    graph.add_edge(0, 1, 12);
    graph.add_edge(0, 5, 4);
    graph.add_edge(1, 5, 3);
    graph.add_edge(1, 2, 2);
    graph.add_edge(1, 4, 21);
    graph.add_edge(2, 3, 2);
    graph.add_edge(4, 6, 15);
    graph.add_edge(3, 6, 1);
    graph.add_edge(3, 7, 10);
    graph.add_edge(5, 7, 15);

    int start_vertex = 1;
    vector<float> dist = graph.shortest_path(start_vertex);
    cout << "Shortest path cost from " << graph.get_node_val(start_vertex) << " to:" << endl;
    for (size_t i = 0; i < dist.size(); i++)
    {
        cout << "\t" << graph.get_node_val(i) << ": " << dist[i] << endl;
    }

    return 0;    
}
