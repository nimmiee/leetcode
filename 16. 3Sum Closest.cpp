class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         // Sort the input array
        sort(nums.begin(), nums.end());
        
        // Initialize closestSum with the sum of the first three elements
        int closestSum = nums[0] + nums[1] + nums[2];
        
        // Iterate over the array
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1; // Pointer for the element after nums[i]
            int right = nums.size() - 1; // Pointer for the last element
            
            // Check all possible combinations
            while (left < right) {
                // Calculate the current sum
                int sum = nums[i] + nums[left] + nums[right];
                
                // Update closestSum if the current sum is closer to target
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }
                
                // Adjust pointers based on the current sum
                if (sum < target) {
                    ++left; // Move the left pointer to increase the sum
                } else {
                    --right; // Move the right pointer to decrease the sum
                }
            }
        }
        
        return closestSum;
    }
};