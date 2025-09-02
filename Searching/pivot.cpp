#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    
    int findpivot(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        

        while(e>=s){
            int mid = s + (e-s)/2;
            if(mid+1 < nums.size() && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(mid-1>= 0&&nums[mid-1]>nums[mid]){
                return mid-1;
            }
            else if(nums[s]>=nums[mid]){
                e = mid-1;
                
            }
            else{
                s = mid+1;
            }
        }
        return -1;
    }
    


};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endifd new 

    vector<int>nums{7,1,2,3,4,5};

    Solution ob;
    int ans = ob.findpivot(nums);
    cout<<ans<<endl;
    cout<<nums[ans];

}
