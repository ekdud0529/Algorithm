#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int fibo[100001];

    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2; i<=n; i++)
    {
        fibo[i] = (fibo[i-1] + fibo[i-2]) % 1234567;
    }
    answer = fibo[n] % 1234567;
    return answer;
}





---------------2---------------------
    
#include <string>
#include <vector>

using namespace std;

struct fibo{
    long long a, b, c, d;
};

fibo Cal(fibo a, fibo b)
{
    return {
        (a.a * b.a + a.b * b.c) % 1234567,
        (a.a * b.b + a.b * b.d) % 1234567,
        (a.c * b.a + a.d * b.c) % 1234567,
        (a.c * b.b + a.d * b.d) % 1234567
    };
}

int solution(int n) {
    int answer = 0;
    fibo cal = {1, 1, 1, 0};
    fibo ans = {1, 0, 1, 0};
    
    if(n <= 2)
        return (1);
    n -= 2;
    for(; n > 0; n = n >> 1)
    {
        if(n & 1)
            ans = Cal(cal, ans);
        cal = Cal(cal, cal);
    }
    answer = (ans.a) % 1234567;
    return answer;
}
