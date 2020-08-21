#include <iostream>

struct Node{
  int data;
  Node *left, *right;
  Node (int data){this -> data = data; left = right = NULL;}
};

void printinorder(struct Node *node){
  if (node == NULL) return;
  printinorder(node->left);
  std::cout << node -> data << " ";
  printinorder(node -> right);
}

int main() {
  Node *root = new Node(1);
  root -> left = new Node(2);
  root -> right = new Node(3);
  root -> left -> left = new Node(4);
  root -> left -> right = new Node(5);
  printinorder(root);

  return 0;
}