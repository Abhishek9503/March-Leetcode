class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start =1;
        int high=INT_MAX;
        
    while(start<=high)
    {
        int mid=start+(high-start)/2;
        int fxn=0;
        
        for(int i =0;i<piles.size();i++)
        {
            if(fxn>h) break;
            fxn =fxn +ceil(piles[i]/(double)mid);
        }
        if(fxn>h)
        {
            start=mid+1;
        }
        else
        {
           high= mid-1;
        }
    }
        
          return start;
    }
  
};
