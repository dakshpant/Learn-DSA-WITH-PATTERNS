# 🚀 DSA With Patterns

<div align="center">

![DSA](https://img.shields.io/badge/DSA-Problem%20Solving-blue?style=for-the-badge)
![LeetCode](https://img.shields.io/badge/Platform-LeetCode-orange?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B-success?style=for-the-badge)

### A structured collection of Data Structures & Algorithms problems solved pattern-wise.

</div>

---

# 📚 Patterns Covered

- Two Pointers
- Fast & Slow Pointers
- Sliding Window
- Kadane's Algorithm
- Prefix Sum
- Intervals

---

# 1️⃣ Two Pointers Pattern

> The Two Pointers pattern uses two indices/pointers moving through the data structure to solve problems efficiently.

| # | Problem | Difficulty | LeetCode |
|---|---|---|---|
| 1 | Pair with Target Sum | Easy | [Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) |
| 2 | Rearrange 0 and 1 | Easy | [Sort Colors](https://leetcode.com/problems/sort-colors/) |
| 3 | Remove Duplicates | Easy | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) |
| 4 | Squaring a Sorted Array | Easy | [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/) |
| 5 | Triplet Sum to Zero | Medium | [3Sum](https://leetcode.com/problems/3sum/) |
| 6 | Triplet Sum Close to Target | Medium | [3Sum Closest](https://leetcode.com/problems/3sum-closest/) |
| 7 | Triplets with Smaller Sum | Medium | [3Sum Smaller](https://leetcode.com/problems/3sum-smaller/) |
| 8 | Dutch National Flag Problem | Medium | [Sort Colors](https://leetcode.com/problems/sort-colors/) |

---

# 2️⃣ Fast & Slow Pointers Pattern

> Also known as Floyd’s Cycle Detection Algorithm. Used mainly in linked lists and cycle-related problems.

| # | Problem | Difficulty | LeetCode |
|---|---|---|---|
| 1 | LinkedList Cycle | Easy | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) |
| 2 | Start of LinkedList Cycle | Medium | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/) |
| 3 | Happy Number | Medium | [Happy Number](https://leetcode.com/problems/happy-number/) |
| 4 | Find Duplicate Number | Medium | [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) |
| 5 | Middle of the LinkedList | Easy | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) |

---

# 3️⃣ Sliding Window Pattern

> The Sliding Window pattern is used for problems involving arrays or strings where a subset/subarray/substring needs to be processed efficiently.

| # | Problem | Difficulty | LeetCode |
|---|---|---|---|
| 1 | Maximum Sum Subarray of Size K | Easy | [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/) |
| 2 | Smallest Subarray with a Given Sum | Easy | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) |
| 3 | Longest Substring with K Distinct Characters | Medium | [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/) |
| 4 | Fruits into Baskets | Medium | [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/) |
| 5 | No-repeat Substring | Hard | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) |
| 6 | Longest Substring with Same Letters after Replacement | Hard | [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) |
| 7 | Longest Subarray with Ones after Replacement | Hard | [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) |
| 8 | Minimum Size Subarray Sum | Medium | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) |
| 9 | Minimum Window Substring | Hard | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) |

---

# 4️⃣ Kadane's Algorithm Pattern

> Kadane’s Algorithm is used to solve maximum/minimum subarray problems in linear time.

| # | Problem | Difficulty | LeetCode |
|---|---|---|---|
| 1 | Maximum Subarray Sum | Medium | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) |
| 2 | Minimum Subarray Sum | Medium | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) |
| 3 | Maximum Product Subarray | Medium | [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) |
| 4 | Maximum Subarray Sum with One Deletion | Hard | [Maximum Subarray Sum with One Deletion](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/) |
| 5 | Maximum Absolute Sum of Any Subarray | Medium | [Maximum Absolute Sum of Any Subarray](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/) |
| 6 | Maximum Sum Circular Subarray | Medium | [Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/) |

---

# 5️⃣ Prefix Sum Pattern

