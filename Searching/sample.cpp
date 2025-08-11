#include <iostream>
#include <vector>
using namespace std;

bool canFormTriangle(vector<int>&v){
    sort(v.begin(),v.end());

    for(int i=0;i<v.size()-2;i++){
        if( (v[i]+v[i+1]>v[i+2]) && v[i]>0 && v[i+1]>0 && v[i+2]>0 ){
            return 1;
        }
    }
    return 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tt,n;
    cin>>tt;


    while (tt--) {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        if(canFormTriangle(v)){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
        cout<<endl;
    }

    return 0;
}