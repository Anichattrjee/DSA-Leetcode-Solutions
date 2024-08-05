class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
    int maxlen=0,maxf=0;
    int changes=0;
    int l=0,r=0;
    map<char,int>mp;

    while(r<n)
    {
        mp[s[r]]++;
        int len=r-l+1;
        maxf=max(maxf,mp[s[r]]);
        changes=len-maxf;
        
        if(changes>k)
        {
            mp[s[l]]--;
            l++;
            maxf=0;
        }
        else
        {
            maxlen=max(maxlen,r-l+1);
        }
        r++;

    }
    return maxlen;
    }
};