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

int findKthLastElementRecursive(Node* head, int k){
    if(head == nullptr) return 0;
    int id = findKthLastElementRecursive(head->next, k) + 1;
    if(id == k){
        cout << k << "th last element is: " << head->data << endl;
    }
    return id; 
}

int findKthLastElementIterative(Node* head, int k){
    Node* first = head;
    Node* second = head;

    for(int i = 0; i < k-1; ++i){
        if(second->next == nullptr) return -1;
        second = second -> next;
    }

    while(second->next != nullptr){
        first = first->next;
        second = second->next;
    }
    return first->data;
}

int main(){
    Node* head = new Node(9);
    head -> next = new Node(2);
    head -> next -> next = new Node(11);
    head -> next -> next -> next = new Node(10);
    head -> next -> next -> next -> next = new Node(8);
    head -> next -> next -> next -> next -> next = new Node(12);
    head -> next -> next -> next -> next -> next -> next = new Node(6);

    printLinkedList(head);

    int k = 1;

    /// TC = O(n) | SC = O(n)
    findKthLastElementRecursive(head, k);

    /// TC = O(n) | SC = O(1)
    cout << k << "th last element using iterative is: " << findKthLastElementIterative(head, k) << endl;
    return 0;
}