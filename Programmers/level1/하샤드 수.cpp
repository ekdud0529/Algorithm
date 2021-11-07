#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = false;
    int n = x;
    int sum=0;
    while(x)
    {
        sum += (x%10);
        x /= 10;
    }
    if(n % sum == 0)
        answer = true;
    return answer;
}
