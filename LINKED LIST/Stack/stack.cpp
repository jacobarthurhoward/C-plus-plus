#include <iostream>

struct Node{
  int data;
  Node *link;
};

Node* top;

void push(int data){
  Node *temp = new Node();
  if (!temp){std::cout << "\nHeap Overflow"; exit(1);}
  temp -> data = data;
  temp -> link = top;
  top = temp;
}

int isempty(){return top == NULL;}
int peek(){
  if (!isempty()) return top -> data;
  else exit(1);
}

void pop(){
  Node *temp;
  if (top == NULL){
    std::cout << "Stack Underflow"; exit(1);
  }
  else{
    temp = top;
    top = top -> link;
    temp -> link = NULL;
    free(temp);
  }
}

void printstack(){
  Node *temp;
  if (top == NULL){
    std::cout << "\nStack Underflow"; 
    exit(1);
  }
  else{
    temp = top;
    while (temp != NULL){
      std::cout << temp -> data << " ";
      temp = temp -> link;
    }
  }
}

int main() {
  push(11);
  push(22);
  push(33);
  push(44);

  printstack();

  std::cout << "\nTop element is:" <<  peek(); 

  pop();
  pop();

  printstack();

  std::cout << "\nTop element is:" <<  peek(); 

  return 0;
}