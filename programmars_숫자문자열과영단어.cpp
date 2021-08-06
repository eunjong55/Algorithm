#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(string s) {
    
    map<string, int> dict;
    dict["zero"] = 0;
    dict["one"] = 1;
    dict["two"] = 2;
    dict["three"] = 3;
    dict["four"] = 4;
    dict["five"] = 5;
    dict["six"] = 6;
    dict["seven"] = 7;
    dict["eight"] = 8;
    dict["nine"] = 9;

    long long answer = 0;
    
    string tmp="";
    
    for(int i=0; i<s.length(); i++)
    {
        if(isdigit(s.at(i)))
        {
            answer = answer* 10 + (s.at(i) - '0');
        }
        else
        {
            tmp += s.at(i);
            if(dict.find(tmp) != dict.end())
            {
                answer = answer*10 + dict[tmp];
                tmp.clear();
            }
        }
    }
    return answer;
}