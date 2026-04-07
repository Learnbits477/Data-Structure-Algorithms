#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Robot {
    int w, h, p;
    int pos = 0;
    bool moved = false;

public:
    /**
     * Initializes the grid and the robot at (0, 0) facing "East".
     * @param width The width of the grid.
     * @param height The height of the grid.
     */
    Robot(int width, int height) : w(width), h(height) {
        // The perimeter length is the number of unique positions on the boundary.
        // It forms a cycle for the robot's movement.
        p = 2 * (w + h - 2);
    }

    /**
     * Instructs the robot to move forward num steps.
     * @param num The number of steps to move.
     */
    void step(int num) {
        moved = true;
        // Total displacement from start within a cycle.
        pos = (pos + num) % p;
    }

    /**
     * Returns the current cell [x, y].
     * @return A vector containing x and y coordinates.
     */
    vector<int> getPos() {
        // Based on the position in the perimeter cycle, calculate (x, y).
        if (pos <= w - 1) {
            // South boundary: (x, 0)
            return {pos, 0};
        }
        if (pos <= w + h - 2) {
            // East boundary: (w-1, y)
            return {w - 1, pos - (w - 1)};
        }
        if (pos <= 2 * w + h - 3) {
            // North boundary: (x, h-1)
            return {w - 1 - (pos - (w + h - 2)), h - 1};
        }
        // West boundary: (0, y)
        return {0, h - 1 - (pos - (2 * w + h - 3))};
    }

    /**
     * Returns the current direction: "East", "North", "West", or "South".
     * @return The direction string.
     */
    string getDir() {
        // Direction is determined by the segment of the perimeter.
        // Special case for (0,0) after movement.
        if (pos == 0) {
            return moved ? "South" : "East";
        }
        if (pos >= 1 && pos <= w - 1) {
            return "East";
        }
        if (pos >= w && pos <= w + h - 2) {
            return "North";
        }
        if (pos >= w + h - 1 && pos <= 2 * w + h - 3) {
            return "West";
        }
        return "South";
    }
};

int main() {
    // Example 1
    cout << "Example 1 Trace:" << endl;
    Robot* robot = new Robot(6, 3);
    cout << "Init: (0,0) East" << endl;

    robot->step(2);
    vector<int> p1 = robot->getPos();
    cout << "step(2): [" << p1[0] << "," << p1[1] << "] " << robot->getDir() << endl;

    robot->step(2);
    vector<int> p2 = robot->getPos();
    cout << "step(2): [" << p2[0] << "," << p2[1] << "] " << robot->getDir() << endl;

    robot->step(2);
    vector<int> p3 = robot->getPos();
    cout << "step(2): [" << p3[0] << "," << p3[1] << "] " << robot->getDir() << endl;

    robot->step(1);
    vector<int> p4 = robot->getPos();
    cout << "step(1): [" << p4[0] << "," << p4[1] << "] " << robot->getDir() << endl;

    robot->step(4);
    vector<int> p5 = robot->getPos();
    cout << "step(4): [" << p5[0] << "," << p5[1] << "] " << robot->getDir() << endl;

    delete robot;
    return 0;
}
