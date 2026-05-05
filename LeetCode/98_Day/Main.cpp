#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    cout << "[";
    while (curr) {
        cout << curr->val << (curr->next ? ", " : "");
        curr = curr->next;
    }
    cout << "]" << endl;
}

// Helper function to delete a linked list
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void runTest(vector<int> nums, int k) {
    Solution sol;
    ListNode* head = createList(nums);
    
    cout << "Input: ";
    printList(head);
    cout << "k: " << k << endl;
    
    ListNode* result = sol.rotateRight(head, k);
    
    cout << "Output: ";
    printList(result);
    cout << "-----------------------------------" << endl;
    
    deleteList(result);
}

int main() {
    cout << "Running Tests for Rotate List..." << endl << endl;

    // Example 1
    runTest({1, 2, 3, 4, 5}, 2);

    // Example 2
    runTest({0, 1, 2}, 4);

    // Edge Case: Empty List
    runTest({}, 5);

    // Edge Case: k = 0
    runTest({1, 2}, 0);

    return 0;
}
