#include<bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
struct hashfun{
    size_t operator()(
         const pp &x
    )const{
        return  x.first ^ x.second;
    }
};

int main(){
    unordered_set<pp,hashfun>st;
    pp a1 = {1,2};
    pp a2 = {2,3};
    pp a3 = {2,3};
    st.insert(a1);
    st.insert(a2);
    st.insert(a3);
    cout<<st.size();
    return 0;
}