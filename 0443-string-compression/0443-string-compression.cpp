class Solution {
public:
    int compress(vector<char>& a) {
        int n=a.size();
    char curr_char;
    int ind=0;
    int i=0;

    while(i<n)
    {
        curr_char=a[i];
        int cnt=0;

        while(i<n && a[i]==curr_char)
        {
            cnt++;
            i++;
        }
        a[ind]=curr_char;
        ind++;
        
        if(cnt>1)
        {
            string s=to_string(cnt);
            for(char &ch:s)
            {
                a[ind]=ch;
                ind++;
            }
        }
    }
    return ind;
    }
};