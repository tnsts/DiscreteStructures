#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <limits.h>
#include "dijkstra.cpp"

using namespace std;

TEST_CASE("Cheaking"){

  int n = 8;
	int **w = new int*[n];

	for(int i=0; i<n; i++){
		w[i] = new int[n];
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			w[i][j] = INT_MAX;
		}
		w[i][i] = 0;
	}

	w[0][1] = 1;
	w[1][2] = 2;
	w[2][3] = 5;
	w[3][0] = 4;
	w[2][4] = 1;
  w[6][7] = 5;
  w[0][5] = 8;
  w[5][2] = 1;

	w[1][0] = 1;
	w[2][1] = 2;
	w[3][2] = 5;
	w[0][3] = 4;
	w[4][2] = 1;
  w[7][6] = 5;
  w[5][0] = 8;
  w[2][5] = 1;

  CHECK_THROWS(Dijkstra(w, n, -1, 4));
  CHECK_THROWS(Dijkstra(w, n, 1, 8));

  CHECK(Dijkstra(w, n, 5, 0)[0] == 4);
  CHECK(Dijkstra(w, n, 0, 6)[0] == INT_MAX);
  CHECK(Dijkstra(w, n, 1, 1)[0] == 0);
  CHECK(Dijkstra(w, n, 6, 7)[0] == 5);
  CHECK(Dijkstra(w, n, 4, 2)[0] == 1);
  CHECK(Dijkstra(w, n, 5, 1)[0] == 3);

  int *result1 = Dijkstra(w, n, 0, 4);
  CHECK(result1[0] == 4);
  CHECK(result1[1] == 2);
  CHECK(result1[2] == 1);
  CHECK(result1[3] == 0);

  int *result2 = Dijkstra(w, n, 3, 1);
  CHECK(result2[0] == 5);
  CHECK(result2[1] == 0);
  CHECK(result2[2] == 3);

}
