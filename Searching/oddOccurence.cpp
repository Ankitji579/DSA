#include <bits/stdc++.h>
using namespace std;

int oddOccurence(vector<int>arr){
    int s=0;
    int e=arr.size()-1;
    int mid = s+(e-s)/2;

    // 1,1,2,2,3,3,4,4, 3, 600,600,4,4
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            return arr[mid];
        }
        if(s==e){
            return s;
        }
        if(mid%2==0){
            if((mid+1)%2!=0){
                s =mid+1;
            }
        }
        else{
            e = mid-1;
        }
    }
    return -1;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    vector<int> arr= {1,1,2,2,3,3,4,4,3,600,600,4,4};

    cout<<oddOccurence(arr);

  return 0;
}