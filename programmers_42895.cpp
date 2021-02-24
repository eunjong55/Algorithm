//problem link : https://programmers.co.kr/learn/courses/30/lessons/42895

#include <string>
#include <vector>
#include <set>

using namespace std;
vector<set<int>> record(9);
int solution(int N, int number) {//N : 1~9, number : target
    int answer = 0;

    int nn =N;
    for(int i=1; i<=8; i++)
    {
      set<int> temp;
      temp.insert(nn);
      record[i] = temp;
      nn = nn* 10 +N;
    }
    if(N == number) return 1;
    for(int i=2; i<=8; i++) //0~6 (1씩 빼준거)
    {
      for(int j=1; j<i; j++)
      {
        set<int>::iterator iter1, iter2;
        for(iter1 = record[j].begin(); iter1!=record[j].end(); iter1++)
        {
          for(iter2 = record[i-j].begin(); iter2!=record[i-j].end(); iter2++)
          {
            record[i].insert(*iter1 + *iter2);
            record[i].insert(*iter1 - *iter2);
            record[i].insert(*iter1 * *iter2);
            if(*iter2 != 0){
              record[i].insert(*iter1 / *iter2);
            }
          }
        }
        
        for(iter1 = record[i].begin(); iter1!=record[i].end(); iter1++)
        {
          if(*iter1 == number) return i;
        }
      }
      
    }

    return -1;
}

int main()
{
    int N, number;
    scanf("%d %d", &N, &number);
    printf("%d", solution(N, number));
}