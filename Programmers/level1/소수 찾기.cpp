#include <string>
#include <vector>

using namespace std;

int prime[1000001];

int solution(int n) {
    int answer = n-1;
    for(int i=2; i<=n; i++)
    {
        if(prime[i]) continue;
        for(int k=i; k<=n; k+=i)
        {
            if(prime[k]) continue;
            if(k != i) 
            {
                prime[k] = 1;
                answer -= 1;
            }
        }
    }
    return answer;
}
