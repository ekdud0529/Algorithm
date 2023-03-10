class Solution {
    public int longestPalindrome(String s) {
        int answer = 0;
        char[] str = s.toCharArray();
        boolean flag = false;
        int[] up = new int[26];
        int[] down = new int[26];

        for(char c : str)
        {
            if('A' <= c && c <= 'Z')
            {
                up[c - 'A']++;
            }
            else
            {
                down[c - 'a']++;
            }
        }
        for(int i=0; i<26; i++)
        {
            if(up[i] / 2 >= 1)
            {
                answer += 2 * (up[i] / 2);
            }
            if(down[i] / 2 >= 1)
            {
                answer += 2 * (down[i] / 2);
            }
            if(up[i] == 1 || (up[i] % 2 != 0))
                flag = true;
            if(down[i] == 1 || (down[i] % 2 != 0))
                flag = true;
        }
        if(flag)
            answer++;
        return (answer);
    }
}
