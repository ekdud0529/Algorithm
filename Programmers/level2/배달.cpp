#include <vector>
using namespace std;

int cost[51][51];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cost[i][j] = 100000000;
            if(i == j) cost[i][j] = 0;
        }
    }
    for(vector<int> r : road)
    {
        if(cost[r[0]][r[1]] != 0)
            if(cost[r[0]][r[1]] < r[2]) continue;
        if(cost[r[1]][r[0]] != 0)
            if(cost[r[1]][r[0]] < r[2]) continue;
        cost[r[0]][r[1]] = r[2];
        cost[r[1]][r[0]] = r[2];
    }
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            for(int k=1; k<=N; k++)
            {
                if(k == j) continue;
                cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
            }
        }
    }
    for(int i=1; i<=N; i++)
        if(cost[1][i] <= K) answer++;
    return answer;
}
