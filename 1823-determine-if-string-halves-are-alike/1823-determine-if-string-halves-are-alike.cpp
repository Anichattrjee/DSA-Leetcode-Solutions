class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int lc=0;
        int rc=0;
       
        for(int i=0;i<n/2;i++)
        {
            char ch=s[i];
            ch=tolower(ch);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            {
                lc++;
            }
        }

        for(int i=n/2;i<n;i++)
        {
            char ch=s[i];
            ch=tolower(ch);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            {
                rc++;
            }
        }

        if(lc==rc)return true;
        else return false;
    }
};