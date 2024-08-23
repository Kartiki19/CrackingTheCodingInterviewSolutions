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

bool deleteGivenNode(Node* node){
    if(node == nullptr || node->next == nullptr) return false;

    Node* next = node -> next;
    node->data = next->data;
    node->next = next->next;
    return true;
}
int main(){
    Node* head = new Node(9);
    head -> next = new Node(2);
    head -> next -> next = new Node(11);
    head -> next -> next -> next = new Node(10);
    head -> next -> next -> next -> next = new Node(8);
    head -> next -> next -> next -> next -> next = new Node(12);
    head -> next -> next -> next -> next -> next -> next = new Node(6);

    Node* nodeToBeDeleted =  head;

    printLinkedList(head);

    if(deleteGivenNode(nodeToBeDeleted))
        printLinkedList(head);
    else 
        cout << "\nThis is a last node, which can not be deleted !" << endl;
    
    return 0;
}