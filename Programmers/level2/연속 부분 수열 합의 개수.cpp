#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> num;
    
    for(int i=0; i<elements.size(); i++)
    {
        int dig = 0;
        for(int j=i; j<i + elements.size(); j++)
        {
            dig += elements[j % elements.size()];
            num.insert(dig);
        }
    }
    return answer = num.size();
}
