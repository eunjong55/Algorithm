#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;
void dfs(int x, int y);

int map[25][25];
int group_count = 0;
int cnt = 0;
int member_cnt[625];

int n;
bool compare(int f, int s)
{
  if(f<s) return true;
  else return false;
}

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      scanf("%1d", &map[i][j]);
    }
  }
  
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      if(map[i][j] == 1) 
      {
        cnt = 0;
        dfs(i, j);
        member_cnt[group_count]=cnt;
        group_count+=1;
      }
    }
  }
  printf("%d\n", group_count);
  sort(member_cnt, member_cnt+group_count, compare);
  for(int i=0; i<group_count; i++) printf("%d\n", member_cnt[i]);
}

void dfs(int x, int y)
{
  map[x][y] = 0;
  cnt+=1;
  if(x-1>0 && map[x-1][y] == 1)//x-1
  {
    dfs(x-1, y);
  }
  if(x+1<n && map[x+1][y] == 1)//x+1
  {
    dfs(x+1, y);
  }
  if(y-1>0 && map[x][y-1] == 1)//y-1
  {
    dfs(x, y-1);
  }
  if(y+1<n && map[x][y+1] == 1)//y+1
  {
    dfs(x, y+1);
  }
}
