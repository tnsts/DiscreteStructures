#include <iostream>
#include <limits.h>
using namespace std;

int *Dijkstra(int **a, int n, int from, int to){

  if (from < 0 || to < 0 || from >= n || to >= n){
    throw invalid_argument("imposible top");
  }

    bool *visited = new bool[n];
    int *length = new int[n];
    int *result_way = new int[n];

    for(int i = 0; i < n; i++){
        length[i] = a[from][i];
        visited[i] = false;
		    result_way[i] = INT_MAX;
    }

    length[from] = 0;

    int current = 0, p = 0, k = 1;   // p - the last top, which get the permanent mark

    for (int i = 0; i < n; i++){
      int min = INT_MAX;
      for (int j = 0; j < n; j++){
        if (!visited[j] && length[j] < min){
          min = length[j];
          current = j;
        }
      }

        p = current;
        visited[p] = true;

        for(int j = 0; j < n; j++){
			if (!visited[j] && a[p][j] != INT_MAX && length[p] != INT_MAX){
				if (length[p] + a[p][j] < length[j]){
					length[j] = length[p] + a[p][j];
				}
            }
        }
    }

	result_way[0] = length[to];

	int current_end = to;
	int weight = length[current_end];
  k = 1;

	while (current_end != from){
		for(int i = 0; i < n; i++){
			if (a[current_end][i] != 0 && weight - a[current_end][i] >= 0){
				int temp = weight - a[current_end][i];
				if (temp == length[i]){
					weight = temp;
					current_end = i;
					result_way[k] = i;
					k++;
				}
			}
		}
	}

	result_way[k] = from;

	return result_way;

}
