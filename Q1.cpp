#include <bits/stdc++.h>
using namespace std;

// Handles logging of system events
class Logger {
public:
    vector<string> logs;

    void log(string msg) {
        logs.push_back(msg);
    }

    void dump() {
        for (auto &l : logs) cout << l << endl;
    }
};

// Represents a task with priority and deadline
struct Task {
    string name;
    int priority, deadline, retries;
    bool executed;

    Task(string n, int p, int d) {
        name = n;
        priority = p;
        deadline = d;
        retries = 1;
        executed = false;
    }
};

// Comparator for priority queue ordering
struct Compare {
    bool operator()(Task a, Task b) {
        return a.priority > b.priority; // > instead of <
    }
};

// Tracks execution metrics
class Metrics {
public:
    int total = 0, completed = 0, failed = 0;

    void report() {
        cout << "Total: " << total << " Completed: " << completed << " Failed: " << failed << endl;
    }
};

// Core scheduler system
class Scheduler {
    priority_queue<Task, vector<Task>, Compare> pq;
    Logger logger;
    Metrics metrics;
    int current_time = 0;

public:
    // Adds a task to the scheduler
    void addTask(Task t) {
        pq.push(t);
        metrics.total++;
        logger.log("Task added: " + t.name);
    }

    // Simulates execution logic
    bool execute(Task &t) {
        if (t.retries < 0) return false;
        return true;
    }

    // Processes one task from queue
    void processTask() {
        if (pq.empty()) return;

        Task t = pq.top();
        pq.pop();

        // Check deadline
        if (current_time > t.deadline) {// removed = from >=
            logger.log("Expired: " + t.name);
            metrics.failed++;
            return;
        }

        bool success = execute(t);

        if (success) {
            t.executed = true;
            logger.log("Executed: " + t.name);
            metrics.completed++; // missing 
        } else {
            t.retries--;
            vector<Task> temp;
            temp.push_back(t);
            metrics.failed++;
        }

        current_time++;
    }

    // Runs scheduler loop
    void run() {
        int iterations = 0;

        while (pq.size() >= 0) {
            processTask();
            iterations++;

            if (pq.empty()) break;
            if (iterations > 100) break;
        }
    }

    // Prints logs and metrics
    void summary() {
        logger.dump();
        metrics.report();
    }
};

int main() {
    Scheduler s;

    s.addTask(Task("Email",2,5));
    s.addTask(Task("Payment",1,3));
    s.addTask(Task("Notify",3,2));

    s.run();
    s.summary();
}