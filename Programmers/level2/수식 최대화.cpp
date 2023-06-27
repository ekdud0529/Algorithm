#include <string>
#include <vector>
using namespace std;

bool visited[3];
char operate[3] = {'+', '-', '*'};
vector<long long> num;
vector<char> op;
long long ans = 0;

long long strToLLong(string s)
{
    long long num = 0;
    
    for(char c : s)
    {
        num = (num * 10) + (c - '0');
    }
    return (num);
}

void separate(string expression)
{
    string s = "";

    for(char c : expression)
    {
        if(c == '*' || c == '+' || c == '-')
        {
            num.push_back(strToLLong(s));
            op.push_back(c);
            s = "";
        }
        else
            s += c;        
    }
    num.push_back(strToLLong(s));
}

long long calculate(long long a, long long b, char op)
{
    if(op == '+')
        return (a + b);
    else if(op == '-')
        return (a - b);
    return (a * b);
}

void dfs(vector<long long> number, vector<char> oper)
{
    if(number.size() == 1)
    {
        if(abs(number[0]) > ans)
            ans = abs(number[0]);
        return ;
    }
    for(int i=0; i<3; i++)
    {
        if(visited[i]) continue;
        vector<long long> numCpy(number.begin(), number.end());
        vector<char> operCpy(oper.begin(), oper.end());
        for(int j=0; j<operCpy.size(); j++)
        {
            if(operate[i] == operCpy[j])
            {
                numCpy[j] = calculate(numCpy[j], numCpy[j+1], operate[i]);
                numCpy.erase(numCpy.begin() + (j+1));
                operCpy.erase(operCpy.begin() + j);
                j--;
            }
        }
        visited[i] = true;
        dfs(numCpy, operCpy);
        visited[i] = false;
    }
}

long long solution(string expression) {
    long long answer = 0;
    
    separate(expression);
    dfs(num, op);
    answer = ans;
    return answer;
}
