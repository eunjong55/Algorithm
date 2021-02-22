//problem link : https://www.acmicpc.net/problem/12865

#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  int w_list[n+1];
  int v_list[n+1];
  int record[k+1][n+1];
  memset(record, 0, sizeof(record));
  int i,j;
  for(i=1; i<=n; i++) scanf("%d %d", &w_list[i], &v_list[i]);

  for(i=1; i<=k; i++)
  {
    for(j=1; j<=n; j++)
    {
      if(i<w_list[j]){
        record[i][j] = record[i][j-1];
        continue;
      }
      record[i][j] = max(record[i][j-1], record[i-w_list[j]][j-1] +v_list[j]);
    }
  }

  printf("%d", record[k][n]);
}