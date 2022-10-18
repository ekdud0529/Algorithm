#include <string>
#include <algorithm>
using namespace std;

string changNum(int num, int n)
{
    string s = "";
    
    while (num)
    {
        int r = num % n;
        if (r < 10)
            s += (r + '0');
        else
        {
            s += (r - 10) + 'A';
        }
        num /= n;
    }
    reverse(s.begin(), s.end());
    return (s);
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string number = "01";
    int turn = 1;
    
    for(int i=2; i<=100000; i++)
    {
        number += changNum(i, n);
    }
    for(int i=0; answer.size() < t; i++)
    {
        if(turn == p)
        {
            answer += number[i];
        }
        turn++;
        if(turn > m) turn = 1;
    }
    return answer;
}
