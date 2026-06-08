#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

// Helper function to create a linked list from a vector
Node* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

string listToString(Node* head) {
    if (!head) return "Empty";
    string res = "";
    Node* curr = head;
    while (curr) {
        res += to_string(curr->data);
        if (curr->next) {
            res += "->";
        }
        curr = curr->next;
    }
    return res;
}

// Helper function to free memory of the list
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to run a single test case
void runTest(int testNum, const vector<int>& inputArr, const string& expectedStr) {
    Node* head = createList(inputArr);
    string inputStr = listToString(head);
    
    Solution sol;
    Node* resultHead = sol.compute(head);
    string resultStr = listToString(resultHead);
    
    cout << "Test Case " << testNum << ":\n";
    cout << "  Input:    " << inputStr << "\n";
    cout << "  Expected: " << expectedStr << "\n";
    cout << "  Output:   " << resultStr << "\n";
    
    if (resultStr == expectedStr) {
        cout << "  Status:   ✅ PASSED\n\n";
    } else {
        cout << "  Status:   ❌ FAILED\n\n";
    }
    
    freeList(resultHead);
}

int main() {
    cout << "\n🔢 Delete Nodes with Greater on Right — Test Suite\n";
    cout << "========================================================\n" << endl;
    
    // GFG Example 1
    runTest(1, {12, 15, 10, 11, 5, 6, 2, 3}, "15->11->6->3");
    
    // GFG Example 2
    runTest(2, {10, 20, 30, 40, 50, 60}, "60");
    
    // Additional Edge Cases
    runTest(3, {5}, "5");                               // Single Node
    runTest(4, {5, 4, 3, 2, 1}, "5->4->3->2->1");       // Strictly decreasing list
    runTest(5, {1, 2, 3, 4, 5}, "5");                   // Strictly increasing list
    runTest(6, {8, 2, 5, 4, 3}, "8->5->4->3");          // Mixed values
    runTest(7, {6, 6, 6, 6}, "6->6->6->6");             // Duplicate values
    
    return 0;
}
