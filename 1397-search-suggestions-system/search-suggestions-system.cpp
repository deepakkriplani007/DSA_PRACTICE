#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        string prefix = "";
        for (char ch : searchWord) {
            prefix += ch;
            vector<string> suggestions;
            for (auto& prod : products) {
                if (prod.substr(0, prefix.size()) == prefix) {
                    suggestions.push_back(prod);
                    if (suggestions.size() == 3) break;
                }
            }
            result.push_back(suggestions);
        }
        return result;
    }
};
