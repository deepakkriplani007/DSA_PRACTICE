class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0;
        for (int i = 1; i < colors.size(); ++i) {
            if (colors[i] == colors[i - 1]) {
                totalCost += min(neededTime[i], neededTime[i - 1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]); // keep the higher time
            }
        }
        return totalCost;
    }
};
