#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
private:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* nextNode = nullptr;
        while (curr != nullptr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    Node* compute(Node* head) {
        if (!head || !head->next) {
            return head;
        }

        // Step 1: Reverse the Linked List
        head = reverse(head);

        // Step 2: Filter Nodes
        Node* max_node = head;
        Node* curr = head->next;

        while (curr != nullptr) {
            if (curr->data < max_node->data) {
                // Bypass curr node since a larger node exists to its right (left in reversed list)
                Node* temp = curr;
                max_node->next = curr->next;
                curr = curr->next;
                delete temp; // Free memory of the bypassed node
            } else {
                // Update max_node and move forward
                max_node = curr;
                curr = curr->next;
            }
        }

        // Step 3: Re-reverse the Linked List
        head = reverse(head);

        return head;
    }
};
