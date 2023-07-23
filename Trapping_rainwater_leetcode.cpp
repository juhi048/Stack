class Solution {
public:
    int left(int idx, vector<int>& height) {
        int leftMax = INT_MIN;
        for (int i = 0; i <= idx; i++) {
            leftMax = max (leftMax, height[i]);
        }
        return leftMax;
    }

    int right(int idx, vector<int>& height) {
        int rightMax = INT_MIN;
        for (int i = idx; i < height.size(); i++) {
            rightMax = max (rightMax, height[i]);
        }
        return rightMax;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        int waterTrapped = 0;
        for (int i = 1; i < n-1; i++) {
            int leftMax = left(i, height);
            int rightMax = right(i, height);
            waterTrapped += min (leftMax, rightMax) - height[i];
        }
        return waterTrapped;
    }
};
