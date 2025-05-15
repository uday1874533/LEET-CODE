class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int tingari1 = 0, tingari2 = s.size() - 1; tingari1 < tingari2; ++tingari1, --tingari2)
            swap(s[tingari1], s[tingari2]);
    }
};
