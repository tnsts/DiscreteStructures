#include <stdexcept>
#include <iostream>

using namespace std;

class  List
{
private:
	typedef struct Node
	{
		int n;
		struct Node* next;
	} Node;

	Node* first;
public:
	List();
	int length();
	List::Node* search_index(int n);
	void remove(int index);
	void insert(int data, int index);
	void push(int data);
	void show();
	void move(int index, int n);
	List::Node* get_first();

	~ List();

	class Iterator {
      private:
        const List *l;
        Node *current;
        int index;
      public:
        Iterator(const List *s): l(s), index(0) {
          current = l->first;
        }
        Iterator(const List *s, int size): l(s), index(size) {
          current = l->first;
          for (int i = 0; i < size; i++) {
            current = current->next;
          }
        }
        void operator ++() {
          current = current->next;
          index++;
        }
        bool operator !=(const Iterator& other) {
          return index != other.index;
        }
        bool operator ==(const Iterator& other) {
          return index == other.index;
        }
        int operator *() {
          if (current) {
            return current->n;
          }
        }
      };
      Iterator begin() {
        Iterator it(this);
        return it;
      }
      Iterator end() {
        Iterator it(this, this->length() - 1);
        return it;
}
};
