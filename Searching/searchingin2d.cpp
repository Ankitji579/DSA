#include <bits/stdc++.h>
using namespace std;

int findElement(int row,int col,vector<vector<int>>& matrix,int target){
    int start= 0;
    int end= (row*col)-1;
    int mid = start+(end-start)/2;

    int row_index= mid/col;
    int col_index=mid%col;

    // return matrix[row_index][col_index];


    while(start<=end){
      int mid = start+(end-start)/2;
      int row_index= mid/col;
      int col_index=mid%col;
      if(matrix[row_index][col_index]==target){
        return matrix[row_index][col_index];
      }
      else if(matrix[row_index][col_index]>target){
        end = mid-1;
      }
      else{
        start=mid+1;
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

    int row=3;
    int col=3;
    int target = 9;
    vector<vector<int>>matrix= {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };


    cout<<findElement(row,col,matrix,target);


  return 0;
}