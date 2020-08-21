// C++ program to implement a queue using an array
#include <iostream>

using namespace std;

// FIFO Queue
struct Queue{
  int front, rear, capacity;
  int *queue;


  Queue(int c){
    front = rear = 0;
    capacity = c;
    queue = new int;
  }


  ~Queue(){ delete[] queue; }


  // First In
  void Enqueue(int data){
    // Is Queue Full? -> Can't add over capcity
    if (capacity == rear){
      printf("\nQueue is Full -> Cannot Add Node\n");
      return;
    }

    // Enqueue -> add to Queue
    else{
      queue[rear] = data;
      rear++;
    }
    return;
  }


  // First Out
  void Dequeue(){
    // Is Queue Empty? -> Can't remove a node if none exist
    if (front == rear){
      printf("\nQueue is Empty -> Cannot Remove Node\n");
      return;
    }

    // Shift Elements Right by One
    else{
      for (int i = 0; i < rear - 1; i++){
        queue[i] = queue[i + 1];
      }
      rear--; // Decrement Rear
    }
    return;
  }

  // Displays Queue
  void Display(){
    // Is Queue Empty? -> Can't print anything if the queue is empty
    if (front == rear){
      printf("\nQueue is Empty -> Cannot Display\n");
      return;
    }

    // Print Queue Node Traversal
    for (int i = 0; i < rear; i++){
      printf("  <--  %d", queue[i]);
    }
    return;
  }


  // Returns First Element
  void Front(){
    // Is Queue Empty? -> Can't return a first element if none exist
    if (front == rear){
      printf("\nQueue is Empty -> Cannot Return Front Element\n");
      return;
    }

    // Prints First Element of Queue
    printf("\nFront Element of Queue: %d", queue[front]);
    return;
  }

};