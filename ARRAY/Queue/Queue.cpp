#include "Queue.cpp"

// Driver Code
int main(void){
  // Create a queue of capacity 4
  Queue q(4);

  // print queue elements
  q.Display();

  // insert elements in the queue
  q.Enqueue(10);
  q.Enqueue(30);
  q.Enqueue(50);
  q.Enqueue(70);

  // Print Queue elements
  q.Display();

  // Insert Element in the Queue
  q.Enqueue(60);

  // Print Queue elements
  q.Display();

  // Remove two front nodes
  q.Dequeue();
  q.Dequeue();

  printf("\n\nAfter Removing 2 Nodes: \n");
  q.Display();

  // Print front of the queue
  q.Front();

  return 0;
}