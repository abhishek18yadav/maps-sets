#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/submissions/1269676775/
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int, vector<int>>mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]] = {i};
            }
            else{
                mp[nums[i]].push_back(i);
            }
        }
        vector<int>res;
        for(int i=0; i<queries.size(); i++){
            if(queries[i] > mp[x].size())res.push_back(-1);
            else{
                res.push_back(mp[x][queries[i]-1]);
            }
        }
        return res;
    }
int main(){
    vector<int> nums{1,2,3}; 
    vector<int> queries{10}; 
    int x=5;
    vector<int> res = occurrencesOfElement(nums,queries,x);
    for(auto ele: res){
        cout<<ele<<" ";
    }
    return 0;
}