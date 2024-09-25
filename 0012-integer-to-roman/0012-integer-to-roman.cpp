class Solution {
public:
    string intToRoman(int n) {
        vector<int>num{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string>rom{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res="";
        int times=0;
        int rem=0;

        int min=INT_MAX;

        for(int i=0;i<num.size();i++)
        {
            if(n==0)break;
            times=n/num[i];
            while(times--)
            {
                res+=rom[i];
            }
            n=n%num[i];

        }
        return res;
    }
};