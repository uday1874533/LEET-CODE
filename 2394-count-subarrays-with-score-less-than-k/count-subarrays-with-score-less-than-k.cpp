class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int start = 0;
        long long sum = 0;
        long long count = 0;
        
        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end];
            
            while (sum * (end - start + 1) >= k) {
                sum -= nums[start];
                start++;
            }
            
            count += (end - start + 1);
        }
        
        return count;
    }
};