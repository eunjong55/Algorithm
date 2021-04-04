#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int map[300][300];
int dr[] = {-2, -2, 2, 2, -1, +1, -1, +1};
int dc[] = {-1, +1, -1, +1, -2, -2, 2, 2};

bool check(int mapLen, int r, int c)
{
  if(r<0 || c<0) return false;
  if(r>=mapLen || c>=mapLen) return false;
  if(map[r][c] == 1) return false;
  return true; 
}

int bfs(int mapLen, int s_r, int s_c, int e_r, int e_c)
{
  queue<pair<int, int>> q;
  q.push(make_pair(s_r, s_c));
  int len = 0;

  while(!q.empty())
  {
    int qSize = q.size();
    for(int i=0; i<qSize; i++)
    {
      int now_r = q.front().first;
      int now_c = q.front().second;
      if(now_r==e_r && now_c == e_c) return len;
      q.pop();

      for(int j=0; j<8; j++)
      {
        int next_r = now_r + dr[j];
        int next_c = now_c + dc[j];
        if(check(mapLen, next_r, next_c))
        {
          map[next_r][next_c] =1;
          q.push(make_pair(next_r, next_c));
        }
      }
    }
    len++;
  }
  return len;
}

int main(){
  int n;
  scanf("%d", &n);
  int res[n];

  for(int i=0; i<n; i++)
  {
    int mapLen;
    int s_r, s_c;
    int e_r, e_c;
    scanf("%d %d %d %d %d", &mapLen, &s_r, &s_c, &e_r, &e_c);
    memset(map, 0, sizeof(map));
    res[i] = bfs(mapLen, s_r, s_c, e_r, e_c);
  }

  for(int i=0; i<n; i++) printf("%d\n", res[i]);
}
