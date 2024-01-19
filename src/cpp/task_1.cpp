/*
 * Author: Rakhimberdi
 * Date:
 * Name:
 */

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

Node* mergeNodes(Node* head) {
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;
    Node* curr = head;
    int sum = 0;

    while (curr != NULL) {
        if (curr->val == 0) {
            while (curr != NULL && curr->val == 0) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
            prev->next = new Node(sum);
            prev = prev->next;
            sum = 0;
        } else {
            sum += curr->val;
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    return dummy->next;
}


