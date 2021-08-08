#include <string>
#include <vector>
#include <stack>
#include <stdio.h>

using namespace std;

int cur;
stack<int> st;

int siz;

string solution(int n, int k, vector<string> cmd) {
    siz = n;
    cur = k;
    
    for(int i=0; i<cmd.size(); i++)
    {
        if(cmd[i][0] == 'C')
        {
            st.push(cur);
            siz--;
            if(siz==cur) cur--;
        }
        if(cmd[i][0] == 'Z')
        {
            int num = st.top();
            st.pop();
            if(cur>=num) cur++;
            siz++;
        }
        if(cmd[i][0] == 'U') 
        {
            cmd[i][0] = ' ';
            cur -=stoi(cmd[i]); 
        }
        if(cmd[i][0] == 'D')
        {
            cmd[i][0] = ' ';
            cur+=stoi(cmd[i]);
        }
    }
    
    string answer = "";
    answer.append(siz, 'O');

    while(!st.empty())
    {
        answer.insert(st.top(), "X");
        st.pop();
    }
    
    return answer;
}