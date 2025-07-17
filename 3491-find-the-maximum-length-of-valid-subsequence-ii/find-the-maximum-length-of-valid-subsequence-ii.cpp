
class Solution {
public:
    int maximumLength(std::vector<int>& nums, int k) {
        int maxLength = 2;

        for (int targetMod = 0; targetMod < k; ++targetMod) {
            std::vector<int> remainderDP(k, 0);

            for (int num : nums) {
                int numMod = num % k;
                int requiredMod = (targetMod - numMod + k) % k;
                remainderDP[numMod] = remainderDP[requiredMod] + 1;
            }

            for (int length : remainderDP) {
                maxLength = std::max(maxLength, length);
            }
        }

        return maxLength;
    }
};