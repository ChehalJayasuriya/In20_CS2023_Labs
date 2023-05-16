#include <iostream>
#include <list>
using namespace std;

struct Node {
    // A node will have 2 entities
    //1. data type int called label
    //2. a int type list called neighbours
    int label;
    list<int> neighbours;
};

struct Graph {
    int n = 8;
    Node* nodes = new Node[n];

    void initializeNodes() {
        for (int i = 0; i < n; i++) {
            nodes[i].label = i;
        }
    }

    void addEdge(int u, int v) {    
        //since an undirected graph is created, both nodes are connected to each other
        //select node u and push v into u's neighbour
        nodes[u].neighbours.push_back(v);
        //select node v and push u into v's neighbour
        nodes[v].neighbours.push_back(u);
    }

    void print() {
        //lets iterate through each node and print its neighbours
        for(int i = 1; i <= n; i++){
            cout << "Node " << i << " neighbours -> ";
            for (int neighbour : nodes[i].neighbours){
                cout << neighbour << " -> ";
            }
            cout << "x" << endl;
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->initializeNodes();
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(1, 5);
    g->addEdge(2, 3);
    g->addEdge(2, 6);
    g->addEdge(4, 6);
    g->addEdge(4, 7);
    g->addEdge(4, 8);
    g->addEdge(5, 6);
    g->addEdge(5, 7);
    g->addEdge(5, 8);

    g->print();

    delete g; // free the allocated memory
    return 0;
}

