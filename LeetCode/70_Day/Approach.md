# Approach: Walking Robot Simulation II

The robot moves on a fixed rectangular grid but only stays on the **perimeter boundary**. Instead of simulating each step, we can use **modular arithmetic** to find the position and direction efficiently.

## 1. Perimeter Calculation

The total number of unique positions on the boundary forms a cycle. For a `width x height` grid, the perimeter length (number of cells) is calculated as:

```cpp
p = 2 * (width + height - 2);
```

Initialize the robot's position index `pos = 0` and a flag `moved = false`.

## 2. Moving the Robot (`step`)

When the robot moves `num` steps, we simply update its position index relative to the perimeter using the modulo operator.

```cpp
void step(int num) {
    moved = true;
    pos = (pos + num) % p;
}
```

This reduces any large `num` to a value within the range `[0, p-1]`.

## 3. Determining Position (`getPos`)

We divide the perimeter into four segments:

- **South (0 to w-1)**: `(pos, 0)`
- **East (w to w+h-2)**: `(w-1, pos - (w-1))`
- **North (w+h-1 to 2w+h-3)**: `(w-1 - (pos - (w+h-2)), h-1)`
- **West (Remaining)**: `(0, h-1 - (pos - (2*w+h-3)))`

## 4. Determining Direction (`getDir`)

The direction depends on which segment the robot is currently in:

- **Special Case**: At `pos == 0`, the robot faces **"East"** if it hasn't moved yet, but faces **"South"** if it has completed at least one step (as it arrives from the North-West corner).
- **East**: `1 <= pos <= w-1`
- **North**: `w <= pos <= w+h-2`
- **West**: `w+h-1 <= pos <= 2w+h-3`
- **South**: Otherwise.

## Complexity Analysis

- **Time Complexity**: $O(1)$ for each `step`, `getPos`, and `getDir` call.
- **Space Complexity**: $O(1)$ as we only store a few integer variables.
