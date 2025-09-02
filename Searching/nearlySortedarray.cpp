#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>arr,int target){
    int s =0;
    int e=arr.size()-1;
    int mid = s+(e-s)/2;

    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid-1]==target && mid-1 >0){
            return mid-1;
        }
        if(arr[mid+1]==target && mid+1 < arr.size()){
            return mid+1;
        }
        if(arr[mid]>target ){
            e= mid-2;
        }
        else{
            s=mid+2;
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

    vector<int> arr{10,3,40,20,50,80,70};
    int target;
    cin>>target;

    int ans = binarySearch(arr,target);

    cout<<ans;

  return 0;
}