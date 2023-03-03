class Solution {
public:
    int strStr(string haystack, string needle) {
     int i(0), j(0);
        int n = haystack.size();
        int m = needle.size();

        while(i<n-m+1){
            if(j >= m) return i;
            if(haystack[i+j] != needle[j]){
                j = 0;
                i++;
            } else j++;
        }
        return -1;
    }
};
 