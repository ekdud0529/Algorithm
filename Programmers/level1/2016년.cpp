#include <string>
#include <vector>

using namespace std;

int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

string solution(int a, int b) {
    string answer = "";
    int d = 0;
    
    for(int i=0; i<a-1; i++)
    {
        d += month[i];
    }
    d += b;
    d--;
    answer = day[d%7];
    
    return answer;
}
