
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> freq;

        for (int i = 0; i < tasks.size(); i++) {
            freq[tasks[i]]++;
        }

        priority_queue<pair<int, char>> maxHeap;

        for (auto p : freq) {
            maxHeap.push({p.second, p.first});
        }

        int intervals = 0;

        while (!maxHeap.empty()) {
            queue<pair<int, char>> temp;
            int cooldown = n + 1;

            while (cooldown > 0 && !maxHeap.empty()) {
                auto p = maxHeap.top();
                maxHeap.pop();

                int count = p.first - 1;
                char task = p.second;

                if (count > 0) {
                    temp.push({count, task});
                }

                intervals++;
                cooldown--;
            }

            while (!temp.empty()) {
                maxHeap.push(temp.front());
                temp.pop();
            }

            if (!maxHeap.empty()) {
                intervals += cooldown;
            }
        }

        return intervals;
    }
};
