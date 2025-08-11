#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> firstOcc(vector<int>& v,int target){
  int s = 0;
  int e = v.size()-1;
  
  int left = -1;
  int right = -1;
  
  
  while(s<=e){
    int mid = s +((e-s)/2);
    
    if(v[mid] == target){
      // ans store and move to left
      left = mid;
      e = mid-1;
    }
    else if(target>v[mid]){
      // move to right
      s = mid+1;
    }
    else if(target<v[mid]){
      // move to left
      e = mid -1;
    }
  }
   s = 0;
   e = v.size()-1;
    while(s<=e){
    int mid = s +((e-s)/2);
    
    if(v[mid] == target){
      // ans store and move to right
      right = mid;
      s = mid+1;
    }
    else if(target>v[mid]){
      // move to right
      s = mid+1;
    }
    else if(target<v[mid]){
      // move to left
      e = mid -1;
    }
  }
  return {left,right};

  
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
  
  vector<int>v{5,7,7,8,8,10};
  // sort(v.begin(),v.end());
  
  int target;
  cin>>target;
  vector<int> indexFirstOcc = firstOcc(v,target); 
  

  for(auto& a: indexFirstOcc){
    cout<<a<<" ";
  }
  cout<<endl<<endl;
  
  auto b = lower_bound(v.begin(),v.end(),8);
  auto c = upper_bound(v.begin(),v.end(),8);

  cout<<b-v.begin()<<" ";
  cout<<c-v.begin()-1;

  return 0;
}