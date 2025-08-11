#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

void solve() {


    string str;
    cin>>str;

    int count =0;
    char cur = 'a';

    for(char ch:str){
    
    int distance  = abs(int(ch)- int(cur));
    int opp_dis = 26-distance;
    int min_rot = min(distance,opp_dis);
    count += min_rot;
    
    cur = ch;
    }
    cout<<count;
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}