#include <string>
#include <vector>
#include <set>
using namespace std;

vector<string> makeLower(vector<string> city)
{
    for(int i=0; i<city.size(); i++)
    {
        for(int j=0; j<city[i].size(); j++)
        {
            if('A' <= city[i][j] && city[i][j] <= 'Z')
            {
                city[i][j] += 32;
            }
        }
    }
    return (city);
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    set<string> city;
    
    cities = makeLower(cities);
    for(int i=0; i<cities.size(); i++)
    {
        if(city.find(cities[i]) != city.end())
        {
            for(int j=0; j<cache.size(); j++)
            {
                if(cache[j] == cities[i])
                {
                    cache.erase(cache.begin() + j);
                    cache.push_back(cities[i]);
                }
            }
            answer++;
        }
        else
        {
            if (cache.size() < cacheSize)
            {
                city.insert(cities[i]);
                cache.push_back(cities[i]);
            }
            else if(cache.size())
            {
                city.erase(cache[0]);
                cache.erase(cache.begin());
                cache.push_back(cities[i]);
                city.insert(cities[i]);
            }
            answer += 5;
        }
    }
    return answer;
}
