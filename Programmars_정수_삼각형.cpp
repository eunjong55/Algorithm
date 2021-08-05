#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int max = -1;
    int height = triangle.size();
    for(int i=1; i<height; i++)
    {
        int width = triangle[i].size();
        for(int j=0; j<triangle[i].size(); j++)
        {
            if(j==0) triangle[i][j] += triangle[i-1][j];
            else if(j==(width-1)) triangle[i][j] += triangle[i-1][j-1];
            else 
            {
                if(triangle[i-1][j-1]<triangle[i-1][j])
                {
                    triangle[i][j] += triangle[i-1][j];
                }
                else triangle[i][j] += triangle[i-1][j-1];
            }
            // cout << triangle[i][j] << " ";
        }
        // cout<<endl;
    }
    for(int i=0; i<triangle[height-1].size();i++)
        if(max<triangle[height-1][i]) max = triangle[height-1][i]; 
    
    return max;
}