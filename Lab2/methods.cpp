#include "tree.h"

using namespace std;

Tree::Tree():
  root(nullptr),
  amount_of_elements(0)
{}

Tree::~Tree() {
  delete root;
  root = nullptr;
}

void Tree::add_node(Node *current, Node *element) {
  if (root == nullptr) {
    root = element;
    return;
  }

  if (element->data < current->data) {
		if (current->left == nullptr) {
      element->parent = current;
			current->left = element;
			return;
		} else {
			add_node(current->left, element);
		}
  } else {
		if (current->right == nullptr) {
      element->parent = current;
      current->right = element;
      return;
    } else {
      add_node(current->right, element);
    }
  }
}

void Tree::add_value(int data) {
  Node* element = (Node*)malloc(sizeof(Node));
  element->data = data;
	element->left = nullptr;
	element->right = nullptr;
  amount_of_elements++;
  this->add_node(root, element);
}

Tree::Node* Tree::search(int value) {
  Node *current = root;

  while (current) {
    if (current->data == value) {
      return current;
    } else {
			if (current->data < value){
				current = current->right;
			} else {
				current = current->left;
			}
		}
  }

  return nullptr;
}

void Tree::delete_node(int value) {
  if (root == nullptr) {
    throw logic_error("tree is empty");
  }

  Node *element = search(value);

  if (element == nullptr) {
    throw out_of_range("needed element not founded");
  }

  amount_of_elements--;

  if (element == root){
    if (element->left && element->right){
      root = element->right;
      add_node(root, element->left);
    } else {
      if (element->right){
        root = element->right;
      }
      else root = element->left;
    }

    delete element;
    return;
  }

	if (!element->right && !element->left){
		if(element->parent->right == element){
			element->parent->right = nullptr;
		}
		else element->parent->left = nullptr;
	}

	if (element->right && !element->left){
		if (element->parent->right == element){
			element->parent->right = element->right;
		}
		else{
			element->parent->left = element->right;
		}
	}

	if (element->left && !element->right){
		if (element->parent->right == element){
			element->parent->right = element->left;
		}
		else{
			element->parent->left = element->left;
		}
	}

  if (element->left && element->right) {
    element->right->parent = element->parent;

		if (element->parent->right == element){
			element->parent->right = element->right;
		}
		else{
			element->parent->left = element->right;
		}

    add_node(root, element->left);
  }

	delete element;
	return;
}

int Tree::count_of_including(){
	int E = data_of_left();
	return search_count(E, get_root());
}

int Tree::search_count(int E, Node* current){
  static int counter = 0;

  if (current != nullptr){
    search_count(E, current->left);
    if (current->data == E)counter++;
    search_count(E, current->right);
  }

  return counter;
}

int Tree::data_of_left(){
	Node* current = root;

	while(current->left){
		current = current->left;
	}

	return current->data;
}

bool Tree::is_in_tree(int data) {
      if (search(data) != nullptr)return true;
      else return false;
}
