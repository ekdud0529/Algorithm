import java.util.*;

class Solution {
    public String solution(String m, String[] musicinfos) {
        String answer = "";
        int playTime = 0;
        
        m = replaceMelody(m);
        for (int i=0; i<musicinfos.length; i++) {
            String[] music = musicinfos[i].split(",");
            int minute = getMinute(music[0], music[1]);
            music[3] = replaceMelody(music[3]);
            music[3] = mkMelody(music[3], minute);
            
            if(music[3].contains(m) && playTime < minute) {
                answer = music[2];
                playTime = minute;
            }
        }
        if (answer.equals(""))
            answer = "(None)";
        return answer;
    }
    
    public int getMinute(String start, String end) {
        String[] s = start.split(":");
        String[] e = end.split(":");
        int minute = (Integer.parseInt(e[0]) - Integer.parseInt(s[0])) * 60 
                        + Integer.parseInt(e[1]) - Integer.parseInt(s[1]);
        return minute;
    }
    
    String mkMelody(String melody, int minute) {
        String full = melody;
        
        while (full.length() < minute) {
            full = full + melody;
        }
        full = full.substring(0, minute);
        return (full);
    }
    
    public String replaceMelody(String melody) {
        melody = melody.replace("C#", "1");
        melody = melody.replace("D#", "2");
        melody = melody.replace("F#", "3");
        melody = melody.replace("G#", "4");
        melody = melody.replace("A#", "5");
        return (melody);
    }
}
