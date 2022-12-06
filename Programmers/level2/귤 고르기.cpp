#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> tang;
    vector<int> cntOftangSize;
    
    for(int n : tangerine)
    {
        if(!tang[n]) tang[n] = 1;
        else tang[n] += 1;
    }
    for(auto it=tang.begin(); it!=tang.end(); it++)
    {
        cntOftangSize.push_back(it->second);
    }
    sort(cntOftangSize.begin(), cntOftangSize.end());
    for(int i=cntOftangSize.size()-1; i>=0; i--)
    {
        k -= cntOftangSize[i];
        answer++;
        if(k <= 0) break;
    }
    return answer;
}
