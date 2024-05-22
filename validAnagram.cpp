#include<bits/stdc++.h>
using namespace std;
 bool isAnagram(string s, string t) {
    if (s.size()!=t.size())return false;
        unordered_map<char,int>mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        for(int i=0; i<t.length(); i++){
            if(mp.find(t[i])!= mp.end()){
                // i find it
                mp[t[i]]--;
            }
            else return false;
        }
        bool iskeypresent = true;
        for(auto ele : mp){
            if(ele.second>0)iskeypresent=false;
        }
        return iskeypresent;
    }
int main(){
    cout<<isAnagram("anagram","nagaram");
    return 0;
}