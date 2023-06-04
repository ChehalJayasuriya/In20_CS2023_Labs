#include <iostream>
#include <limits.h>
#include <vector>
#include <string>

using namespace std;

#define max_n 6

struct City {
    string name;
    int time;
    vector<string> path;
};

int findMinDistance(const vector<City>& cities, const vector<bool>& sptSet)
{
    int minTime = INT_MAX, minIndex;
    for (int v = 0; v < max_n; v++)
        if (sptSet[v] == false && cities[v].time <= minTime)
            minTime = cities[v].time, minIndex = v;
    return minIndex;
}

void printSolution(const vector<City>& cities, int src)
{
    for (int i = 0; i < max_n; i++) {
        if (i != src) {
            cout << "Shortest path from " << cities[src].name << " to " << cities[i].name << " takes " << cities[i].time << " units of time. Path: ";
            for (const string& city : cities[i].path) {
                cout << city << " ";
            }
            cout << cities[i].name << endl;
        }
    }
}

void dijkstra(const vector<vector<int>>& adj_mat, const vector<string>& cityNames, int src)
{
    vector<City> cities(max_n);
    vector<bool> sptSet(max_n, false);

    for (int i = 0; i < max_n; i++) {
        cities[i].name = cityNames[i];
        cities[i].time = INT_MAX;
    }

    cities[src].time = 0;
    cities[src].path.push_back(cityNames[src]);

    for (int count = 0; count < max_n - 1; count++) {
        int u = findMinDistance(cities, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < max_n; v++) {
            if (!sptSet[v] && adj_mat[u][v] && cities[u].time != INT_MAX &&
                cities[u].time + adj_mat[u][v] < cities[v].time) {
                cities[v].time = cities[u].time + adj_mat[u][v];
                cities[v].path = cities[u].path;
                cities[v].path.push_back(cityNames[v]);
            }
        }
    }

    printSolution(cities, src);
}

int main()
{
    vector<string> cityNames = { "City 0", "City 1", "City 2", "City 3", "City 4", "City 5" };
    vector<vector<int>> adj_mat = {
        { 0, 10,  0,  0, 15,  5 },
        { 10,  0, 10, 30,  0,  0 },
        { 0, 10,  0, 12,  5,  0 },
        { 0, 30, 12,  0,  0, 20 },
        { 15,  0,  5,  0,  0, 0 },
        { 5,  0,  0, 20, 0,  0 }
    };

    for (int src = 0; src < max_n; src++) {
        cout << "Source city is " << cityNames[src] << endl;
        dijkstra(adj_mat, cityNames, src);
        cout << endl;
    }

    return 0;

}
