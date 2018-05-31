#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "methods.cpp"
#include "ctime"
#include "cmath"

using namespace std;

TEST_CASE("Task 1"){
	srand(time(0));

	Tree* tree = new Tree();
	int n = 3;
	int a[15];

  for(int i = 0; i < 15; i++){
		int temp = rand()%200-100;
		tree->add_value(temp);
		a[i] = temp;
	}

	Tree* res = tree->task1(tree->get_root(), n);

	for(int i = 0; i < 15; i++){
		if (a[i] % n == 0){
			CHECK(res->is_in_tree(a[i]));
		}
		else{
			CHECK(!res->is_in_tree(a[i]));
		}
	}
}

TEST_CASE("Task 2"){
	srand(time(0));

	Tree* tree = new Tree();
	int a[15];

  for(int i = 0; i < 15; i++){
		int temp = rand()%200-100;
		tree->add_value(temp);
		a[i] = temp;
	}

	Tree* res = tree->task2(tree->get_root());

	for(int i = 0; i < 15; i++){
		if (a[i] % 2){
			CHECK(res->is_in_tree(a[i]));
		}
		else{
			CHECK(!res->is_in_tree(a[i]));
		}
	}
}

TEST_CASE("Task 3"){
	srand(time(0));

	Tree* tree = new Tree();
	int n = 10;
	int a[15];

  for(int i = 0; i < 15; i++){
		int temp = rand()%200-100;
		tree->add_value(temp);
		a[i] = temp;
	}

Tree* res = tree->task3(tree->get_root(), n);

	for(int i = 0; i < 15; i++){
		if (a[i] > n){
			CHECK(res->is_in_tree(a[i]));
		}
		else{
			CHECK(!res->is_in_tree(a[i]));
		}
	}
}

TEST_CASE("Task 4"){
	srand(time(0));

	Tree* tree = new Tree();
	int n = 10;
	int a[15];

  for(int i = 0; i < 15; i++){
		int temp = rand()%200-100;
		tree->add_value(temp);
		a[i] = temp;
	}

	Tree* res = tree->task4(tree->get_root(), n);

	for(int i = 0; i < 15; i++){
		if (a[i] < n){
			CHECK(res->is_in_tree(a[i]));
		}
		else{
			CHECK(!res->is_in_tree(a[i]));
		}
	}
}

TEST_CASE("Task 5"){
	srand(time(0));

	Tree* tree = new Tree();
	int n;
	int a[15];

  for(int i = 0; i < 15; i++){
		int temp = rand()%200-100;
		tree->add_value(temp);
		a[i] = temp;
		cout << a[i] << " ";
	}
cout << endl;
cin >> n;
int *temp = new int[n];

for(int i = 0; i < n; i++){
	cin>>temp[i];
}

Tree* res = tree->task5(tree->get_root(), n, temp);

	for(int i = 0; i < n; i++){
			CHECK(res->is_in_tree(temp[i]));
		}
}

TEST_CASE("Task 6"){
	srand(time(0));

	Tree* tree = new Tree();
	int a[15];

  for(int i = 0; i < 15; i++){
		int temp = rand()%200-100;
		tree->add_value(temp);
		a[i] = temp;
	}

	Tree* res = tree->task6(tree->get_root());

	for(int i = 0; i < 15; i++){
		if (isSimple(a[i])){
			CHECK(res->is_in_tree(a[i]));
		}
		else{
			CHECK(!res->is_in_tree(a[i]));
		}
	}
}

TEST_CASE("Task 7"){
	srand(time(0));

	Tree* tree = new Tree();
	int a[15];

  for(int i = 0; i < 15; i++){
		int temp = rand()%200-100;
		tree->add_value(temp);
		a[i] = temp;
	}

	Tree* res = tree->task7(tree->get_root());

	for(int i = 0; i < 15; i++){
		if (!isSimple(a[i])){
			CHECK(res->is_in_tree(a[i]));
		}
		else{
			CHECK(!res->is_in_tree(a[i]));
		}
	}
}

TEST_CASE("Task 8"){
	srand(time(0));

	Tree* tree = new Tree();
	int x = 20;
	int y = -50;
	int a[15];

  for(int i = 0; i < 15; i++){
		int temp = rand()%200-100;
		tree->add_value(temp);
		a[i] = temp;
	}

	Tree* res = tree->task8(tree->get_root(), x, y);

	for(int i = 0; i < 15; i++){
		if (a[i] < y && a[i] > x){
			CHECK(res->is_in_tree(a[i]));
		}
		else{
			CHECK(!res->is_in_tree(a[i]));
		}
	}
}

TEST_CASE("Task 9"){
	srand(time(0));

	Tree* tree = new Tree();
	int n = 8;
	int a[15];

  for(int i = 0; i < 15; i++){
		int temp = rand()%200-100;
		tree->add_value(temp);
		a[i] = temp;
	}

Tree* res = tree->task9(tree->get_root(), n);

	for(int i = 0; i < 15; i++){
		if (number_sum(a[i]) > n){
			CHECK(res->is_in_tree(a[i]));
		}
		else{
			CHECK(!res->is_in_tree(a[i]));
		}
	}
}

TEST_CASE("Task 10"){
	srand(time(0));

	Tree* tree = new Tree();
	int n = 11;
	int a[15];

  for(int i = 0; i < 15; i++){
		int temp = rand()%200-100;
		tree->add_value(temp);
		a[i] = temp;
	}

	Tree* res = tree->task10(tree->get_root(), n);

	for(int i = 0; i < 15; i++){
		if (number_sum(a[i]) < n){
			CHECK(res->is_in_tree(a[i]));
		}
		else{
			CHECK(!res->is_in_tree(a[i]));
		}
	}
}

TEST_CASE("Task 11"){
	srand(time(0));

	Tree* tree = new Tree();
	int x = 2;
	int y = 9;
	int a[15];

  for(int i = 0; i < 15; i++){
		int temp = rand()%200-100;
		tree->add_value(temp);
		a[i] = temp;
	}

	Tree* res = tree->task11(tree->get_root(), x, y);

	for(int i = 0; i < 15; i++){
		if (number_sum(a[i]) < y && number_sum(a[i]) > x){
			CHECK(res->is_in_tree(a[i]));
		}
		else{
			CHECK(!res->is_in_tree(a[i]));
		}
	}
}

TEST_CASE("Task 12"){
	srand(time(0));

	Tree* tree = new Tree();
	int a[15];

  for(int i = 0; i < 15; i++){
		int temp = rand()%200-100;
		tree->add_value(temp);
		a[i] = temp;
	}

	Tree* res = tree->task12(tree->get_root());

	for(int i = 0; i < 15; i++){
		if ((int)sqrt(abs(a[i])) == sqrt(abs(a[i]))){
			CHECK(res->is_in_tree(a[i]));
		}
		else{
			CHECK(!res->is_in_tree(a[i]));
		}
	}
}
