#include <iostream>
using namespace std;

int queue[100];
int n = 100;
int front = -1;
int rear = -1;

void enqueue()
{
  int val;
  if (rear == n - 1)
  {
    cout << "Queue is full" << endl;
  }
  else
  {
    if (front == -1)
    {
      front = 0;
      cout << "Insert the element in queue: " << endl;
      cin >> val;
      rear++;
      queue[rear] = val;
    }
  }
}

void dequeue()
{
  if (front == rear || front > rear)
  {
    cout << "Queue is empty" << endl;
    return;
  }
  cout << "Element deleted from queue is: " << queue[front] << endl;
  front++;
}

void display()
{
  if (front == -1)
  {
    cout << "Queue is empty " << endl;
  }
  else
  {
    cout << "Queue elements are: ";
    for (int i = front; i <= rear; i++)
    {
      cout << queue[i] << " ";
      cout << endl;
    }
  }
}

void readFront()
{
  if (front == -1)
  {
    cout << "Queue underflow" << endl;
    return;
  }
  cout << "Element at front is: " << queue[front] << endl;
}

int main()
{
  int choice;
  cout << "1. Insert element to queue" << endl;
  cout << "2. Delete element from queue" << endl;
  cout << "3. Display all the elements of the queue" << endl;
  cout << "4. Read element fromm the queue" << endl;
  cout << "5. Exit" << endl;

  do
  {
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    case 4:
      readFront();
      break;
    case 5:
      cout << "Exited the queue" << endl;
      break;
    default:
      cout << "Invalid Operation" << endl;
    }
  }
  while (choice > 0 && choice < 5);
  return 0;
}