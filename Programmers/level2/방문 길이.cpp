#include <string>
#include <set>
#include <utility>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int x = 0;
    int y = 0;
    set<pair<pair<int, int>, pair<int, int>>> road;
    
    for(char c : dirs)
    {
        int a = x; 
        int b = y;
        switch(c)
        {
            case 'L' :
                if (y > -5) y--;
                break;
            case 'R' :
                if (y < 5) y++;
                break;
            case 'D' :
                if (x < 5) x++;
                break;
            case 'U' :
                if (x > -5) x -= 1;
        }
        if (!(a == x && b == y))
        {
            road.insert({{a, b}, {x, y}});
            road.insert({{x, y}, {a, b}});
        }
    }
    answer = road.size();
    return answer / 2;
}
