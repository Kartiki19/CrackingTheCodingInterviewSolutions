#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr){}
};

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* partition(Node* node, int k){
    Node* head = node;
    Node* tail = node;
    Node* next = nullptr;
    while(node != nullptr){
        next = node->next;
        if(node->data < k){
            node -> next = head;
            head = node;
        }else{
            tail -> next = node;
            tail = node;
        }
        node = next;
    }
    tail->next = nullptr;
    return head;
}


int main(){
    Node* head = new Node(9);
    head -> next = new Node(2);
    head -> next -> next = new Node(11);
    head -> next -> next -> next = new Node(5);
    head -> next -> next -> next -> next = new Node(5);
    head -> next -> next -> next -> next -> next = new Node(10);
    head -> next -> next -> next -> next -> next -> next = new Node(2);
    head -> next -> next -> next -> next -> next -> next = new Node(4);

    printLinkedList(head);

    int k = 5;

    head = partition(head, k);

    printLinkedList(head);
        
    return 0;
}