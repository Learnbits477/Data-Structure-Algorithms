# Approach for 3296. Minimum Number of Seconds to Make Mountain Height Zero

## Problem Analysis
We have `N` workers, each taking `w * x * (x + 1) / 2` seconds to reduce the mountain by `x` units. The workers act simultaneously, meaning the total time taken will be the maximum of the individual completion times. We want to find a scenario such that the sum of all reductions across workers matches `mountainHeight`, and the maximum worker completion time is minimized.

This is a classic "Binary Search on Answer" problem. 
If it is possible to reduce the mountain to `0` in `T` seconds, it is definitely possible for any `T' > T`. Conversely, it would be impossible for `T' < T`. The monotonic property makes binary search suitable.

## Algorithm
1. **Define the Search Space**:
   - The minimum possible time is `0`.
   - The maximum possible time corresponds to assigning all the work to the fastest worker. Let `minWorker = min(workerTimes)`. Then, reducing all `H` sequentially takes `minWorker * H * (H + 1) / 2` seconds.

2. **Feasibility Check for a Given Time `T`**:
   - For a candidate total time `T`, determine how many units each worker can reduce on their own within `T` seconds.
   - For a worker with base time `w`, they can reduce `x` units, given by the inequality:
     `w * x * (x + 1) / 2 <= T`
   - Rearranging:
     `x * (x + 1) <= 2 * (T / w)`
   - We can obtain `x` approximately from the quadratic formula `x = (-1 + sqrt(1 + 8 * (T / w))) / 2` and carefully tune it downwards or upwards (using a small `while` loop) to ensure integer precision. Alternatively, if the required `x` clearly exceeds `mountainHeight`, we can simply clamp it at `mountainHeight` to prevent precision loss effectively.
   - We sum the heights reduced by all workers. If the sum reaches or exceeds `mountainHeight`, then time `T` is feasible.

3. **Binary Search Mechanism**:
   - `low = 0`, `high = max possible time`.
   - Take `mid = low + (high - low) / 2`.
   - By iteratively halving the search space, hone in on the exact minimum `T`.

## Complexity
- **Time Complexity:** $\mathcal{O}(N \log M)$, where $N$ is the number of workers, and $M$ is the upper bound of seconds. The max search range $\approx 5 \cdot 10^{15}$, so $\log_2(M) \approx 53$ operations per binary search. Within each step we iterate $N$ workers calculating square roots in $\mathcal{O}(1)$. Total loop operations $\approx 53 \times 10^4 \approx 5 \cdot 10^5$, finishing comfortably within any tight time limits.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
