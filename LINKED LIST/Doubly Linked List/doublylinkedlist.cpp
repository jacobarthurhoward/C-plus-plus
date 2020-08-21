#include <iostream>

struct Node{
  int data;
  Node *next;
  Node *prev;
};


void new_head(Node **head_ref, int new_data){
  Node *new_node = new Node();
  new_node -> data = new_data;

  new_node -> next = (*head_ref);
  new_node -> prev = NULL;

  if ((*head_ref) != NULL) (*head_ref) -> prev = new_node;
  (*head_ref) = new_node;
}


void new_tail(Node **head_ref, int new_data){
  Node *new_node = new Node();
  Node *last = *head_ref;

  new_node -> data = new_data;
  new_node -> next = NULL;

  if (*head_ref == NULL){ new_node -> prev = NULL; *head_ref = new_node; return;}
  while(last -> next != NULL) last = last -> next;

  last -> next = new_node;
  new_node -> prev = last;
}


void insert_node_before(Node **head_ref, Node *next_node, int new_data){
  if (next_node == NULL) return;
  Node *new_node = new Node();

  new_node -> data = new_data;
  new_node -> prev = next_node -> prev;
  next_node -> prev = new_node;
  new_node -> next = next_node;

  if (new_node -> prev != NULL) new_node -> prev -> next = new_node;
  else (*head_ref) = new_node;
}


void insert_node_after(Node *prev_node, int new_data){
  if (prev_node == NULL) return;
  Node *new_node = new Node();

  new_node -> data = new_data;
  new_node -> next = prev_node -> next;
  prev_node -> next = new_node;
  new_node -> prev = prev_node;

  if (new_node -> next != NULL) new_node -> next -> prev = new_node;
}


void printlist(Node *node){
  while (node != NULL){
    std::cout << node->data <<  " ";
    node = node-> next;
  }
}


int main() {
  Node *head = NULL;
  new_tail(&head, 6);
  new_head(&head, 7);
  new_head(&head, 1);
  new_tail(&head, 4);
  insert_node_after(head->next, 8);
  insert_node_before(&head, head->next->next, 2);

  printlist(head);
  return 0;
}