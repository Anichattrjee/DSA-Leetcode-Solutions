class Solution {
public:
    int maxProduct(vector<string>& words) {
         //1. Mask every word in 26 bit
        //2. Nested loop if mask[i]& mask[j]==0 update the length of their product

        int n=words.size();
        vector<int>mask(n,0);
        //convert each word into a 26 bit mask
        for(int i=0;i<n;i++)
        {
            int m=words[i].length();
            for(int j=0;j<m;j++)
            {
                int bitIndex=words[i][j]-'a';
                mask[i]=mask[i] | (1<<bitIndex);
            }
        }
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            int product=0;
            for(int j=0;j<n;j++)
            {
                if((mask[i] & mask[j])==0)
                {
                    product=words[i].length() * words[j].length();
                }
                maxlen=max(product,maxlen);
            }
        }
        return maxlen;
    }
};