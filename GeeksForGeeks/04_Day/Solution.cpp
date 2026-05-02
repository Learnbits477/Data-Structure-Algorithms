#include <iostream>
#include <vector>

using namespace std;

class kQueues {
    int n; // Size of the array
    int k; // Number of queues
    int *arr; // Array to store elements
    int *front; // Array to store front index of each queue
    int *rear; // Array to store rear index of each queue
    int *next; // Array to store next entry in queue or next free slot
    int freeSpot; // Index of the first free slot

public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        // Initialize front and rear for all queues
        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        // Initialize next array to point to the next free slot
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1; // End of free list

        freeSpot = 0;
    }

    ~kQueues() {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }

    // Adds element x into component i
    void enqueue(int x, int i) {
        // Overflow check (though isFull() handles it, good to have safeguard)
        if (isFull()) {
            return;
        }

        // Get index of first free slot
        int index = freeSpot;

        // Update freeSpot
        freeSpot = next[index];

        // If queue is empty
        if (front[i] == -1) {
            front[i] = index;
        } else {
            // Link new element to the current rear
            next[rear[i]] = index;
        }

        // Update next to -1 (end of queue)
        next[index] = -1;

        // Update rear
        rear[i] = index;

        // Store element
        arr[index] = x;
    }

    // Removes element from component i
    int dequeue(int i) {
        // Underflow check
        if (isEmpty(i)) {
            return -1;
        }

        // Find index of front
        int index = front[i];

        // Update front
        front[i] = next[index];

        // If queue becomes empty, update rear (optional, logic works without it but clean)
        if (front[i] == -1) {
             rear[i] = -1;
        }

        // Add the free slot back to free list
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    // Check if queue i is empty
    bool isEmpty(int i) {
        return front[i] == -1;
    }

    // Check if array is full
    bool isFull() {
        return freeSpot == -1;
    }
};
