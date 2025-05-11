class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;

        for(int num : arr) {

            if(num % 2 != 0) count++;
            else if(count >= 3) return true;
            else count = 0;

        }

        return count >= 3;
        
    }
};