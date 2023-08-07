package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static class Meeting{
        int start;
        int end;

        public Meeting(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    static Comparator<Meeting> comparator = new Comparator<Meeting>() {
        @Override
        public int compare(Meeting o1, Meeting o2) {
            if (o1.end == o2.end) {
                return (o1.start - o2.start);
            }
            return (o1.end - o2.end);
        }
    };

    public static void main(String[] args) throws IOException {
        int answer = 1;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int time = Integer.parseInt(br.readLine());
        ArrayList<Meeting> meet = new ArrayList<>();

        for (int i=0; i<time; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            meet.add(new Meeting(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }

        Collections.sort(meet, comparator);
        int endTime = meet.get(0).end;
        for (int i=1; i<meet.size(); i++) {
            if (endTime <= meet.get(i).start) {
                answer++;
                endTime = meet.get(i).end;
            }
        }
        System.out.println(answer);
    }
}
