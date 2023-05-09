class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = new int[2];
        int len = sequence.length + 1;
        int a = 0;
        int b = 0;
        int sum = sequence[0];
        
        while (a <= b && b < sequence.length)
        {
            if(sum == k)
            {
                if(len > b - a + 1)
                {
                    len = b - a + 1;
                    answer[0] = a;
                    answer[1] = b;
                }
                sum -= sequence[a];
                a++;
            }
            else if(sum < k)
            {
                b++;
                if(b == sequence.length)
                    break;
                sum += sequence[b];
            }
            else if(sum > k)
            {
                sum -= sequence[a];
                a++;
            }
        }
        return answer;
    }
}
