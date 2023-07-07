import java.util.*;

class Solution {
    
    public int[] solution(String today, String[] terms, String[] privacies) {
        ArrayList<Integer> list = new ArrayList<>();
        HashMap<String, Integer> map = new HashMap<>();
        int todays = getDate(today);
        
        for(int i=0; i<terms.length; i++)
        {
            map.put(terms[i].substring(0, 1),
                    Integer.parseInt(terms[i].substring(2)));
        }
        for(int i=0; i<privacies.length; i++)
        {
            int date = getDate(privacies[i]);
            date += (map.get(privacies[i].substring(11)) * 28);
            if(todays >= date)
            {
                list.add(i+1);
            }
        }
        int[] answer = new int[list.size()];
        for(int i=0; i<list.size(); i++)
        {
            answer[i] = list.get(i);
        }
        return answer;
    }
    
    int getDate(String date)
    {
        int year = Integer.parseInt(date.substring(0, 4)) * 12 * 28;
        int month = Integer.parseInt(date.substring(5, 7)) * 28;
        int day = 0;

        if (date.length() > 10)
        {
            day = Integer.parseInt(date.substring(8, 10));
        }
        else
        {
            day = Integer.parseInt(date.substring(8));
        }
        return (year + month + day);
    }
}
