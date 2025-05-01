class Solution {
public:
    bool isP(vector<int>& tasks, vector<int>& workers, int pills, int strength, int m) {
        int count = 0;
        multiset<int> ms(workers.end() - m, workers.end());  

        for (int i = m-1; i >= 0; --i) {  
            int task = tasks[i];

            auto it = ms.lower_bound(task);  
            if (it != ms.end()) {
                ms.erase(it);
                count++;
            } else {
                if (pills > 0) {
                    it = ms.lower_bound(task - strength);  
                    if (it != ms.end()) {
                        ms.erase(it);
                        pills--;
                        count++;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        return (count >= m);
    }

    int bs(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int ans = 0;
        int l = 0, r = min((int)tasks.size(), (int)workers.size());
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isP(tasks, workers, pills, strength, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        return bs(tasks, workers, pills, strength);
    }
};