#include <iostream>
using namespace std;

class TicketQueue {
private:
    int queue[5];
    int front, rear;

public:
    TicketQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int ticketNumber) {
        if (rear == 4) {
            cout << "\nQueue Overflow! The ticket counter is full.\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        queue[rear] = ticketNumber;

        cout << "\nTicket Number " << ticketNumber << " inserted successfully.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "\nQueue Underflow! No customers to serve.\n";
            front = -1;
            rear = -1;
            return;
        }

        cout << "\nNow Serving Ticket Number: " << queue[front] << "\n";
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "\nQueue is Empty. No one is waiting.\n";
            return;
        }

        cout << "\nCustomers currently in Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    TicketQueue q;
    int choice;
    int ticketNumber;

    do {
        cout << "\n=================================";
        cout << "\n      TICKET COUNTER MENU";
        cout << "\n=================================";
        cout << "\n1. Enqueue (Add Customer)";
        cout << "\n2. Dequeue (Serve Customer)";
        cout << "\n3. Display (Show Line)";
        cout << "\n4. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Ticket Number: ";
                cin >> ticketNumber;
                q.enqueue(ticketNumber);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "\nProgram Terminated Successfully.\n";
                break;

            default:
                cout << "\nInvalid Choice! Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}