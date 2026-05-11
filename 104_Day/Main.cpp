#include <bits/stdc++.h>
using namespace std;

#include "Solution.cpp"

vector<string> buildArr(initializer_list<string> words) {
    return vector<string>(words);
}

void printResult(int no, const vector<string>& arr,
                 bool expected, bool got)
{
    cout << "─────────────────────────────────────────────\n";
    cout << "  Test #" << no << "\n";
    cout << "  Input    : [";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << "\"" << arr[i] << "\"";
        if (i + 1 < (int)arr.size()) cout << ", ";
    }
    cout << "]\n";
    cout << "  Expected : " << (expected ? "true" : "false") << "\n";
    cout << "  Got      : " << (got      ? "true" : "false") << "\n";
    cout << "  Result   : " << (expected == got ? "PASS" : "FAIL") << "\n";
}

// ── Test Cases ───────────────────────────────────────────────

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    cout << "\n";
    cout << "=============================================\n";
    cout << "     Palindrome Pairs — Test Suite          \n";
    cout << "=============================================\n\n";

    // Test 1 — GFG Example 1
    // "geekf" + "keeg" = "geekfkeeg" (palindrome)
    {
        auto arr = buildArr({"geekf", "geeks", "or", "keeg", "abc", "bc"});
        printResult(1, arr, true, sol.palindromePair(arr));
    }

    // Test 2 — GFG Example 2
    // "abc" + "xyxcba" = "abcxyxcba" (palindrome)
    {
        auto arr = buildArr({"abc", "xyxcba", "geekst", "or", "bc"});
        printResult(2, arr, true, sol.palindromePair(arr));
    }

    // Test 3 — GFG Example 3
    // Single string, no pair possible
    {
        auto arr = buildArr({"aa"});
        printResult(3, arr, false, sol.palindromePair(arr));
    }

    // Test 4 — Exact reverses
    // "abcd" + "dcba" = "abcddcba" (palindrome)
    {
        auto arr = buildArr({"abcd", "dcba"});
        printResult(4, arr, true, sol.palindromePair(arr));
    }

    // Test 5 — No valid pair exists
    {
        auto arr = buildArr({"cat", "dog", "bird"});
        printResult(5, arr, false, sol.palindromePair(arr));
    }

    // Test 6 — Empty string + palindrome
    // "" + "aba" = "aba" (palindrome)
    {
        auto arr = buildArr({"", "aba", "xyz"});
        printResult(6, arr, true, sol.palindromePair(arr));
    }

    // Test 7 — All single distinct characters, no pair possible
    {
        auto arr = buildArr({"a", "b", "c"});
        printResult(7, arr, false, sol.palindromePair(arr));
    }

    cout << "─────────────────────────────────────────────\n\n";
    return 0;
}
