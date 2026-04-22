#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;

        // Iterate through each word in the queries
        for (const string& query : queries) {
            bool foundMatch = false;

            // Compare query word with each word in the dictionary
            for (const string& dictWord : dictionary) {
                int diffCount = 0;

                // Calculate the Hamming distance (number of differing positions)
                for (int i = 0; i < query.length(); ++i) {
                    if (query[i] != dictWord[i]) {
                        diffCount++;
                    }
                    
                    // If differences exceed 2, this dictionary word is not a match
                    if (diffCount > 2) {
                        break;
                    }
                }

                // If differences are <= 2, the query word matches this dictionary word
                if (diffCount <= 2) {
                    foundMatch = true;
                    break;
                }
            }

            // If a matching dictionary word was found, add query word to result
            if (foundMatch) {
                result.push_back(query);
            }
        }

        return result;
    }
};
