class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        vector<int>temp;
        for(int i=0 ; i<rocks.size() ; i++)
            temp.push_back(capacity[i] - rocks[i]);
        
        sort(temp.begin() , temp.end());
        int count = 0;

        int i = 0;
        while(additionalRocks > 0 and i < temp.size())
        {
            if(additionalRocks >= temp[i])
            {
                count++;
                additionalRocks -= temp[i];
            }
            else
                break;
            i++;
        }
        return count;
    }
};