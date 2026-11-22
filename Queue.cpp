//Name:Prachi Solanki
//Roll no:35
//SY8
//ASSIGNMENT NO:2


#include <iostream>
using namespace std;

class Queue
{
private:
    int queue[5];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    // Insert element into queue
    void insert(int value)
    {
        if (rear == 4)
        {
            cout << "Queue is Full!" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        cout << "Element Inserted Successfully." << endl;
    }

    // Display queue elements
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "\nQueue Elements are: ";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue obj;
    int value;

    for (int i = 1; i <= 5; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> value;
        obj.insert(value);
    }

    obj.display();

    return 0;
}