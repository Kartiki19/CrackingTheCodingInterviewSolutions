#include<iostream>
#include<stack>
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
Node* reverseLinkedList(Node* node){
    Node* head = node;
    Node* tail = node;
    Node* next;

    while(node!= nullptr){
        next = node->next;
        node->next = head;
        head = node;
        node = next;
    }

    tail -> next = nullptr;
    return head;
}
bool isPalindromeReverse(Node* node){
    Node* slow = node;
    Node* fast = node;
    
    /// Finding middle
    while(slow != nullptr && fast != nullptr && fast->next!=nullptr){
        slow = slow -> next;
        fast = fast ->next->next;
    }

    if(fast != nullptr){
        slow = slow->next;
    }

    /// Reverse from middle to end
    Node* newhead = reverseLinkedList(slow);

    /// check for palindrome from first and middle
    while(newhead != nullptr && node != nullptr && newhead->data == node->data){
        newhead = newhead->next;
        node = node->next;
    }
    if(newhead != nullptr) return false;
    return true;
}

bool isPalindromeStack(Node* node){
    Node* slow = node;
    Node* fast = node;
    stack<int> st;
    while(slow != nullptr && fast != nullptr && fast->next != nullptr){
        st.push(slow->data);
        slow = slow->next;
        fast = fast -> next -> next;
    }
    if(fast != nullptr){
        slow = slow->next;
    }

    while(!st.empty() && slow != nullptr){
        int top = st.top();
        st.pop();
        if(top != slow->data) return false;
        slow = slow->next;
    }
    return true;
}
int main(){
    Node* head = new Node(9);
    head -> next = new Node(2);
    head -> next -> next = new Node(11);
    head -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next = new Node(5);
    head -> next -> next -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next -> next -> next = new Node(11);
    head -> next -> next -> next -> next -> next -> next -> next = new Node(2);
    head -> next -> next -> next -> next -> next -> next -> next-> next = new Node(9);

    printLinkedList(head);
    //cout << "By reversing half linkedlist: "<< boolalpha << isPalindromeReverse(head) << endl;
    //printLinkedList(head);
    //cout << "By using Stack: " << boolalpha << isPalindromeStack(head) << endl;
    return 0;
}