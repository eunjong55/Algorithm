#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>

using namespace std;

int row[9][10] = {0,};
int map[9][9];

void check();
int start();
bool isFeasible(int x, int y, int num);

int ccount = 0;

int main()
{
  for(int i=0; i<9; i++)
  {
    for(int j=0; j<9; j++)
    {
      scanf("%d", &map[i][j]);
    }
  }
  check();
  start();
  printf("\n");
  for(int i=0; i<9; i++)
  {
    for(int j=0; j<9; j++)
    {
      printf("%d ", map[i][j]);
    }
    printf("\n");
  }
  return 0;
}

int start()
{
  int i,j;
  int count = 0;
  int hole_r = -1;
  int hole_c = -1;
  for(i=0; i<9; i++)
  {
    for(j=0; j<9; j++)
    {
      if(map[i][j] == 0)
      {
        count+=1;
        hole_r = i;
        hole_c = j;
        break;
      }
    }
    if(hole_r != -1) break;
  }
  if(count == 0) return 1;

  for(j=1; j<=9; j++)
  {
    if(row[hole_r][j] == 0)
    {
      if(isFeasible(hole_r, hole_c, j))
      {
        row[hole_r][j] = 1;
        map[hole_r][hole_c] = j;

        if(start() == 1) return 1;

        row[hole_r][j] = 0;
        map[hole_r][hole_c] = 0;
      }
    }
  }
  return false;
}

void check()
{
  for(int i=0; i<9; i++)
  {
    for(int j=0; j<9; j++)
    {
      row[i][map[i][j]]=1;
    }
  }
}

bool isFeasible(int row, int col, int num)
{
  for(int i=0; i<9; i++)
  {
    if(map[i][col] == num)
    {
      return false;
    }
  }
  int r, c;
  r = row/3;
  c = col/3;
  for(int i=r*3; i<r*3+3; i++)
  {
    for(int j=c*3; j<c*3+3; j++)
    {
      if(map[i][j] == num)
      {
        return false;
      }
    }
  }
  return true;
}