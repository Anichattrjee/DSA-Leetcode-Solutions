class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n=a.size();
        vector<int>nsr;
        vector<int>nsl;
        vector<int>width;
        stack<pair<int,int>>st;

        //finding the nsr index
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                nsr.push_back(a.size());
            }
            else if(st.size()!=0 && st.top().first<a[i])
            {
                nsr.push_back(st.top().second);
            }
            else{
                while(!st.empty() && st.top().first>=a[i])
                {
                    st.pop();
                }
                if(st.empty())nsr.push_back(a.size());
                else nsr.push_back(st.top().second);
            }
            st.push({a[i],i});
        }
        //we need to reverse the vector now because we are starting from reverse order
        //just like we did in case of ngr and nsr
        reverse(nsr.begin(),nsr.end());

        //now we need to empty the stack
        while(!st.empty())
        {
            st.pop();
        }

        // //finding the nsl index
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                nsl.push_back(-1);
            }
            else if(st.size()!=0 && st.top().first<a[i])
            {
                nsl.push_back(st.top().second);
            }
            else{
                while(!st.empty() && st.top().first>=a[i])
                {
                    st.pop();
                }
                if(st.empty())nsl.push_back(-1);
                else nsl.push_back(st.top().second);
            }
            st.push({a[i],i});
        }

        for(int i=0;i<n;i++)
        {
            width.push_back(nsr[i]-nsl[i]-1);
            width[i]=width[i]*a[i];
        }

        int maxArea=*max_element(width.begin(),width.end());

        return maxArea;

    }
};