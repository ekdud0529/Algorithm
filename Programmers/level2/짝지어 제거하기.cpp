#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> str;
    int size = s.size();
    
    for(int i=0; i<size; i++){
        if(!str.empty() && s[i] == str.top()){
            str.pop();
        }
        else str.push(s[i]);
    }
    
    if(str.empty()) answer = 1;
    else answer = 0;

    return answer;
}
