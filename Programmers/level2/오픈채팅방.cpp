#include <string>
#include <vector>
#include <map>
using namespace std;

struct user_data{
    string func, uid, name;
};

map<string, string> user;
string enter = "님이 들어왔습니다.";
string leave = "님이 나갔습니다.";   

user_data getData(string s)
{
    user_data id;
    string str = "";
    int index = 0;

    for(char c : s)
    {
        if(c == ' ')
        {
            if(index++ == 0)
                id.func = str;
            else
                id.uid = str;
            str = "";
        }
        else
            str += c;
    }
    if(id.uid == "")
        id.uid = str;
    else
        id.name = str;
    return (id);
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for(string s : record)
    {
        user_data id = getData(s);
        if(id.name == "") continue;
        user[id.uid] = id.name;
    }
    for(string s : record)
    {
        string str = "";
        user_data id = getData(s);
        if(id.func == "Change") continue;
        else if(id.func == "Enter")
        {
            str += user[id.uid];
            str += enter;
        }
        else
        {
            str += user[id.uid];
            str += leave;
        }
        answer.push_back(str);
    }
    return answer;
}
