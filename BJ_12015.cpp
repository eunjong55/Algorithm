problem link : https://www.acmicpc.net/submit/12015/26605176

#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int nums[n];
  memset(nums, 0, sizeof(nums));
  int cnt = 0;

  for(int i=0; i<n; i++)
  {
    int num;
    scanf("%d", &num);

    if(i==0)
    {
      nums[0] = num;
      cnt+=1;
      continue;
    }
    if(nums[cnt-1] < num){
      nums[cnt] = num;
      cnt+=1;
    }
    else
    {
      int left = 0;
      int right = cnt-1;
      while(left<=right)
      {
        int mid = left+ (right-left)/2;
        if(nums[mid] < num) left = mid +1;
        else right = mid -1;
      }
      nums[right+1] = num;
    }
  }
  printf("%d", cnt);
  return 0;
}