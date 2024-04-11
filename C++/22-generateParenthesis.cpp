#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string current = "";
        helper(current, 0, 0, ans, n);
        return ans;
    }

private:
    void helper(string current, int open, int close, vector<string> &ans, int n)
    {
        if (current.size() == 2 * n)
        {
            ans.push_back(current);
            return;
        }

        if (open < n)
        {
            helper(current + '(', open + 1, close, ans, n);
        }
        if (close < open)
        {
            helper(current + ')', open, close + 1, ans, n);
        }
    }
};


int main(){
    Solution s;
    int n = 3;
    vector<string> ans = s.generateParenthesis(n);
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}