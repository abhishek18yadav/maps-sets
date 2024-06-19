#include<bits/stdc++.h>

using namespace std;
#define pp pair<string , int>
//  https://leetcode.com/problems/count-the-number-of-special-characters-ii/
int numberOfSpecialChars(string word) {
        unordered_map<char , vector<int>>mp;
        for(int i=0; i<word.size(); i++){
            mp[word[i]].push_back(i);
        }
        int count=0;
        for(auto ele : mp){
            int asci = int(ele.first);
            if(asci < 97){
                if(mp.find(char(asci + 32)) != mp.end()){
                    bool right=true;
                    for(auto e : (mp[char(asci + 32)])){
                        if(e > ele.second[0]) right = false;
                    }
                    if(right)count++;
                }
            }
        }
        return count;
    }



int main(){
    cout<<numberOfSpecialChars("AbBCab");
    return 0;
}