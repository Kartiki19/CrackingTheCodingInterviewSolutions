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

Node* LinkedListSumIterative(Node* L1, Node* L2){
    if(L1 == nullptr) return L2;
    if(L2 == nullptr) return L1;

    Node* head = nullptr;
    Node* curr = head;
    int carry = 0;
    int sum = 0;

    while(L1 != nullptr || L2 != nullptr || carry > 0){
        sum = carry;
        if(L1 != nullptr) sum += L1-> data;
        if(L2 != nullptr) sum += L2-> data;

        if(sum >= 10){
            carry = sum / 10;
            sum %= 10;
        }
        else carry = 0;

        if(head == nullptr){
            head = new Node(sum);
            curr = head;
        }
        else{
            curr->next = new Node(sum);
            curr = curr->next;
        }
        if(L1 != nullptr) L1 = L1->next;
        if(L2 != nullptr) L2 = L2->next;
    }
    curr->next = nullptr;
    return head;
}

Node* LinkedListSumRecursive(Node* L1, Node* L2, int carry){
    if(L1 == nullptr && L2 == nullptr && carry == 0) return nullptr;

    int sum = carry;
    if(L1 != nullptr) sum += L1->data;
    if(L2 != nullptr) sum += L2->data;

    carry = sum / 10;
    Node* result = new Node(sum % 10);
    if(L1 != nullptr || L2 != nullptr){
        Node* nextSum = LinkedListSumRecursive(L1 != nullptr ? L1->next : nullptr, L2 != nullptr ? L2->next : nullptr, carry);
        result->next = nextSum;
    }
    return result;
}
Node* reverseLinkedList(Node* node){
    if(node == nullptr) return nullptr;
    Node* tail = node;
    Node* head = node;
    Node* next;
    while(node != nullptr){
        next = node -> next;
        node -> next = head;
        head = node;
        node = next;
    }
    tail -> next = nullptr;
    return head;
}
int main(){
    Node* L1 = new Node(7);
    L1 -> next = new Node(1);
    L1 -> next -> next = new Node(8);

    Node* L2 = new Node(9);
    L2 -> next = new Node(2);
    L2 -> next -> next = new Node(5);
    L2 -> next -> next -> next = new Node(9);

    Node* sum = LinkedListSumIterative(L1, L2);
    Node* sumR = LinkedListSumRecursive(L1, L2, 0);

    // printLinkedList(sum);
    // printLinkedList(sumR);

    Node* L3 = new Node(8);
    L3 -> next = new Node(1);
    L3 -> next -> next = new Node(7);

    Node* L4 = new Node(9);
    L4 -> next = new Node(5);
    L4 -> next -> next = new Node(2);
    L4 -> next -> next -> next = new Node(9);

    Node* L5 = reverseLinkedList(L3);
    Node* L6 = reverseLinkedList(L4);

    Node* sumRv = reverseLinkedList(LinkedListSumIterative(L5, L6));
    printLinkedList(sumRv);

    return 0;
} 