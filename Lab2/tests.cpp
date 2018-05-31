#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "methods.cpp"

using namespace std;

TEST_CASE("Checking the adding an element"){
	Tree* tree = new Tree();

	tree->add_value(7);
	tree->add_value(2);
	tree->add_value(9);
	tree->add_value(1);
	tree->add_value(4);
	tree->add_value(8);
	tree->add_value(10);
	tree->add_value(3);

	REQUIRE(tree->get_amount_of_elements() == 8);

  CHECK(tree->is_in_tree(7));
	CHECK(tree->is_in_tree(2));
	CHECK(tree->is_in_tree(9));
	CHECK(tree->is_in_tree(1));
	CHECK(tree->is_in_tree(4));
	CHECK(tree->is_in_tree(8));
	CHECK(tree->is_in_tree(10));
	CHECK(tree->is_in_tree(3));
}

TEST_CASE("Cheacking the search"){
	Tree* tree = new Tree();

	tree->add_value(7);
	tree->add_value(2);
	tree->add_value(9);
	tree->add_value(1);
	tree->add_value(4);
	tree->add_value(8);
	tree->add_value(10);
	tree->add_value(3);

	CHECK(tree->is_in_tree(4));
	CHECK(tree->is_in_tree(8));
	CHECK(tree->is_in_tree(10));
	CHECK(!tree->is_in_tree(-2));
	CHECK(!tree->is_in_tree(0));
	CHECK(!tree->is_in_tree(16));
}

TEST_CASE("Cheacking the removing"){
	Tree* tree = new Tree();

	CHECK_THROWS(tree->delete_node(0));

	tree->add_value(7);
	tree->add_value(2);
	tree->add_value(9);
	tree->add_value(1);
	tree->add_value(4);
	tree->add_value(8);
	tree->add_value(10);
	tree->add_value(3);

	CHECK_THROWS(tree->delete_node(-2));

	tree->delete_node(1);
	CHECK(!tree->is_in_tree(1));
	tree->delete_node(4);
	CHECK(!tree->is_in_tree(4));
	CHECK(tree->is_in_tree(3));
	tree->delete_node(9);
	CHECK(!tree->is_in_tree(9));
	CHECK(tree->is_in_tree(8));
	CHECK(tree->is_in_tree(10));
	tree->delete_node(7);
	CHECK(!tree->is_in_tree(7));
	CHECK(tree->is_in_tree(2));
	CHECK(tree->is_in_tree(10));
}

TEST_CASE("Cheacking number of including"){
	Tree* tree = new Tree();

	tree->add_value(7);
	tree->add_value(6);
	tree->add_value(4);
	tree->add_value(4);
	tree->add_value(5);
	tree->add_value(4);
	tree->add_value(8);

	CHECK(tree->count_of_including() == 3);
}
