class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
          vector<vector<int>> result;
        int n = nums.size();
        
        // Sort the input array
        sort(nums.begin(), nums.end());
        
        // Iterate through the array for the first element
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            // Iterate through the array for the second element
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                // Initialize two pointers for the third and fourth elements
                int left = j + 1, right = n - 1;
                
                // Use two-pointer technique to find pairs summing up to target
                while (left < right) {
                    long long sum = static_cast<long long>(nums[i]) + static_cast<long long>(nums[j]) 
                                    + static_cast<long long>(nums[left]) + static_cast<long long>(nums[right]);
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates
                        while (left < right && nums[left] == nums[left + 1])
                            ++left;
                        while (left < right && nums[right] == nums[right - 1])
                            --right;
                        
                        ++left;
                        --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        
        return result;
    }
    
};