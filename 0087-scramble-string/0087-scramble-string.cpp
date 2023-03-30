//Memoization + Pruning
class Solution {
    unordered_map<string,bool> mem;
    bool solve(string s1,string s2)
    {
        if(s1.size()==1)
            return s1==s2;
        if(s1==s2)
            return true;
        string key=s1+s2;
        if(mem.find(key)!=mem.end())
            return mem[key];
        
        //Pruning: Avoid Unnecessary recursion calls
        int n=s1.size();
        vector<int> f1(26),f2(26);
        for(int i=0;i<n;++i)
        {
            f1[s1[i]-'a']+=1;
            f2[s2[i]-'a']+=1;
        }
        if(f1!=f2)
            return mem[key]=false;
        
        bool res = false;
        for(int i=1;i<n;++i)
        {
            if((solve(s1.substr(0,i),s2.substr(0,i)) and solve(s1.substr(i),s2.substr(i)))
               or(solve(s1.substr(0,i),s2.substr(n-i)) and solve(s1.substr(i),s2.substr(0,n-i))))
                return mem[key]=true;
        }
        return mem[key]=false;
    }
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        return solve(s1,s2);
    }
};