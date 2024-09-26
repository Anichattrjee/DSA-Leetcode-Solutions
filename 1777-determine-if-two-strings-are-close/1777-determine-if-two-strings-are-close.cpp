class Solution {
public:
    bool closeStrings(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();

        if(n!=m)return false;

        int a[26]={0};
        int b[26]={0};

        for(int i=0;i<n;i++)
        {
            a[w1[i]-'a']++;
        }

        for(int i=0;i<m;i++)
        {
            b[w2[i]-'a']++;
        }
        //checking if theres any char that is not present in one of the string
        for(int i=0;i<26;i++)
        {
            if((a[i]!=0 && b[i]==0) || (a[i]==0 && b[i]!=0))
            {
                return false;
            } 
        }


        //checking if freq sets are same of not
        sort(a,a+26);
        sort(b,b+26);

        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
        }

        return true;
    }
};