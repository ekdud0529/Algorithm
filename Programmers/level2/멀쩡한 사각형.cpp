using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    double pos = 0;
    
    for(int i=1; i<w; i++)
    {
        pos = -((double)h / (double)w) * i + h;
        answer += (int)pos;
    }
    answer *= 2;
    return answer;
}
