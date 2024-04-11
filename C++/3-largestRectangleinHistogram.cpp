#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // initialize the maxArea to 0
        int maxArea = 0;
        // make a stack to store the heights and their indexes using pairs 
        stack<pair<int,int>> s;

        // loop through the heights vector
        for(int i=0;i<=heights.size();i++){

            // if the current height is the last element in the vector then we set the current height to 0 otherwise we set it to the current height
            int currentHeight = (i==heights.size()) ? 0 : heights[i];

            // if stack != empty and currHeigt < stack.top().second then we calculate the maxArea til that point
            while(!s.empty() && currentHeight < s.top().second){
                // we pop the top element and store it in a pair
                pair<int, int> tp;
                tp = s.top();
                s.pop();
                // we calculate the width of the rectangle
                int width = (s.empty()) ? i : i - s.top().first - 1;
                // we calculate the maxArea
                maxArea = max(maxArea, tp.second * width); 
            } 
            // if stack is empty or currentHeight >= stack.top().second then we push the current height and its index into the stack
            s.push({i, currentHeight});
        }
        // return the maxArea
        return maxArea;
    }
};

int main(){
    Solution s;
    vector<int> heights = {2,1,5,6,2,3};
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}