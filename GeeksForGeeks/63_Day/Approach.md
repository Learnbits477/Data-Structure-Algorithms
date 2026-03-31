# Approach: Buy Stock with Transaction Fee

## Problem Analysis

The goal is to maximize total profit from stock trading where:
- We can make multiple transactions.
- We must sell before buying again.
- Each transaction (buy + sell) incurs a fee `k`.

## Dynamic Programming State

We maintain two states for each day `i`:
1. **`hold`**: The maximum profit we can have on day `i` if we are currently holding a stock.
2. **`notHold`**: The maximum profit we can have on day `i` if we are not holding any stock.

## State Transitions

At any given day `i`:
- **For `hold`**:
  - We already had a stock from a previous day.
  - We didn't have a stock, but we bought one today (`notHold[i-1] - arr[i]`).
  - `hold[i] = max(hold[i-1], notHold[i-1] - arr[i])`

- **For `notHold`**:
  - We already didn't have a stock.
  - We had a stock but we sold it today (`hold[i-1] + arr[i] - k`).
  - `notHold[i] = max(notHold[i-1], hold[i-1] + arr[i] - k)`

## Initial Values

- On day 0:
  - If we buy: `hold = -arr[0]`
  - If we don't buy: `notHold = 0`

## Result

The answer is the maximum profit on the last day when we are not holding any stock, which is `notHold`.

## Complexity Analysis

- **Time Complexity**: **O(n)**, where `n` is the number of days. We only need to iterate through the prices once.
- **Space Complexity**: **O(1)**, as we only need to store the `hold` and `notHold` values from the previous day.

---

### Code Illustration

```cpp
long long hold = -arr[0];
long long notHold = 0;

for (int i = 1; i < n; i++) {
    long long prevNotHold = notHold;
    notHold = max(notHold, hold + arr[i] - k);
    hold = max(hold, prevNotHold - arr[i]);
}
return notHold;
```

---

[Problem Link](https://www.geeksforgeeks.org/problems/buy-stock-with-transaction-fee/1)
