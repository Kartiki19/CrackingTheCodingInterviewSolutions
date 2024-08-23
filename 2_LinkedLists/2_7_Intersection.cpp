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
class Result{
    public:
        int size;
        Node* tail;
        Result(Node* node, int len): tail(node), size(len) {}
};

Result* getTailandSize(Node* node){  /// O(n)
    int size = 1;
    Node* current = node;
    while(current->next != nullptr){
        current = current->next;
        size++;
    }
    return new Result(current, size);
}

Node* findIntersection(Node* L1, Node* L2){
    Result* result_1 = getTailandSize(L1); /// O(n)
    Result* result_2 = getTailandSize(L2); /// O(m)

    if(result_1->tail != result_2->tail) return nullptr;

    Node* longer = (result_1->size > result_2->size) ? L1 : L2;
    Node* shorter = (result_1->size <= result_2->size) ? L1 : L2;

    int diff = abs(result_1->size - result_2->size);

    /// O(n)
    while(diff > 0){
        longer = longer->next;
        diff--;
    }

    while(longer != shorter){
        longer = longer->next;
        shorter = shorter->next;
    }
    return longer;
}

int main(){
    Node* L1 = new Node(9);
    L1 -> next = new Node(2);
    L1 -> next -> next = new Node(11);
    L1 -> next -> next -> next = new Node(4);
    L1 -> next -> next -> next -> next = new Node(5);
    L1 -> next -> next -> next -> next -> next = new Node(4);
    L1 -> next -> next -> next -> next -> next -> next = new Node(11);
    L1 -> next -> next -> next -> next -> next -> next -> next = new Node(2);
    L1 -> next -> next -> next -> next -> next -> next -> next-> next = new Node(9);

    Node* L2 = new Node(15);
    L2 -> next = new Node(4);
    L2 -> next -> next =  L1 -> next -> next -> next -> next;

    printLinkedList(L1);
    printLinkedList(L2);
    
    /// O(n+m) + O(n÷)
    Node* intersection = findIntersection(L1, L2);

    cout << "\nThe intersection point is: " << endl;
    printLinkedList(intersection);

    return 0;
}