class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string>segments;
        unordered_set<string>seen;
        string currentSegment="";

        for( char c:s)
            {
                currentSegment+=c;
                //find in the set-if not there add to answer and move to next index to start a new currentSegment otherwise add the next char to currentSegment
                if(seen.find(currentSegment)==seen.end())
                {
                    segments.push_back(currentSegment);
                    seen.insert(currentSegment);
                    //make the current segment empty
                    currentSegment="";
                }
            }
        return segments;
    }
};