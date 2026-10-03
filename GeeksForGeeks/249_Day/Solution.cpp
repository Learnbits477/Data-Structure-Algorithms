#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> formCoils(int n) {
        // Step: 01 - Pre-allocate containers for coil 1 and coil 2
        int m = 8 * n * n;
        int totalCells = 16 * n * n;
        vector<int> coil1;
        coil1.reserve(m);
        vector<int> coil2(m);

        // Step: 02 - Initialize starting position and direction offsets
        int r = 0, c = 0;
        coil1.push_back(r * (4 * n) + c + 1);

        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};
        int dir = 0;

        // Step: 03 - Traverse initial downward segment of length 4n
        for (int step = 0; step < 4 * n - 1; ++step) {
            r += dr[dir];
            c += dc[dir];
            coil1.push_back(r * (4 * n) + c + 1);
        }
        dir = (dir + 1) % 4;

        // Step: 04 - Traverse orthogonal segment pairs of decreasing lengths
        for (int len = 4 * n - 2; len >= 2; len -= 2) {
            for (int rep = 0; rep < 2; ++rep) {
                for (int step = 0; step < len; ++step) {
                    r += dr[dir];
                    c += dc[dir];
                    coil1.push_back(r * (4 * n) + c + 1);
                }
                dir = (dir + 1) % 4;
            }
        }

        // Step: 05 - Derive coil 2 using 180-degree central point symmetry
        for (int i = 0; i < m; ++i) {
            coil2[i] = totalCells + 1 - coil1[i];
        }

        // Step: 06 - Return both coils in order
        return {coil1, coil2};
    }

    vector<vector<int>> formCoilsSimulation(int n) {
        // Step: 01 - Compute coil 1 using spiral traversal
        vector<vector<int>> res = formCoils(n);
        int m = 8 * n * n;
        vector<int> coil2Direct;
        coil2Direct.reserve(m);

        // Step: 02 - Initialize coil 2 starting from bottom-right corner
        int r = 4 * n - 1, c = 4 * n - 1;
        coil2Direct.push_back(r * (4 * n) + c + 1);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        int dir = 0;

        // Step: 03 - Traverse initial upward segment of length 4n
        for (int step = 0; step < 4 * n - 1; ++step) {
            r += dr[dir];
            c += dc[dir];
            coil2Direct.push_back(r * (4 * n) + c + 1);
        }
        dir = (dir + 1) % 4;

        // Step: 04 - Traverse orthogonal segment pairs for coil 2
        for (int len = 4 * n - 2; len >= 2; len -= 2) {
            for (int rep = 0; rep < 2; ++rep) {
                for (int step = 0; step < len; ++step) {
                    r += dr[dir];
                    c += dc[dir];
                    coil2Direct.push_back(r * (4 * n) + c + 1);
                }
                dir = (dir + 1) % 4;
            }
        }

        // Step: 05 - Return coils with directly simulated coil 2
        return {res[0], coil2Direct};
    }
};
