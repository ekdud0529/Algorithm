class Solution {
    public void reverseString(char[] s) {
        int size = s.length / 2;
        char tmp = 0;

        for(int i=0; i<size; i++)
        {
            tmp = s[i];
            s[i] = s[s.length - 1 - i];
            s[s.length - 1 - i] = tmp;
        }
    }
}