> Prefix Sum helps in solving cumulative/range sum problems efficiently.
> Advanced Prefix Sum problems often use HashMaps to store previously seen sums or remainders.

| # | Problem | Difficulty | LeetCode |
|---|---|---|---|
| 1 | Subarray Sum Equals K | Easy | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/) |
| 2 | Find Pivot Index | Easy | [Find Pivot Index](https://leetcode.com/problems/find-pivot-index/description/) |
| 3 | Subarray Sums Divisible By K | Medium | [Subarray Sums Divisible By K](https://leetcode.com/problems/subarray-sums-divisible-by-k/description/) |
| 4 | Contiguous Array | Medium | [Contiguous Array](https://leetcode.com/problems/contiguous-array/description/) |

---

# 🧠 Prefix Sum Learning Flow

### 1️⃣ Find Pivot Index
Learn:
- Running Sum
- Left Sum vs Right Sum
- Total Sum usage

### 2️⃣ Subarray Sum Equals K
Learn:
- Prefix Sum + HashMap
- Converting subarray problems into prefix relations

Core idea:
```cpp
currentSum - previousSum = k
```

### 3️⃣ Contiguous Array
Learn:
- Transformations in Prefix Sum

Convert:
```cpp
0 -> -1
1 -> +1
```

Equal 0s and 1s means same prefix sum repeats.

### 4️⃣ Subarray Sums Divisible By K
Learn:
- Prefix Modulo Pattern
- Hashing remainders

Core idea:
```cpp
(prefixSum % k)
```

If two prefix sums have the same remainder,
their difference is divisible by `k`.

---

# 6️⃣ Intervals Pattern

> Interval problems involve merging, inserting, overlapping, scheduling, and range-based processing.

| # | Problem | Difficulty | LeetCode |
|---|---|---|---|
| 1 | Merge Intervals | Medium | [Merge Intervals](https://leetcode.com/problems/merge-intervals/) |
| 2 | Insert Interval | Medium | [Insert Interval](https://leetcode.com/problems/insert-interval/) |
| 3 | Non-overlapping Intervals | Medium | [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) |
| 4 | Meeting Rooms | Easy | [Meeting Rooms](https://leetcode.com/problems/meeting-rooms/) |
| 5 | Meeting Rooms II | Medium | [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) |

---

# 🧠 Intervals Learning Flow

### 1️⃣ Merge Intervals
Learn:
- Sorting intervals
- Detecting overlaps
- Merging ranges

Core idea:
```cpp
if(e1 >= s2)
```

---

### 2️⃣ Insert Interval
Learn:
- Correct insertion position
- Merge after insertion
- Edge cases involving empty arrays

Core idea:
```cpp
Insert + Merge
```

---

### 3️⃣ Non-overlapping Intervals
Learn:
- Greedy interval removal
- Choosing optimal ending times

---

### 4️⃣ Meeting Rooms
Learn:
- Overlap detection
- Sorting by start time

---

### 5️⃣ Meeting Rooms II
Learn:
- Min Heap / Priority Queue
- Active interval tracking

---

# 🛠️ Languages Used

```cpp
C++
```

---

# 🎯 Goals

- Master common DSA patterns
- Improve problem-solving skills
- Prepare for coding interviews
- Build strong algorithmic intuition
- Understand WHY patterns work instead of memorizing solutions

---

# 📈 Progress Tracker

| Pattern | Problems Solved |
|---|---|
| Two Pointers | 8 |
| Fast & Slow Pointers | 5 |
| Sliding Window | 9 |
| Kadane Pattern | 6 |
| Prefix Sum | 4 |
| Intervals | 2 |

### ✅ Total Problems Solved: 37

---

# ⭐ Notes

- Problems are organized pattern-wise for better learning.
- Solutions focus on optimized approaches.
- Focus on understanding WHY a pattern works.
- Prefix Sum problems are heavily connected through transformations and HashMap usage.
- Interval problems rely heavily on sorting and overlap detection.
- More patterns and problems will be added continuously.

---

<div align="center">

## 🌟 Happy Coding!

</div>