#include <iostream>

struct Node{
  int data;
  Node *next;
  Node *prev;
};


void insertbegin(Node **start, int new_data){
  Node *last = (*start) -> prev;
  Node *new_node = new Node();
  
  new_node -> data = new_data;
  new_node -> next = *start;
  new_node -> prev = last;
  last -> next = (*start) -> prev = new_node;
  *start = new_node;
}

void insertafter(Node **start, int x, int y){
  Node *new_node = new Node();
  Node *temp = *start;
  while (temp -> data != y) temp = temp -> next;
  Node *next = temp -> next;

  // Insert new_node between temp and next
  temp -> next = new_node;
  new_node -> prev = temp;
  new_node -> next = next;
  next -> prev = new_node;
}


void printlist(Node *start){
  Node *temp = start;
  while (temp -> next != start){
    std::cout << temp -> data;
    temp = temp -> next;
  }
  std::cout << temp -> data;
}


void insertend(struct Node **start, int new_data){
  if (*start == NULL){
    Node *new_node = new Node();
    new_node -> data = new_data;
    new_node -> next = new_node -> prev = new_node;
    *start = new_node;
    return;
  }
  // If List is not Empty
  Node *last = (*start) -> prev;
  Node *new_node = new Node();
  new_node -> data = new_data;
  new_node -> next = *start;
  (*start) -> prev = new_node;
  new_node -> prev = last;
  last -> next = new_node;
}


int main() {
  Node *start = NULL;
  insertend(&start, 5);
  insertbegin(&start, 4);
  insertend(&start, 7);
  insertend(&start, 8);
  insertafter(&start, 6, 5);

  printlist(start);

  return 0;
}