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

//problems

Tree* Tree::task1(Tree::Node* current, int n){
  static Tree* res = new Tree();

  if (current != nullptr){
    task1(current->left, n);
    if (!(current->data % n)){
      res->add_value(current->data);
    }
    task1(current->right, n);
  }

  return res;
}

Tree* Tree::task2(Tree::Node* current){
  static Tree* res = new Tree();

  if (current != nullptr){
    task2(current->left);
    if (current->data % 2){
      res->add_value(current->data);
    }
    task2(current->right);
  }

  return res;
}

Tree* Tree::task3(Tree::Node* current, int n){
  static Tree* res = new Tree();

  if (current != nullptr){
    task3(current->left, n);
    if (current->data > n){
      res->add_value(current->data);
    }
    task3(current->right, n);
  }

  return res;
}

Tree* Tree::task4(Tree::Node* current, int n){
  static Tree* res = new Tree();

  if (current != nullptr){
    task4(current->left, n);
    if (current->data < n){
      res->add_value(current->data);
    }
    task4(current->right, n);
  }

  return res;
}

Tree* Tree::task5(Tree::Node* current, int n, int* a){
  static Tree* res = new Tree();

  if (current != nullptr){
    task5(current->left, n, a);
    for(int i = 0; i < n; i++){
      if (current->data == a[i]){
        res->add_value(current->data);
      }
    }
    task5(current->right, n, a);
  }

  return res;
}

Tree* Tree::task6(Tree::Node* current){
  static Tree* res = new Tree();

  if (current != nullptr){
    task6(current->left);
    if (isSimple(current->data)){
      res->add_value(current->data);
    }
    task6(current->right);
  }

  return res;
}

Tree* Tree::task7(Tree::Node* current){
  static Tree* res = new Tree();

  if (current != nullptr){
    task7(current->left);
    if (!isSimple(current->data)){
      res->add_value(current->data);
    }
    task7(current->right);
  }

  return res;
}

Tree* Tree::task8(Tree::Node* current, int x, int y){
  static Tree* res = new Tree();

  if (current != nullptr){
    task8(current->left, x, y);
    if (current->data < y && current->data > x){
      res->add_value(current->data);
    }
    task8(current->right, x, y);
  }

  return res;
}

Tree* Tree::task9(Tree::Node* current, int n){
  static Tree* res = new Tree();

  if (current != nullptr){
    task9(current->left, n);
    if (number_sum(current->data) > n){
      res->add_value(current->data);
    }
    task9(current->right, n);
  }

  return res;
}

Tree* Tree::task10(Tree::Node* current, int n){
  static Tree* res = new Tree();

  if (current != nullptr){
    task10(current->left, n);
    if (number_sum(current->data) < n){
      res->add_value(current->data);
    }
    task10(current->right, n);
  }

  return res;
}

Tree* Tree::task11(Tree::Node* current, int x, int y){
  static Tree* res = new Tree();

  if (current != nullptr){
    task11(current->left, x, y);
    if (number_sum(current->data) < y && number_sum(current->data) > x){
      res->add_value(current->data);
    }
    task11(current->right, x, y);
  }

  return res;
}

Tree* Tree::task12(Tree::Node* current){
  static Tree* res = new Tree();

  if (current != nullptr){
    task12(current->left);
    if ((int)sqrt(abs(current->data)) == sqrt(abs(current->data))){
      res->add_value(current->data);
    }
    task12(current->right);
  }

  return res;
}
