class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,r=0,maxlen=0;
        map<char,int>mp;

        while(r<n)
        {
            char c=s[r];
            //if map contains the element then check whether the index of the char is greater than l or not
            if(mp.find(c)!=mp.end())
            {
                //if greater than then shrink the window(l=map[s[r]]+1);
                if(mp[c]>=l)
                {
                    l=mp[c]+1;
                }
            }
            maxlen=max(maxlen,r-l+1);
            mp[c]=r;
            r++;
        }
        return maxlen;
    }
};