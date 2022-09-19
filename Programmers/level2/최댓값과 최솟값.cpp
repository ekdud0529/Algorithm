#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;

void getNum(string s)
{
    int n = 0;
    int sign = 1;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '-')
        {
            sign = -1;
            continue;
        }
        if(s[i] == ' ')
        {
            n *= sign;
            num.push_back(n);
            n = 0;
            sign = 1;
            continue;
        }
        n = n * 10 + s[i] - '0';
    }
    num.push_back(n * sign);
}

string makeChar(int n)
{
    string c = "";

    if(n / 10 == 0)
    {
        c = n + '0';
        return (c);
    }
    c = n % 10 + '0'; 
    return (makeChar(n / 10) + c);
}

string solution(string s) {
    string answer = "";
    getNum(s);
    sort(num.begin(), num.end());
    if(num[0] < 0)
    {
        answer += "-";
        num[0] *= -1;
    }
    answer += makeChar(num[0]);
    answer += " ";
    if(num[num.size() - 1] < 0)
    {
        answer += "-";
        num[num.size() - 1] *= -1;
    }
    answer += makeChar(num[num.size() - 1]);
    return answer;
}
