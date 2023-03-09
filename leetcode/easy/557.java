class Solution {
    public String reverseWords(String s) {
        String[] str = s.split(" ");

        for(int i=0; i<str.length; i++)
        {
            str[i] = strReverse(str[i]);
        }
        s = "";
        for(int i=0; i<str.length; i++)
        {
            s += str[i];
            if(i != str.length - 1)
                s += " ";
        }
        return (s);
    }

    public String strReverse(String s)
    {
        int size = s.length() / 2;
        char[] str = s.toCharArray();
        char tmp;

        for(int i=0; i<size; i++)
        {
            tmp = str[i];
            str[i] = str[s.length() - 1 - i];
            str[s.length() - 1 - i] = tmp;
        }
        s = String.valueOf(str);
        return (s);
    }
}
