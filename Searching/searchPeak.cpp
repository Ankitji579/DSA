#include <iostream>
#include <vector>

using namespace std;

int findPeak(vector<int>& arr){
    int start = 0;
    int end = arr.size()-1;
    
    while(start<=end){
        int mid = start + (end-start)/2;

        if((mid == 0 || arr[mid] > arr[mid-1]) && 
        (mid == arr.size()-1 || arr[mid] > arr[mid+1])){
        return mid;
        }

        else if(arr[mid]<arr[mid+1] && mid+1<arr.size()){
            start = mid+1;
        }
        else{
            end = mid-1;
        }

    }
    return -1;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  

    vector<int> arr{1,2,3,4,5,4,3,2,1};
    
    
    cout<<findPeak(arr)<<endl;
    
    cout<<arr[findPeak(arr)];

}