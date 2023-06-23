class Solution {
    public String solution(String number, int k) {
        String answer = "";
        
        answer += number.charAt(0);
        for(int i=1; i<number.length(); i++)
        {
            if(k == 0)
            {
                for(int j=i; j<number.length(); j++)
                {
                    answer += number.charAt(j);
                }
                break;
            }
            while (answer.length() != 0 
               && answer.charAt(answer.length() - 1) < number.charAt(i))
            {
                answer = answer.substring(0, answer.length() - 1);
                k--;
                if(k == 0) break;
            }
            answer += number.charAt(i);
        }
        while (k != 0)
        {
            k--;
            answer = answer.substring(0, answer.length() - 1);
        }
        return answer;
    }
}
