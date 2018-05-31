#include <iostream>

using namespace std;

class Tree {
  private:
    struct Node {
      double data;
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
};
