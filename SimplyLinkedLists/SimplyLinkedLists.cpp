// SimplyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;

template <typename E>
class MySimpleList {
private:
    struct Node {
        E data;
        struct Node* next;
        Node(E h) : data(h), next(NULL) {}
    };
    struct Node* head;

public:
    MySimpleList() : head(NULL) {}

    void insertFront(E element) {
        Node* newNode = new Node(element);
        newNode->next = head;
        head = newNode;
    }

    void removeRear()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void empty()
    {
        while (head != NULL)
        {
            removeRear();
        }
        cout << "Linked List is emptied!";
    }

    int sizeOf()
    {
        int size = 0;
        if (head == NULL)
        {
            return size;
        }
        Node* temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }

    void print() const {
        Node* print = head;
        while (print != NULL) {
            cout << print->data << " ";
            print = print->next;
        }
        cout << endl;
    }
};


int main()
{
    MySimpleList<string> mylist;
    mylist.insertFront("Jane");
    mylist.insertFront("John");
    mylist.insertFront("Kim");
    mylist.print();

    mylist.removeRear();
    mylist.print();
    cout << "Size of List: " << mylist.sizeOf();
    cout << "\nEmptying List... \n";
    mylist.empty();
    cout << "\nSize of List: " << mylist.sizeOf();
}