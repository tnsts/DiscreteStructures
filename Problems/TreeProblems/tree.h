#include <iostream>
#include "help.cpp"
using namespace std;

class Tree {
  private:
    struct Node {
      int data;
      Node *parent;
      Node *left;
      Node *right;
    };
		int amount_of_elements;
    Node *root;

  public:
    Tree();
    ~Tree();
    void add_value(int data);
    void add_node(Node *current, Node *element);
    Node *search(int value);
    void delete_node(int data);
		int count_of_including();
		int data_of_left();
    int search_count(int E, Node* current);
		bool is_in_tree(int data);
		int get_amount_of_elements(){
			return amount_of_elements;
		}
    Node *get_root(){
      return root;
    }

    Tree* task1(Node* current, int n);
    Tree* task2(Node* current);
    Tree* task3(Node* current, int n);
    Tree* task4(Node* current, int n);
    Tree* task5(Node* current, int n, int* a);
    Tree* task6(Node* current);
    Tree* task7(Node* current);
    Tree* task8(Node* current, int x, int y);
    Tree* task9(Node* current, int n);
    Tree* task10(Node* current, int n);
    Tree* task11(Node* current, int x, int y);
    Tree* task12(Node* current);
};
