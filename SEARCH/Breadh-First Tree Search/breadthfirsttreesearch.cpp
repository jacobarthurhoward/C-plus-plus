// Recursive CPP program for level order traversal of Binary Tree
#include <iostream>
using namespace std;

/* A binary tree node has data,
pointer to left child
and pointer to the right child*/
struct Node{
  int data;
  Node *LEFT, *RIGHT;
};


// Helper Function that allocates a new node
// with the given data and NULL left and right pointers.
Node *newNode(int data){
  Node *Node = new struct Node();
  Node -> data  = data;
  Node -> LEFT  = NULL;
  Node -> RIGHT = NULL;
  return Node;
}


int height(Node *node){
  if (node == NULL)
    return 0;
  else{
    // Compute the height of each subtree
    int lheight = height(node -> LEFT);
    int rheight = height(node -> RIGHT);

    // User the Larger One
    if (lheight > rheight) return lheight + 1;
    else return rheight + 1;
  }
}

// Prints Nodes at a given level
void printGivenLevel(Node *root, int level){
  if (root == NULL) return;
  if (level == 1) cout << root -> data << " ";
  else if (level > 1){
    printGivenLevel(root-> LEFT,  level-1);
    printGivenLevel(root-> RIGHT, level-1);
  }
}

// Prints Level Order Traversal of a Tree
void printLevelOrder(Node *root){
  int h = height(root);
  for (int i = 1; i <= h; i++) printGivenLevel(root, i);
}

int main() {
  Node *root = newNode(1);
  root -> LEFT = newNode(2);
  root -> RIGHT = newNode(3);
  root -> LEFT -> LEFT = newNode(4);
  root -> LEFT -> RIGHT = newNode(5);

  cout << "Level Order Traversal of Binary Tree is \n";
  printLevelOrder(root);
  
  return 0;
}