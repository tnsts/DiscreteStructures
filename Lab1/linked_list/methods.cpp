#include "linked_list.h"

List::List():
	first(nullptr)
{}

List::~List() {
	Node* ptr = first;
	while(length()) {
		Node* nextptr = ptr->next;
		delete ptr;
		ptr = nextptr;
	}
}

int List::length(){

	int len = 0;

	Node* ptr = first;

	while(ptr != nullptr){
		len++;
		ptr = ptr->next;
	}

	return len;
}

List::Node* List::search_index(int n)
{
	if (n < 0){
		throw invalid_argument("can't search index < 0");
		return nullptr;
	}

	if (n >= length()){
		throw invalid_argument("can't search index > length");
		return nullptr;
	}

	Node* ptr = first;

	int counter = 0;
	while (ptr != nullptr){
		if(counter == n){
			return ptr;
		}
		else{
			ptr = ptr->next;
			counter++;
		}
	}
	return nullptr;
}

void List::remove(int index) {
	if (index < 0){
		throw invalid_argument("can't insert index < 0");
		return;
	}

	if (index >= length()){
		throw invalid_argument("out of range");
		return;
	}

   Node* element = search_index(index);
   Node* ptr = first;

   if (index == 0){
	   first = first->next;
   }
   else{
	   while(true){
		   if(ptr->next == element){
			   ptr->next = element->next;
			   break;
		   }
		   ptr = ptr->next;
	   }
	}
}

void List::insert(int data, int index)
{
	Node* element = (Node*)malloc(sizeof(Node));
	if (index < 0){
		throw invalid_argument("can't insert index < 0");
		return;
	}

	if (index > length()){
		throw invalid_argument("out of range");
		return;
	}

	element->n = data;
    element->next = nullptr;
	int counter = 0;

	Node* predptr = first;

	if (index == 0){
		element->next = first;
		first = element;
	} else
		if (index != length()){
		while (true){
			if (counter == index - 1){
				element->next = predptr->next;
				predptr->next = element;
                break;
			}
			predptr = predptr->next;
			counter++;
		}
	} else {
		while(true){
			if (predptr->next == nullptr){
				predptr->next = element;
				break;
			}
			predptr = predptr->next;
		}
	}
}

void List::push(int data){
	insert(data, length());
}

void List::show(){

	Node* ptr = first;

	while(ptr != nullptr){
		cout<< ptr->n <<endl;
		ptr = ptr->next;
	}
}

void List::move(int index, int n){

	if (index < 0 || index >= length()){
		throw invalid_argument("invalid index of element");
		return;
	}

	if (index + n >= length() || index + n < 0){
		throw invalid_argument("moving is impossible");
		return;
	}

	Node* element = search_index(index);
	Node* ptr = first;

	remove(index);
	insert(element->n, index + n);
}

List::Node* List::get_first(){
	return first;
}
