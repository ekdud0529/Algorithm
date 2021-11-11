#include <string>
#include <vector>

using namespace std;

string mk_num(int n)
{
    string num = "";
    int size = 0;
    
    if(n == 0) return "0";
    
    for(int i=0; n!=0; i++)
    {
        num += n%10 + '0';
        n /= 10;
    }
    size = num.size();
    for(int k=0; k<size/2; k++)
    {
        char tmp = num[k];
        num[k] = num[size-1 - k];
        num[size-1 - k] = tmp;
    }
    
    return num;
}

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    for(int i=0; i<seoul.size(); i++)
    {
        if(seoul[i] == "Kim")
        {
            answer += mk_num(i);
            break;
        }
    }
    answer += "에 있다";
    return answer;
}
