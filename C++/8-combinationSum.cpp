#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findComb(0, target, candidates, ans, ds);
        return ans;
    }

private:
    void findComb(int indx, int target, vector<int> candidates,
                  vector<vector<int>> &ans, vector<int> &ds)
    {
        if (indx == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if (candidates[indx] <= target)
        {
            ds.push_back(candidates[indx]);
            findComb(indx, target - candidates[indx], candidates, ans, ds);
            ds.pop_back();
        }

        findComb(indx + 1, target, candidates, ans, ds);
    }
};

int main(){
    Solution s;
    vector<int> candidates = {2,3,5};
    int target = 8;
    vector<vector<int>> ans = s.combinationSum(candidates, target);
    for(auto i: ans){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}