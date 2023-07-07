import java.util.*;

class Solution {
    HashMap<Character, Integer> map = new HashMap<>();
    
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        
        for(int i=0; i<survey.length; i++)
        {
            if(choices[i] == 4) continue;
            int index = compare(choices[i]);
            if (map.containsKey(survey[i].charAt(index)))
            {
                map.put(survey[i].charAt(index),
                    map.get(survey[i].charAt(index)) + getScore(index, choices[i]));
            }
            else
            {
                map.put(survey[i].charAt(index), getScore(index, choices[i]));
            }
        }
        answer = mkRFMN();
        return answer;
    }
    
    String choiceChar(String a, String b)
    {
        int aScore = 0;
        int bScore = 0;
        
        aScore = map.getOrDefault(a.charAt(0), 0);
        bScore = map.getOrDefault(b.charAt(0), 0);
        if (aScore < bScore) return (b);
        return (a);
    }
    
    String mkRFMN()
    {
        String s = "";
        
        s += choiceChar("R", "T");
        s += choiceChar("C", "F");
        s += choiceChar("J", "M");
        s += choiceChar("A", "N");
        return (s);
    }
    
    int compare(int choice)
    {
        if (choice > 4)
            return (1);
        return (0);
    }
    
    int getScore(int direct, int choice)
    {
        if(direct == 0)
        {
            return (3 - choice + 1);
        }
        else
        {
            return (choice - 4);
        }
    }
}
