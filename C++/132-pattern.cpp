// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int ak = numeric_limits<int>::min();
        vector<int> stk;
        for (int i = size(nums) - 1; i >= 0; --i) {
            if (nums[i] < ak) {
                return true;
            }
            while (!empty(stk) && stk.back() < nums[i]) {
                ak = stk.back(), stk.pop_back(); 
            }
            stk.emplace_back(nums[i]);
        }
        return false;
    }
};

// Time:  O(n^2)
// Space: O(1)
class Solution_TLE {
public:
    bool find132pattern(vector<int>& nums) {
        for (int i = 0; i < size(nums); ++i) {
            bool valid = false;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    valid = true;
                } else if (nums[j] > nums[i]) {
                    if (valid) {
                        return true;
                    }
                }
           }
        }
        return false;
    }
};
