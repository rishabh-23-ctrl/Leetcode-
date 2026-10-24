class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }

        priority_queue<int> maxHeap;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push(freq[i]);
            }
        }

        int intervals = 0;

        while (!maxHeap.empty()) {
            vector<int> temp;
            int cooldown = n + 1;

            while (cooldown > 0 && !maxHeap.empty()) {
                int count = maxHeap.top();
                maxHeap.pop();

                count--;

                if (count > 0) {
                    temp.push_back(count);
                }

                intervals++;
                cooldown--;
            }

            for (int i = 0; i < temp.size(); i++) {
                maxHeap.push(temp[i]);
            }

            if (!maxHeap.empty()) {
                intervals += cooldown;
            }
        }

        return intervals;
    }
};

