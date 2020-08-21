#include <iostream>
#define MAX 1000

struct Stack{
  int a[MAX];

  Stack(){top = -1;}

  bool push(int x){
    if (top >= MAX - 1) return false;
    else {
      a[++top] = x;
      std::cout << x << " Pushed into stack" << std::endl;
      return true;
    }
  }

  int pop(){
    if (top < 0) return 0;
    else return a[top--];
  }

  int peek(){
    if (top < 0) return 0;
    else return a[top];
  }

  bool isEmpty(){return (top < 0);}

private:
  int top;
};

int main() {
  class Stack s;
  std::cout << "Pushing into the Stack:" << std::endl;
  std::cout << "-----------------------" << std::endl;
  s.push(10);
  s.push(30);
  s.push(50);
  s.push(70);
  s.push(90);

  std::cout << std::endl << std::endl;

  std::cout << "Popping from the Stack:" << std::endl;
  std::cout << "-----------------------" << std::endl;
  while (!s.isEmpty()){
    std::cout << s.pop() << " Popped from stack" << std::endl;
  }

  return 0;
}