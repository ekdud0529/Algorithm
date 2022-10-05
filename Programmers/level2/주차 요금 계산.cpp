#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct carInfo
{
    string car;
    int hour, minute;
};

vector<carInfo> in;
vector<pair<string, int>> fee;

carInfo makeCarInfo(string s)
{
    carInfo info;
    string car_num(s.begin() + 6, s.begin() + 10);
    
    info.car = car_num;
    info.hour = ((s[0] - '0') * 10) + (s[1] - '0');
    info.minute = ((s[3] - '0') * 10) + (s[4] - '0');
    return (info);
}

void getFee(vector<int> fees)
{
    for(int i=0; i<fee.size(); i++)
    {
        int f = 0;
        int m = fee[i].second;
        if(m <= 0)
        {
            m += (23 * 60) + 59;
        }
        f += fees[1];
        m -= fees[0];
        if(m > 0)
        {
            f += ((m / fees[2]) * fees[3]);
            if(m % fees[2] != 0)
                f += fees[3];
        }
        fee[i].second = f;
    }
}

bool CMP(const pair<string, int> &a, const pair<string, int> &b)
{
    if(a.first < b.first)
        return (true);
    return (false);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    for(int i=0; i<records.size(); i++)
    {
        char c = records[i][records[i].size() - 1];
        carInfo car = makeCarInfo(records[i]);
        int m = car.minute + (car.hour * 60);
        int index = -1;

        if(c == 'N') m = -m;
        for(int j=0; j<fee.size(); j++)
        {
            if(fee[j].first == car.car)
            {
                index = j;
                break;
            }
        }
        if(index != -1)
            fee[index].second += m;
        else
            fee.push_back({car.car, m});
    }
    getFee(fees);
    sort(fee.begin(), fee.end(), CMP);
    for(int i=0; i<fee.size(); i++)
    {
        answer.push_back(fee[i].second);
    }
    return answer;
}
