#include <string>
#include <vector>

using namespace std;

bool check[7], ch_over[10000000];
int num_len;
vector<int> num;

bool check_prime(int n)
{
    if(ch_over[n]) return false;
    
    if(n == 1 || n == 0) return false;
    if(n == 2 || n == 3) return true;
    
    for(int i=2; i*i<=n; i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

void mk_prime(int len, int n, int *cnt)
{
    if(len == num_len)
    {
        if(check_prime(n)) *cnt += 1;
        ch_over[n] = true;
        return ;
    }
    
    for(int i=0; i<num.size(); i++)
    {
        if(check[i]) continue;
        
        check[i] = true;
        mk_prime(len+1, (n*10 + num[i]), cnt);
        check[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    
    for(int i=0; i<numbers.size(); i++)
    {
        num.push_back(numbers[i] - '0');
    }
    
    for(int len=1; len<=num.size(); len++)
    {
        num_len = len;
        mk_prime(0, 0, &answer);
    }
    return answer;
}
