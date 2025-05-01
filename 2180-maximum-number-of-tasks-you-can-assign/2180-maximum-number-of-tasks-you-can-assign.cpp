

class Solution {
public:
    int maxTaskAssign(std::vector<int>& tasks, std::vector<int>& workers, int pills, int strength) {
        // Sort the tasks and workers arrays
        std::sort(tasks.begin(), tasks.end());
        std::sort(workers.begin(), workers.end());

        // Binary search setup
        int left = 0, right = std::min(tasks.size(), workers.size());

        // Helper function to check if it's possible to assign the first `k` tasks
        auto canAssign = [&](int k) {
            std::multiset<int> availableWorkers(workers.end() - k, workers.end()); // The strongest `k` workers
            int remainingPills = pills;

            // Try assigning each task to a worker
            for (int i = k - 1; i >= 0; --i) {
                int task = tasks[i];
                auto it = availableWorkers.lower_bound(task); // Find a worker who can do this task

                if (it != availableWorkers.end()) {
                    availableWorkers.erase(it); // Assign the worker
                } else if (remainingPills > 0) {
                    // Try using a pill to make the worker strong enough
                    it = availableWorkers.lower_bound(task - strength);
                    if (it != availableWorkers.end()) {
                        availableWorkers.erase(it); // Assign the worker
                        --remainingPills; // Use one pill
                    } else {
                        return false; // No worker can do this task
                    }
                } else {
                    return false; // No worker can do this task
                }
            }
            return true;
        };

        // Binary search to find the maximum number of tasks that can be assigned
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (canAssign(mid)) {
                left = mid; // We can assign `mid` tasks, so try for more
            } else {
                right = mid - 1; // We cannot assign `mid` tasks, so try fewer
            }
        }

        return left; // The maximum number of tasks that can be assigned
    }
};
