#include <string>
#include <vector>
using namespace std;

struct Truck
{
    int w, pos;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    int index = 0;
    vector<Truck> onB;
    
    for(; index<truck_weights.size(); index)
    {
        for(int j=0; j<onB.size(); j++)
        {
            onB[j].pos += 1;
            if(onB[j].pos > bridge_length)
            {
                weight += onB[j].w;
                onB.erase(onB.begin());
                j--;
            }
        }
        if(weight - truck_weights[index] >= 0)
        {
            weight -= truck_weights[index];
            Truck t;
            t.pos = 1;
            t.w = truck_weights[index];
            onB.push_back(t);
            index++;
        }
        answer++;
    }
    while (onB.size())
    {
        for(int j=0; j<onB.size(); j++)
        {
            onB[j].pos += 1;
            if(onB[j].pos == bridge_length)
            {
                onB.erase(onB.begin());
                j--;
            }
        }
        answer++;
    }
    return answer;
}
