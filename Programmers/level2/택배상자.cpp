#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> sub;
    stack<int> belt;
    
    for(int i=order.size(); i>0; i--)
    {
        belt.push(i);
    }
    for(int o : order)
    {
        if(!sub.empty() && sub.top() == o)
        {
            sub.pop();
            answer++;
            continue;
        }
        while(belt.top() != o)
        {
            sub.push(belt.top());
            belt.pop();
            if(belt.empty()) break;
        }
        if(belt.empty()) break;
        else
        {
            answer++;
            belt.pop();
        }
    }
    return answer;
}
