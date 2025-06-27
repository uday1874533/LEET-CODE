import java.util.*;

class Solution {
    public String longestSubsequenceRepeatedK(String s, int k) {
        String result = "";
        Queue<String> queue = new LinkedList<>();
        queue.offer("");

        while (!queue.isEmpty()) {
            String current = queue.poll();
            for (char c = 'a'; c <= 'z'; c++) {
                String candidate = current + c;
                if (isValid(candidate, s, k)) {
                    if (candidate.length() > result.length() || 
                       (candidate.length() == result.length() && candidate.compareTo(result) > 0)) {
                        result = candidate;
                    }
                    queue.offer(candidate);
                }
            }
        }

        return result;
    }

    private boolean isValid(String pattern, String source, int k) {
        int i = 0, count = 0;
        for (char ch : source.toCharArray()) {
            if (ch == pattern.charAt(i)) {
                i++;
                if (i == pattern.length()) {
                    count++;
                    i = 0;
                    if (count == k) return true;
                }
            }
        }
        return false;
    }
}
