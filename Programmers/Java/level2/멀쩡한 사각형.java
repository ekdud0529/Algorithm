class Solution {
    public long solution(int w, int h) {
        long answer = 0;
        double cnt = 0;
        
        for(int i=1; i<w; i++)
        {
            cnt = -((double)h / (double)w) * i + h;
            answer += (int)cnt;
        }
        answer *= 2;
        return answer;
    }
}
