class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        int len = p.length();
        Long pNum = Long.parseLong(p);
        
        for(int i=0; i<t.length()-len+1; i++)
        {
            String s = t.substring(i, i+len);
            if(Long.parseLong(s) <= pNum)
                answer++;
        }
        return answer;
    }
}
