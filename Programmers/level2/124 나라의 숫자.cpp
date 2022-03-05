#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> num;
    
    while(n)
    {
        num.push_back(n % 3);
        n /= 3;
    }
    for(int i=0; i<num.size(); i++)
    {
        if((num[i] == 0 || num[i] == -1) && i != num.size()-1)
        {
            num[i+1] -= 1;
            num[i] += 3;
        }
    }
    for(int i=num.size()-1; i>=0; i--)
    {
        if(i == num.size()-1 && num[i] == 0) continue;
        if(num[i] == 3) num[i] = 4;
        answer += (num[i] + '0');
    }
    return answer;
}
