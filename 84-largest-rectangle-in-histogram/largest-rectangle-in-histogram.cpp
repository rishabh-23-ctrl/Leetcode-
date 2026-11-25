class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftStack, rightStack;
        vector<int> leftSmaller(n), rightSmaller(n);

        for(int i = 0; i < n; i++) {
            while(!leftStack.empty() && heights[leftStack.back()] >= heights[i]) {
                leftStack.pop_back();
            }
            int leftIndex = leftStack.empty() ? -1 : leftStack.back();
            leftStack.push_back(i);
            leftSmaller[i] = leftIndex;
        }

        for(int i = n - 1; i >= 0; i--) {
            while(!rightStack.empty() && heights[rightStack.back()] >= heights[i]) {
                rightStack.pop_back();
            }
            int rightIndex = rightStack.empty() ? n : rightStack.back();
            rightStack.push_back(i);
            rightSmaller[i] = rightIndex;
        }

        int max_area = 0;
        for(int i = 0; i < n; i++) {
            max_area = max(max_area, heights[i] * (rightSmaller[i] - leftSmaller[i] - 1));
        }

        return max_area;
    }
};