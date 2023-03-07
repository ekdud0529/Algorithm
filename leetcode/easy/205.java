class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] ss = new int[200];
        int[] tt = new int[200];

        if(s.length() != t.length())
        {
            return (false);
        }
        for(int i=0; i<s.length(); i++)
        {
            if(ss[s.charAt(i)] != tt[t.charAt(i)])
            {
                return (false);
            }
            ss[s.charAt(i)] = i + 1;
            tt[t.charAt(i)] = i + 1;
        }
        return (true);
    }
}
