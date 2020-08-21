#include <iostream>

struct Node{
  int data;
  Node* next;
  Node(int d){data = d, next = NULL;}
};

struct Queue{
  Node *front, *rear;
  Queue() {front = rear = NULL;}

  void enqueue(int data){
    Node *temp = new Node(data);

    if (rear == NULL){front = rear = temp; return;}
    
    rear -> next = temp;
    rear = temp;
  }

  void dequeue(){
    if (front == NULL) return;
    
    Node *temp = front;
    front = front -> next;

    if (front == NULL) {rear = NULL;}
    delete(temp);
  }
};


int main() {
  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.dequeue();
  q.dequeue();
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);
  q.dequeue();

  std::cout << "Queue Front: " << (q.front) -> data << std::endl;
  std::cout << "Queue Rear: " << (q.rear) -> data;
}