#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {

        int n = a.size();

        // if the size of the vector is less than 1 then we return an empty vector
        if(n<1){
            return {};
        }

        // make a stack to store the values of the asteroids after the collision 
        // stack is a good data strcuture to use because we can easily compare the top of the stack with the current element
        stack<int> ans;
        for(int i= 0; i<n; i++){
            // we push the current element into the stack 
            ans.push(a[i]);

            while(ans.size()>=2){
                // we pop out the top element and store it in temp then compare it with the new top element
                 int temp = ans.top();
                ans.pop();
                // this means that top goes left and temp goes right - they don't collide by themselves
                if(ans.top() <= 0 && temp > 0){
                    ans.push(temp);
                    break;
                }
                // this is if they collide 
                else if(ans.top() > 0 && temp < 0){
                    // asteroid with negative value is bigger
                    if(abs(temp) > ans.top()){
                        ans.pop();
                        ans.push(temp);
                    }
                    // asteroid with positive value is bigger
                    else if(abs(temp) == ans.top()){
                        ans.pop();
                    }
                }
                // if they don't collide (both moving in same direction)
                else{
                    ans.push(temp);
                    break;
                }
            }    
        }

        vector<int> res;
        while(!ans.empty()){
            res.push_back(ans.top());
            ans.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }

};


int main(){
    Solution s;
    vector<int> a = {5, 10, -5};
    vector<int> ans = s.asteroidCollision(a);
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}