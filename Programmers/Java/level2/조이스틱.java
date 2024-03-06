import java.util.*;

class Name {
    char[] name;
    int cnt = 0;
    int index = 0;
    boolean[] check;
    
    public Name(char[] name, int cnt, int index, boolean[] check) {
        this.name = name.clone();
        this.cnt = cnt;
        this.index = index;
        this.check = check.clone();
    }
}

class Solution {
    int ans = 100;
    
    public int solution(String name) {
        int answer = 0;
        Name n = new Name(new char[name.length()], 0, 0, new boolean[name.length()]);
        
        for (int i=0; i<name.length(); i++) {
            n.name[i] = 'A';
        }
        dfs(n, name);
        answer = ans;
        return answer;
    }
    
    public void dfs(Name nm, String name) {
        if (nm.name[nm.index] != name.charAt(nm.index)) {
            nm.cnt += Math.min(name.charAt(nm.index) - 'A', 'Z' - name.charAt(nm.index) + 1);
            nm.name[nm.index] = name.charAt(nm.index);
        }
        if (cmpName(nm, name)) {
            if (ans > nm.cnt)
                ans = nm.cnt;
            return ;
        }
        for (int i=1; i<name.length(); i++) {
            int index = (nm.index - i + name.length()) % name.length();
            
            if (nm.name[index] != name.charAt(index)) {
                dfs(new Name(nm.name, nm.cnt + i, index, nm.check), name);
                break;
            }
        }
        for (int i=1; i<name.length(); i++) {
            int index = (nm.index + i) % name.length();
            
            if (nm.name[index] != name.charAt(index)) {
                dfs(new Name(nm.name, nm.cnt + i, index, nm.check), name);
                break;
            }
        }
    }
    
    public boolean cmpName(Name n, String name) {
        for (int i=0; i<name.length(); i++)
        {
            if (n.name[i] != name.charAt(i))
                return (false);
        }
        return (true);
    }
}
