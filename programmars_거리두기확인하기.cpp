#include <string>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

int visited[5][5];

bool isFeasible( vector<string> places, int row, int col)
{
    if(row<0 || row>=5 || col<0 || col>=5) return false;
    if(places[row].at(col) == 'X') return false;
    if(visited[row][col] == true) return false;
    
    return true;
}

int dfs(vector<string> places, int row, int col, int depth)
{
    if(depth > 2) return 0;
    if(depth>0 &&depth <=2 && places[row].at(col) == 'P') return 1;
    
    visited[row][col] = true;
    if(isFeasible(places, row-1, col)){
        if (dfs(places, row-1, col, depth+1) == 1) return 1;
    }
    if(isFeasible(places, row+1, col)){
        if (dfs(places, row+1, col, depth+1) == 1) return 1;
    }
    if(isFeasible(places, row, col-1)){
        if (dfs(places, row, col-1, depth+1) == 1) return 1;
    }
    if(isFeasible(places, row, col+1)){
        if (dfs(places, row, col+1, depth+1) == 1) return 1;
    }
    return 0;
}

int check(vector<string> p)
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(p[i].at(j) == 'P')
            {
                if(dfs(p, i, j, 0)==1) return 1;
            }
        }
    }
    return 0;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0; i<5; i++)
    {
        memset(visited, 0, sizeof(int)*25);
        answer.push_back( (check(places[i]) == 1)?0:1);
    }
    return answer;
}