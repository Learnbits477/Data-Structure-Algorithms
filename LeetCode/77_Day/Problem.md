<h2><a href="https://leetcode.com/problems/minimum-total-distance-traveled/description/?envType=daily-question&envId=2026-04-14">2463. Minimum Total Distance Traveled</a></h2>

<h3>Hard</h3>

<hr>

<p>There are some robots and factories on the X-axis. You are given an integer array <code>robot</code> where <code>robot[i]</code> is the position of the <code>i<sup>th</sup></code> robot. You are also given a 2D integer array <code>factory</code> where <code>factory[j] = [position<sub>j</sub>, limit<sub>j</sub>]</code> indicates that <code>position<sub>j</sub></code> is the position of the <code>j<sup>th</sup></code> factory and that the <code>j<sup>th</sup></code> factory can repair at most <code>limit<sub>j</sub></code> robots.</p>

<p>The positions of each robot are unique. The positions of each factory are also unique. Note that a robot can be repaired at any factory that has not reached its limit.</p>

<p>All robots are initially broken; they keep moving in one direction. The direction could be the negative or the positive direction of the X-axis. When a robot reaches a factory that did not reach its limit, the factory repairs the robot, and it stops moving.</p>

<p>At any moment, you can set the initial direction of moving for some robot. Your target is to minimize the total distance traveled by all the robots.</p>

<p>Return <em>the minimum total distance traveled by all the robots</em>. The test cases are generated such that all the robots can be repaired.</p>

<p><strong>Note:</strong></p>
<ul>
<li>All robots move at the same speed.</li>
<li>If two robots move in the same direction, they will never collide.</li>
<li>If two robots move in opposite directions and they meet at some point, they do not collide. They cross each other.</li>
<li>If a robot passes by a factory that reached its limits, it crosses it as if it does not exist.</li>
<li>If the robot moved from a position <code>x</code> to a position <code>y</code>, the distance it moved is <code>|y - x|</code>.</li>
</ul>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> robot = [0,4,6], factory = [[2,2],[6,2]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
- The first robot at position 0 is repaired at the first factory. Distance: |2 - 0| = 2.
- The second robot at position 4 is repaired at the first factory. Distance: |2 - 4| = 2.
- The third robot at position 6 is repaired at the second factory. Distance: |6 - 6| = 0.
Total distance is 2 + 2 + 0 = 4. This is the optimal assignment.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> robot = [1,-1], factory = [[-2,1],[2,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
- The first robot at position 1 is repaired at the second factory (position 2). Distance: |2 - 1| = 1.
- The second robot at position -1 is repaired at the first factory (position -2). Distance: |-2 - (-1)| = 1.
Total distance is 1 + 1 = 2.
</pre>

<p>&nbsp;</p>

<p><strong>Constraints:</strong></p>
<ul>
    <li><code>1 &lt;= robot.length, factory.length &lt;= 100</code></li>
    <li><code>factory[j].length == 2</code></li>
    <li><code>-10<sup>9</sup> &lt;= robot[i], position<sub>j</sub> &lt;= 10<sup>9</sup></code></li>
    <li><code>0 &lt;= limit<sub>j</sub> &lt;= robot.length</code></li>
</ul>
