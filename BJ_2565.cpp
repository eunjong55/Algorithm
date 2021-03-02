//problem link : https://www.acmicpc.net/problem/2565

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int, int>> lines;
int cnt = 0;

int find_loc(int target, int best[])
{
  int left = 0;
  int right = cnt-1;
  while(left<=right)
  {
    int mid = (left + right)/2;
    if(best[mid] < target) left = mid+1;
    else right = mid -1;
  }
  return right+1;
}

bool compare(pair<int, int> a, pair<int, int>b)
{
  if(a.first < b.first) return true;
  else return false;
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
    int num1, num2;
    scanf("%d %d",&num1, &num2);
    lines.push_back(make_pair(num1, num2));
  }
  sort(lines.begin(), lines.end(), compare);

  int best[n];
  memset(best, 0, sizeof(best));
  for(int i=0; i<n; i++)
  {
    if(i==0)
    {
      best[0] = lines[0].second;
      cnt+=1;
    }
    else
    {
      if(best[cnt-1] < lines[i].second)
      {
        best[cnt] = lines[i].second;
        cnt+=1;
      }
      else
      {
        int loc = find_loc(lines[i].second, best);
        best[loc] = lines[i].second;
      }
    }
  }
  printf("%d", n-cnt);
}