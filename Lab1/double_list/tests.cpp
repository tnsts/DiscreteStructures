#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "d_methods.cpp"

using namespace std;

TEST_CASE("Checking the push"){
	List* list = new List();

	for (int i = 0; i < 10; i++){
		list->push(i);
	}

	CHECK(list->get_first()->n == 0);
	CHECK(list->get_first()->next->n == 1);
	CHECK(list->get_first()->next->next->n == 2);
}

TEST_CASE("Checking the length"){
	List* list = new List();

  CHECK(list->length() == 0);

	for (int i = 0; i < 10; i++){
		list->push(i);
	}

	CHECK(list->length() == 10);
}

TEST_CASE("Checking the searching"){
	List* list = new List();

	for (int i = 0; i < 10; i++){
		list->push(i);
	}

	CHECK(list->search_index(0)->n == 0);
	CHECK(list->search_index(8)->n == 8);

	CHECK_THROWS(list->search_index(12));
	CHECK_THROWS(list->search_index(-1));
}

TEST_CASE("Checking the insert"){
	List* list = new List();

	for (int i = 0; i < 10; i++){
		list->push(i);
	}

	list->insert(10, 0);
	CHECK(list->search_index(0)->n == 10);
	CHECK(list->search_index(1)->n == 0);

	list->insert(23, 3);
	CHECK(list->search_index(3)->n == 23);
	CHECK(list->search_index(2)->n == 1);

	list->insert(16, list->length());
	CHECK(list->search_index(list->length()-1)->n == 16);
	CHECK(list->search_index(list->length()-2)->n == 9);

	CHECK_THROWS(list->insert(45, -2));
	CHECK_THROWS(list->insert(-61, list->length()+3));
}

TEST_CASE("Checking the removing"){
	List* list = new List();

	for (int i = 0; i < 10; i++){
		list->push(i);
	}

	list->remove(0);
	CHECK(list->search_index(0)->n == 1);
	CHECK(list->length() == 9);

	list->remove(3);
	CHECK(list->search_index(3)->n == 5);
	CHECK(list->length() == 8);

	list->remove(list->length()-1);
	CHECK(list->length() == 7);

	CHECK_THROWS(list->remove(-1));
	CHECK_THROWS(list->remove(list->length()+2));
}

TEST_CASE("Checking the moving"){
	List* list = new List();

	for (int i = 0; i < 10; i++){
		list->push(i);
	}

	list->move(0, 3);
	CHECK(list->search_index(3)->n == 0);
	CHECK(list->search_index(0)->n == 1);

	list->move(2, 6);
	CHECK(list->search_index(8)->n == 3);
	CHECK(list->search_index(2)->n == 0);

	list->move(5, 0);
	CHECK(list->search_index(5)->n == 6);

	list->move(9, -1);
	CHECK(list->search_index(8)->n == 9);
	CHECK(list->search_index(9)->n == 3);

	CHECK_THROWS(list->move(4, 8));
	CHECK_THROWS(list->move(4, -6));
	CHECK_THROWS(list->move(-1, 2));
}

TEST_CASE("Cheaking the iterator") {
  List *list = new List();

	for (int i = 0; i < 3; i++){
		list->push(i);
	}

	List::Iterator temp(list);
  ++temp;
  CHECK(*temp == 1);
  --temp;
  CHECK(*temp == *list->begin());
  CHECK(*temp != *list->end());
  List::Iterator temp1(list, 1);
  CHECK(*temp1 == 1);
}
