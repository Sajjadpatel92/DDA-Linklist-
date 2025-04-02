#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* next;

    Node(int val) {  
        data = val;
        next = nullptr;
    }
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = nullptr; } 


    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void append(int data) {
        Node* newNode = new Node(data);

        if (!head) { 
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newNode; 
    }

   
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev; 
            prev = current; 
            current = next; 
        }

        head = prev; 
    }

  
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

   
    void deleteNode(int value) {
        if (!head) return; 

        if (head->data == value) { 
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next) { 
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
};


int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Append Node\n";
        cout << "2. Display List\n";
        cout << "3. Reverse List\n";
        cout << "4. Delete Node\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to append: ";
                cin >> value;
                list.append(value);
                break;
            case 2:
                cout << "Linked List: ";
                list.display();
                break;
            case 3:
                list.reverse();
                cout << "Linked List reversed!\n";
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                cout << "Node deleted (if found).\n";
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}