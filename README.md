# 🐞 BugSlayer: Debugging Showdown (C++ Track)

Welcome to the **C++ Debugging Challenge** 🚀

You are provided with **3 programs (A, B, C)**.
Each program contains **5 hidden bugs**.

Your task is to:

* Identify all bugs
* Fix them correctly
* Run the code
* Match the **expected output**

---

# 📌 General Instructions

* Each program has **exactly 5 bugs**
* Total bugs = **15**
* Fixing logic is more important than syntax
* Output must match exactly
* Do NOT change overall structure unless required

---

# QUESTION A: Task Scheduler System

## Problem Statement

You are given a **Task Scheduling System** that:

* Executes tasks based on **priority**
* Handles **deadlines**
* Tracks execution using logs and metrics

### Expected Behavior:

* Higher priority tasks execute first
* Tasks should not execute after deadline
* Successfully executed tasks should be counted

---

## Expected Output

```
Executed: Payment
Executed: Email
Executed: Notify
Total: 3 Completed: 3 Failed: 0
```

---

# QUESTION B: LRU Cache with TTL

## Problem Statement

You are given an **LRU Cache system** with:

* Fixed capacity
* TTL (Time-to-live) for each key
* Doubly Linked List + HashMap

### Expected Behavior:

* Least Recently Used item should be evicted
* Expired items should not be returned
* Recently accessed items move to front

---

## Expected Output

```
A
-1
3 4
```

---

# QUESTION C: Delivery Optimization (Graph)

## Problem Statement

You are given a **graph-based delivery system**:

* Nodes represent locations
* Edges represent weighted paths
* System computes **shortest path**

### Expected Behavior:

* Correct shortest path using Dijkstra logic
* Proper distance updates
* Valid path reconstruction

---

## Expected Output

```
A C D
```

---

# Evaluation Criteria

| Criteria         | Description                     |
| ---------------- | ------------------------------- |
| ✅ Bug Fixing     | Number of correctly fixed bugs  |
| ✅ Correct Output | Matches expected output         |
| ✅ Logic          | Proper algorithm implementation |
| ✅ Efficiency     | Clean and optimal fixes         |

---

# Important Rules

* ❌ No internet usage after start
* ❌ No external help
* ✅ Use only provided code

---

# Goal

Fix all **15 bugs** and achieve correct outputs for all 3 programs.

---

🔥 **May the best debugger win!**

Test case for Q1

```
if __name__ == "__main__":
    scheduler = TaskScheduler()

    scheduler.add_task(Task("T1", 3, 1))
    scheduler.add_task(Task("T2", 1, 0))
    scheduler.add_task(Task("T3", 2, 2))

    t4 = Task("T4-Fail", 1, 10)
    t4.retries = -1
    scheduler.add_task(t4)

    scheduler.add_task(Task("T5", 5, 10))

    scheduler.run()
    scheduler.summary()
```