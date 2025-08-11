//
// Created by Ankit Vashisth on 02/08/24.
//
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        string ans = "";
        char grid[8][8];
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                cin>>grid[i][j];
                if(grid[i][j] !='.')
                {
                    ans += grid[i][j];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}