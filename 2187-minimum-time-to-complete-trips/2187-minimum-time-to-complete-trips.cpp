class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
       int n = time.size();
//         int sum = 0;
//         sort(time.begin(), time.end());
//         float precomp[n];
//         precomp[0] = 1;
//         int ans = 0;
//         for(int i = 1; i<n; i++){
//             precomp[i] = precomp[i-1]*((float)time[i]/(float)time[i-1]) + 1.0;
//             cout<<precomp[i]<<"pc"<<endl;
//         }
//         cout<<endl;

//         if(precomp[n-1] == totalTrips) return time[n-1];
//         else if(precomp[n-1] < totalTrips){
//             cout<<"yes"<<endl;
//             int i = n-1;
//             sum = totalTrips;
//             while(sum>0 && i>=0){
//                 cout<<sum<<" "<<precomp[i]<<" "<<ans<<endl;
//                 int pres = sum;
//                 sum %= (int)precomp[i];
//                 if(pres != sum) ans += time[i]*(pres/(int)precomp[i]);
//                 cout<<sum<<" < "<<precomp[i]<<" "<<ans<<endl;
//                 i--;
//             }
//             if(sum <= 0) return ans;
//             else return -1;
//         } else {
//             cout<<"yes2"<<endl;
//             int l(0), h(n-1);
//             int mid = 0;
//             while(l <= h){
//                 mid = l + (h - l)/2;
//                 cout<<precomp[mid]<<endl;
//                 if((int)precomp[mid] == totalTrips) return time[mid];
//                 else if((int)precomp[mid] > totalTrips) h = mid-1;
//                 else l = mid+1;
//             }
//             cout<<time[l]<<" "<<time[mid]<<" "<<time[h-1]<<endl;
//             return time[h];
//         }
//         return -2;
        
         long long  l(0);
        long long  h = LONG_MAX;
        long long  x = 0;
        while(l <= h){
            x = l + (h-l)/2;
            long long  fx = 0;
            for(auto e:time){
                fx += x/e;
                if(fx > totalTrips) break;
            }
            if(fx < totalTrips) l = x+1;
            else h = x-1;
        }
        return l;
    }
};