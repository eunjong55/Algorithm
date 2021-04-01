#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <cmath>

long long tree[4*1000001] = {0, };
long long nums[1000001] = {0, };

long long build_tree(int loc, int left, int right)
{
  if(left == right){
    tree[loc] = nums[left];
  }
  else
  {
    int mid = left+(right-left)/2;
    tree[loc] = build_tree(loc*2, left, mid) + build_tree(loc*2+1, mid+1, right);
  }
  return tree[loc];
}

long long query(int loc, int left, int right, int q_left, int q_right)
{
  if(left>q_right || right<q_left) return 0;
  else if( q_left <= left && right <=q_right) return tree[loc];
  else
  {
    int mid = left+(right-left)/2;
    return query(loc*2, left, mid, q_left, q_right) + query(loc*2+1, mid+1, right, q_left, q_right);
  }
}

void update_tree(int loc, int left, int right, int target, long long diff)
{
  if(target < left || target > right) return;

  tree[loc] += diff;
  
  if( left != right)
  {
    int mid = left+(right-left)/2;
    update_tree(loc*2, left, mid, target, diff);
    update_tree(loc*2+1, mid+1, right, target, diff);
  }
}



int main()
{
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i=1; i<=n; i++) scanf("%lld", &nums[i]);
  int func;
  build_tree(1, 1, n);
  for(int i=0; i<m+k; i++)
  {
    scanf("%d", &func);
    if(func ==1) {
      int num1;
      long long num2;
      scanf("%d %lld", &num1, &num2);
      long long diff = num2-nums[num1];
      nums[num1] = num2;
      update_tree(1, 1, n, num1, diff);
    }
    else 
    {
      int num1, num2;
      scanf("%d %d", &num1, &num2);
      printf("%lld\n", query(1, 1, n, num1, num2));
    }
  }
}
