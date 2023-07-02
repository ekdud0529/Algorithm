class Solution {
    public String solution(int[] food) {
        String answer = "";
        String left = "";
        
        for(int i=1; i<food.length; i++)
        {
            for(int j=0; j<food[i]/2; j++)
            {
                left += Integer.toString(i);
            }
        }
        answer += left;
        answer += "0";
        StringBuffer sb = new StringBuffer(left);
        answer += sb.reverse().toString();
        return answer;
    }
}
