#include <string>
#include <vector>

using namespace std;

double arrive[501];
double fail[501];

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    double total = stages.size();
    double sum = 0;
    
    for(int i=0; i<stages.size(); i++)
    {
        arrive[stages[i]] += 1;
    }
    
    for(int i=1; i<=N; i++)
    {
        if((total - sum) > 0)
        {
            fail[i] = arrive[i] / (total-sum);
            sum += arrive[i];
        }
        else
            fail[i] = 0;
    }
    
    for(int i=0; i<N; i++)
    {
        int st = 1;
        double max = -1;
        for(int k=1; k<=N; k++)
        {
            if(max < fail[k])
            {
                st = k;
                max = fail[k];
            }
        }
        answer.push_back(st);
        fail[st] = -1;
    }
    return answer;
}
