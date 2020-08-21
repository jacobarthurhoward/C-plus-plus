#include <iostream>
#include <string>
#include <queue>


struct LNode{ // List Node
  int data;
  LNode * next;
};


struct BTNode{ // Binary Tree Node
  int data;
  BTNode *left, *right;
};


void push(LNode **head_ref, int new_data){
  LNode* new_node = new LNode;
  new_node -> data = new_data;

  new_node -> next = (*head_ref);

  (*head_ref) = new_node;
}


BTNode* newBinaryTreeNode(int new_data){
  BTNode* temp = new BTNode();
  temp -> data = new_data;
  temp -> left = temp -> right = NULL;
  return temp;
}


void convertList2Binary(LNode *head, BTNode* &root){
  std::queue<BTNode*> q;
  
  if (head == NULL) root = NULL; return;
  
  root = newBinaryTreeNode(head -> data);
  q.push(root);
  head = head -> next;
  while (head){
    BTNode *parent = q.front();
    q.pop();

    BTNode *leftchild = NULL, *rightchild = NULL;
    leftchild = newBinaryTreeNode(head -> data);
    q.push(leftchild);
    head = head -> next;
    if (head){
      rightchild = newBinaryTreeNode(head -> data);
      q.push(rightchild);
      head = head -> next;
    }

    parent -> left = leftchild;
    parent -> right = rightchild;
  }
}


void inordertraversal(BTNode *root){
  if (root){
    inordertraversal(root -> left);
    std::cout << root -> data << " ";
    inordertraversal(root -> right);
  }
}


int main() {
  LNode *head = NULL;
  push(&head, 36);    // Last Node of Linked List
  push(&head, 30);
  push(&head, 25);
  push(&head, 15);
  push(&head, 12);
  push(&head, 10);    // First Node of Linked List

  BTNode *root;
  convertList2Binary(head, root);

  inordertraversal(root);

  return 0;
}