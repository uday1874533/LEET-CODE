class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
       
        int n = nums.size();

        long long total = (n * 1ll * (n + 1)) / 2;

      
        long long notSoGood = 0;

        long long i = 0, j = 0;

        
        unordered_map<int, long long> freq;

        long long currCount = 0;

        long long a;

        for (; i < n && j < n; j++) {
            a = nums[j];


            if (freq.count(a)) {
                currCount -= (freq[a] * 1ll * (freq[a] - 1)) / 2;
                freq[a]++;
                currCount += (freq[a] * 1ll * (freq[a] - 1)) / 2;
            } else {
                freq[a]++;
            }

            if (currCount < k) {
                notSoGood += (j - i + 1);
            } else {
                
                while (i < j) {
                    currCount -=
                        (freq[nums[i]] * 1ll * (freq[nums[i]] - 1)) / 2;
                    freq[nums[i]]--;
                    currCount +=
                        (freq[nums[i]] * 1ll * (freq[nums[i]] - 1)) / 2;

                    if (freq[nums[i]] == 0) {
                        freq.erase(nums[i]);
                    }

                    i++;

                    if (currCount < k) {
                        break;
                    }
                }

                notSoGood += (j - i + 1);
            }
        }

        long long ans = total - notSoGood;

        return ans;
    }
};