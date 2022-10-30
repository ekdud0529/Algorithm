#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> makeStr(vector<int> num)
{
    vector<string> number;

    for(int n : num)
    {
        string s = "";
        while(n)
        {
            s += (n % 10) + '0';
            n /= 10;
        }
        if(s.size() == 0)
            s += '0';
        reverse(s.begin(), s.end());
        number.push_back(s);
    }
    return (number);
}

int makeNum(string s)
{
    int num = 0;

    for(char c : s)
    {
        num = num * 10 + (c - '0');
    }
    return (num);
}

bool CMP(const string &a, const string &b)
{
    int n1 = makeNum(a + b);
    int n2 = makeNum(b + a);

    if (n1 > n2)
        return (true);
    return (false);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> number;
    
    number = makeStr(numbers);
    sort(number.begin(), number.end(), CMP);
    for(string s : number)
        answer += s;
    if(answer[0] == '0') answer = "0";
    return answer;
}
