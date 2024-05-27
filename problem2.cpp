#include<bits/stdc++.h>
using namespace std;
/**
 * /**
 * You are given an array of integers. In one second, you can pick a number 'x' which is present in the array and for all the occurrences of 'x', replace the values of the adjacent indexes with value 'x'.

Find the minimum time needed to convert all the indexes of the array with the same value.


5
1
2
3
4
5
Output

2
Explanation

arr = [1,2,3,4,5]

If we pick value 3.

There is only one 3 in index 2. So convert index 1 and 3 with value 3.

So, after 1st second the array becomes arr = [1,3,3,3,5].

After 2 second the array becomes arr = [3,3,3,3,3]. So the minimum answer is 2.

It can be proved that there is no other way to get less than 2.

Input

5
1
2
1
4
1
Output

1

*/
unordered_map<int,vector<int>>mp;
vector<int>arr;
unordered_set<int>s;
int f(int idx){
    queue<int>qu;
    unordered_map<int,int>tp ;/// matches to timmming
    for(auto ele : mp[arr[idx]]){
        qu.push(ele);
        s.insert(ele);
        tp[ele]=0;
    }
    while(!qu.empty()){
        int eleidx = qu.front();
 
        qu.pop();
                if(!s.count(eleidx -1) and ( eleidx-1 >=0)){
                   qu.push(eleidx-1);
                   s.insert(eleidx-1);
                   tp[eleidx-1]= tp[eleidx]+1;

                }
                if(!s.count(eleidx +1) and(eleidx+1 <arr.size() )){
                   qu.push(eleidx+1);
                   s.insert(eleidx+1);
                   tp[eleidx+1]=tp[eleidx]+1;

                }
        
    }
    int ans = INT_MIN;
    for(auto ele : tp){
        ans= max(ans,ele.second);
    }
    return ans;
}
int main(){
    unordered_set<int>st;
    s=st;
    unordered_map<int,vector<int>>m;
    mp=m;
    vector<int>ar{1,2,3,4,5};
    arr=ar;

    for(int i=0; i<arr.size(); i++){
        if(mp.find(arr[i])!= mp.end())mp[arr[i]].push_back(i);
        else{
            mp[arr[i]].push_back(i);
        }
    }
    vector<int>ans1;
    int i=0;
    // cout<<f(0);
    cout<<f(1);
    return 0;
}