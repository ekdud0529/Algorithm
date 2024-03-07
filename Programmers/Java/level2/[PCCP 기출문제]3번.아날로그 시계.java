class Solution {
    public int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
        int answer = -1;
        int cnt1 = getCnt(h1, m1, s1);
        int cnt2 = getCnt(h2, m2, s2);
        
        
        answer = cnt2 - cnt1;
        if ((h1 == 0 || h1 == 12) && m1 == 0 && s1 == 0)
            answer++;
        return answer;
    }
    
    public int getCnt(int h, int m, int s) {
        int cnt = 0;
        double hDegree = (h * 30 + m * 0.5 + (double)s / 120) % 360;
        double mDegree = (m * 6 + s * 0.1) % 360;
        double sDegree = s * 6;
        
        if (hDegree <= sDegree) cnt++;
        if (mDegree <= sDegree) cnt++;
        cnt += (h * 60 + m) * 2;
        cnt -= h;
        if (h >= 12) cnt -= 2;
        return (cnt);
    }
}
