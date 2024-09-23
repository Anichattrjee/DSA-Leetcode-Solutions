class Solution {
public:
    bool checkIfPangram(string s) {
        if(s.empty())return false;
    int arr[26]={0};

    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        if(arr[c-'a']==0)
        {
            arr[c-'a']=1;
        }
    }
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)return false;
    }

    return true;
    }
};