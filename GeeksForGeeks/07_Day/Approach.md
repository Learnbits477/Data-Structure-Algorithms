# Approach: Single Pass (Min Price Tracking)

## Intuition

To maximize profit with a single transaction (one buy and one sell), we need to find the largest difference between a selling price and a buying price, such that the buying price comes before the selling price in time.

Instead of a nested loop checking every pair (which would be O(N^2)), we can iterate through the prices while keeping track of the **minimum price seen so far**.

For each day's price:

1. We calculate the potential profit if we sell on this day: `current_price - min_price_so_far`.
2. We update our `max_profit` if this potential profit is higher than what we've seen.
3. We update `min_price_so_far` if the `current_price` is lower than the current minimum.

## Algorithm

1. Initialize `minPrice` to a very large value (or the first element).
2. Initialize `maxProfit` to 0.
3. Iterate through each price in the array:
    - Update `minPrice` = `min(minPrice, price)`.
    - Update `maxProfit` = `max(maxProfit, price - minPrice)`.
4. Return `maxProfit`.

## Complexity Analysis

- **Time Complexity:** O(N), where N is the number of days. We traverse the array once.
- **Space Complexity:** O(1), as we only use a few variables for tracking state.
