#include <iostream>
#include <limits>

using namespace std;

const int cities = 6;

int* dijkstra(int arr[cities][cities], int start)
{
    int* shortest_distance = new int[cities];
    bool visited[cities];

    for (int i = 0; i < cities; ++i) {
        shortest_distance[i] = numeric_limits<int>::max();
        visited[i] = false;
    }

    shortest_distance[start] = 0;

    for (int count = 0; count < cities - 1; ++count) {
        int min_distance = numeric_limits<int>::max();
        int min_index = -1;

        for (int i = 0; i < cities; ++i) {
            if (!visited[i] && shortest_distance[i] <= min_distance) {
                min_distance = shortest_distance[i];
                min_index = i;
            }
        }

        visited[min_index] = true;

        for (int i = 0; i < cities; ++i) {
            if (!visited[i] && arr[min_index][i] && shortest_distance[min_index] != numeric_limits<int>::max() &&
                shortest_distance[min_index] + arr[min_index][i] < shortest_distance[i]) {
                shortest_distance[i] = shortest_distance[min_index] + arr[min_index][i];
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < cities; ++i) {
        cout << "Node " << i << ": " << shortest_distance[i] << endl;
    }
    return shortest_distance;
}

int main()
{
    int adjacency_matrix[cities][cities] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };
    double sums[cities] = {0};
    for (int i=0; i<cities; i++){
        int start_node = i;
        int* arr = dijkstra(adjacency_matrix, start_node);

        for (int j=0; j<cities; j++){
            sums[j] += arr[j];
        }
        delete[] arr;
    }
    for (int i=0; i<cities; i++){
        cout << "City-" << i << "  Average = " << sums[i]/9 <<endl;
    }

    return 0;
}
