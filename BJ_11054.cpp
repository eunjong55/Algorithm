//problem link : https://www.acmicpc.net/problem/11054

#include <cstdio>

using namespace std;

int seq[1000];
int n;
int asc_best[1000];
int dec_best[1000];
int cnt = 0;
int asc_cnt[1000];
int dec_cnt[1000];

int find_loc(int target, int best[])
{
  int left = 0;
  int right = cnt-1;

  while(left<=right)
  {
    int mid = left + (right-left)/2;
    if(best[mid] < target) left = mid+1;
    else right = mid-1;
  }
  return right +1;
}


int main()
{
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &seq[i]);

  for(int i=0; i<n; i++)
  {
    if (i == 0)
    {
      asc_best[0] = seq[i];
      cnt += 1;
    }
    else
    {
      if(asc_best[cnt-1] < seq[i])
      {
        asc_best[cnt] = seq[i];
        cnt += 1;
      }
      else
      {
        int loc = find_loc(seq[i], asc_best);
        asc_best[loc] = seq[i];
      }
    }
    asc_cnt[i] = cnt;
  }

  cnt = 0;
  for(int i=0; i<n; i++)
  {
    if (i == 0)
    {
      dec_best[0] = seq[n-1];
      cnt += 1;
    }
    else
    {
      if(dec_best[cnt-1] < seq[n-1-i])
      {
        dec_best[cnt] = seq[n-1-i];
        cnt += 1;
      }
      else
      {
        int loc = find_loc(seq[n-1-i], dec_best);
        dec_best[loc] = seq[n-1-i];
      }
    }
    dec_cnt[i] = cnt;
  }
  int max = -1;
  for(int i=0; i<n; i++)
  {
    max = asc_cnt[i] + dec_cnt[n-1-i] -1 > max? asc_cnt[i] + dec_cnt[n-1-i] -1 : max;
  }
  printf("%d", max);
}