#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Reserv{
    int start_h;
    int start_m;
    int end_h;
    int end_m;
};

Reserv StrToInt(string start, string end)
{
    Reserv tmp;
    bool flag = true;
    
    tmp.start_h = 0;
    tmp.start_m = 0;
    tmp.end_h = 0;
    tmp.end_m = 0;
    for(int i=0; i<5; i++)
    {
        if(start[i] == ':')
        {
            flag = false;
            continue;
        }
        if(flag)
        {
            tmp.start_h = tmp.start_h * 10 + (start[i] - '0');
            tmp.end_h = tmp.end_h * 10 + (end[i] - '0');
        }
        else
        {
            tmp.start_m = tmp.start_m * 10 + (start[i] - '0');
            tmp.end_m = tmp.end_m * 10 + (end[i] - '0');
        }
    }
    tmp.end_m += 10;
    tmp.end_h += (tmp.end_m / 60);
    tmp.end_m %= 60;
    return (tmp);
}

vector<Reserv> StrToReserv(vector<vector<string>> book_time)
{
    vector<Reserv> bookTime;
    
    for(int i=0; i<book_time.size(); i++)
    {
        bookTime.push_back(StrToInt(book_time[i][0], book_time[i][1]));
    }
    return (bookTime);
}

bool Cmp(const Reserv &a, const Reserv &b)
{
    if(a.start_h < b.start_h)
        return (true);
    if(a.start_h == b.start_h)
    {
        if(a.start_m < b.start_m)
            return (true);
    }
    return (false);
}

int solution(vector<vector<string>> book_time) {
    int answer = 1;
    vector<Reserv> bookTime= StrToReserv(book_time);
    vector<Reserv> room;
    
    sort(bookTime.begin(), bookTime.end(), Cmp);
    for(int i=0; i<bookTime.size(); i++)
    {
        bool flag = true;
        for(int j=0; j<room.size(); j++)
        {
            if(room[j].end_h < bookTime[i].start_h)
            {
                room[j].end_h = bookTime[i].end_h;
                room[j].end_m = bookTime[i].end_m;
                flag = false;
                break;
            }
            else if(room[j].end_h == bookTime[i].start_h)
            {
                if(room[j].end_m <= bookTime[i].start_m)
                {
                    room[j].end_h = bookTime[i].end_h;
                    room[j].end_m = bookTime[i].end_m;
                    flag = false;
                    break;
                }
            }
        }
        if(flag) 
            room.push_back(bookTime[i]);
    }
    answer = room.size();
    return answer;
}
