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

Node* findCycleStart(Node* head){
    Node* fast = head;
    Node* slow = head;

    while(fast != nullptr && fast -> next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) break;
    }

    if(fast == nullptr || fast -> next == nullptr) return nullptr;

    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}
int main(){
    Node* L1 = new Node(1);
    L1 -> next = new Node(2);
    L1 -> next -> next = new Node(3);
    L1 -> next -> next -> next = new Node(4);
    L1 -> next -> next -> next -> next = new Node(5);
    L1 -> next -> next -> next -> next -> next = new Node(6);
    L1 -> next -> next -> next -> next -> next -> next = new Node(7);
    L1 -> next -> next -> next -> next -> next -> next -> next = new Node(8);
    L1 -> next -> next -> next -> next -> next -> next -> next-> next = L1 -> next -> next -> next -> next;

    Node* cycleStart = findCycleStart(L1);
    cout << cycleStart->data;

    return 0;
}