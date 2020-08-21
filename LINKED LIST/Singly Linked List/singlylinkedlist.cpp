#include <iostream>


struct Node{
  int data;
  Node *next;
};


// Make Node New Head Node
void new_head(Node **head_ref, int new_data){
  Node *new_node = new Node();
  new_node -> data = new_data;
  new_node -> next = (*head_ref);
  (*head_ref) = new_node;
}


// Make Node New Tail Node
void new_tail(struct Node** head_ref, int new_data){
  Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  Node *last = *head_ref;
  new_node -> data = new_data;
  new_node -> next = NULL;
  if (*head_ref == NULL){ *head_ref = new_node; return;}
  while (last -> next != NULL) last = last -> next;
  last -> next = new_node;
  return;
}


void printlist(Node *node){
  while (node != NULL){
    std::cout << " " << node -> data;
    node = node -> next;
  }
}


int main() {
  Node *head = NULL;
  new_tail(&head, 6); // 6
  new_head(&head, 7); // 7 6
  new_head(&head, 1); // 1 7 6
  new_tail(&head, 4); // 1 7 6 4

  printlist(head);
  
  return 0;
}