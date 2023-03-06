class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0,high=arr.size();

        while(low<high)
        {
            int mid=(low+high)/2;

            if(arr[mid]-mid>k) high=mid;
            else low=mid+1;
        }
        return high +k;
    }
};