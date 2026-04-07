#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>>& men, vector<vector<int>>& women) {
        int n = men.size();
        // womenPref[w][m] stores the rank of man m for woman w
        // smaller rank means higher preference
        vector<vector<int>> womenPref(n, vector<int>(n));
        for (int w = 0; w < n; w++) {
            for (int rank = 0; rank < n; rank++) {
                womenPref[w][women[w][rank]] = rank;
            }
        }
        
        vector<int> womenPartner(n, -1);
        vector<int> menPartner(n, -1);
        
        // nextPref[m] stores the index of the next woman man m will propose to
        vector<int> nextPref(n, 0);
        
        // queue to store all free men
        queue<int> freeMen;
        for (int m = 0; m < n; m++) {
            freeMen.push(m);
        }
        
        // while there are free men remaining
        while (!freeMen.empty()) {
            int m = freeMen.front();
            
            // Get the highest ranked woman that man m hasn't proposed to yet
            int w = men[m][nextPref[m]];
            nextPref[m]++; // Increment so he proposes to the next woman if rejected or dumped
            
            if (womenPartner[w] == -1) {
                // Woman is free, so pair them up
                womenPartner[w] = m;
                menPartner[m] = w;
                freeMen.pop();
            } else {
                // Woman w is currently engaged to m1
                int m1 = womenPartner[w];
                
                // Check if w prefers m over m1
                if (womenPref[w][m] < womenPref[w][m1]) {
                    // Woman prefers m to m1. So m and w get engaged, m1 becomes free
                    womenPartner[w] = m;
                    menPartner[m] = w;
                    freeMen.pop();
                    
                    menPartner[m1] = -1;
                    freeMen.push(m1); // m1 is now free and has to propose again
                }
                // Else w prefers m1 over m
                // In this case, m remains free (stays in queue) 
                // and will propose to next woman in his list next time
            }
        }
        
        return menPartner;
    }
};
