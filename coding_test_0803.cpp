#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>


using namespace std;

int blocks[4][4];
int visited[4][4] = {0 };
int max_depth_map[4][4];

bool isFeasible(int row, int col, int color)
{
  if(row<0 || row >=4 || col <0 || col>=4) return 0;
  if(blocks[row][col] != color) return 0;
  if(visited[row][col] == 1) return 0;

  return 1;
}

int dfs(int row, int col, int color)
{
  if(max_depth_map[row][col]!= -1) return max_depth_map[row][col];

  visited[row][col] = 1;

  int max = 0;
  int top= 0;
  int bottom=0;
  int left=0;
  int right=0;

  if(isFeasible(row-1,col, color) == true) top = dfs(row-1, col, color);
  if(isFeasible(row+1,col, color) == true) bottom = dfs(row+1, col, color);
  if(isFeasible(row,col-1, color) == true) left = dfs(row, col-1, color);
  if(isFeasible(row,col+1, color) == true) right = dfs(row, col+1, color);


  if(max<top) max = top;
  if(max<bottom) max = bottom;
  if(max<left) max = left;
  if(max<right) max = right;

  max_depth_map[row][col] = max+1;
  return max+1;
}

int main()
{
  memset(max_depth_map, -1, 16*sizeof(int));
  for(int i=0; i<4; i++)
  {
    for(int j=0; j<4; j++)
    {
      scanf("%d", &blocks[i][j]);
    }
  }

  for(int i=0; i<4; i++)
  {
    for(int j=0; j<4; j++)
    {
      dfs(i, j, blocks[i][j]);
    }
  }

  int max = -1;

  for(int i=0; i<4; i++)
  {
    for(int j=0; j<4; j++)
    {
      if(max<max_depth_map[i][j])max = max_depth_map[i][j];
    }
  }

  printf("%d", max);

  return 0;
}
