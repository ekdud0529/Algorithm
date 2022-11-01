#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int cnt[10001];

int solution(vector<int> topping) {
    int answer = 0;
    int tp_cnt = 0;
    set<int> young;
    
    for(int n : topping)
    {
        if(cnt[n] == 0) tp_cnt++;
        cnt[n] += 1;
    }
    for(int i=topping.size()-1; i>=0; i--)
    {
        young.insert(topping[i]);
        cnt[topping[i]]--;;
        if(cnt[topping[i]] == 0) tp_cnt--;
        topping.erase(topping.end() - 1);
        if(young.size() == tp_cnt)
            answer++;
    }
    return answer;
}
