#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct File{
    string head, num, tail;
    int number;
};

vector<File> file;

int StrToInt(string s)
{
    int num = 0;
    
    for(char c : s)
    {
        num = (num * 10) + (c - '0');
    }
    return (num);
}

void sepFile(string s)
{
    File f;
    int i=0;
    string fName = "";
    
    for(; i<s.size(); i++)
    {
        if('0' <= s[i] && s[i] <= '9')
            break;
        fName += s[i];
    }
    f.head = fName;
    fName = "";
    for(; i<s.size(); i++)
    {
        if(!('0' <= s[i] && s[i] <= '9'))
            break;
        fName += s[i];
    }
    f.num = fName;
    f.number = StrToInt(fName);
    fName = "";
    for(; i<s.size(); i++) fName += s[i];
    f.tail = fName;
    file.push_back(f);
}

File mkLower(File f)
{
    for(int i=0; i<f.head.size(); i++)
    {
        if('A' <= f.head[i] && f.head[i] <= 'Z')
        {
            f.head[i] = f.head[i] - 'A' + 'a';
        }
    }
    return (f);
}

bool Cmp(const File &a, const File &b)
{
    File aa = mkLower(a);
    File bb = mkLower(b);
    
    if(aa.head < bb.head)
        return (true);
    else if(aa.head == bb.head)
    {
        if(aa.number < bb.number)
            return (true);
        else
            return (false);
    }
    else
        return (false);
}

string FileToStr(File f)
{
    string s = "";
    
    s += f.head;
    s += f.num;
    s += f.tail;
    return (s);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for(string f : files)
    {
        sepFile(f);
    }
    stable_sort(file.begin(), file.end(), Cmp);
    for(File f : file)
    {
        string s = FileToStr(f);
        answer.push_back(s);
    }
    return answer;
}
