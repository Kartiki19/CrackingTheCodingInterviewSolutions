#include<iostream>
#include<set>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val) : data(val){}
};
void printLinkedList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}
void removeDuplicates(Node* head){ /// TC = O(n) | SC = O(n)
    if(head == nullptr) return;

    set<int> duplicates; /// O(n)
    Node* node = head;
    Node* prev = head;

    while(node != nullptr){ /// O(n)
        if(duplicates.find(node->data) != duplicates.end()){
            prev -> next = node -> next;
        }
        else{
            duplicates.insert(node->data);
            prev = node;
        }
        node = node -> next;
    }
}

void removeDuplicatedNoDS(Node* head){ /// TC = O(n2)
    if(head == nullptr) return;
    Node* first = head;
    Node* prev = nullptr;
    Node* second = nullptr;

    while(first != nullptr){ /// O(n)
        second = first -> next;
        prev = first;
        while(second != nullptr){ /// O(n)
            if(first->data == second->data){
                prev->next = second->next;
            }
            else{
                prev = second;
            }
            second = second -> next;
        }
        first = first -> next;
    }
}
int main(){
    Node* head = new Node(9);
    head -> next = new Node(9);
    head -> next -> next = new Node(11);
    head -> next -> next -> next = new Node(10);
    head -> next -> next -> next -> next = new Node(8);
    head -> next -> next -> next -> next -> next = new Node(9);
    head -> next -> next -> next -> next -> next -> next = new Node(10);

    printLinkedList(head);

    /// TC = O(n) | SC = O(n)
    /// removeDuplicates(head);

    /// TC = O(n2) | SC = O(1)
    removeDuplicatedNoDS(head); 

    printLinkedList(head);

    return 0;
}