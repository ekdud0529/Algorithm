package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static boolean[][] visited;
    static boolean[] answer;
    static int[] size = new int[3];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader((System.in)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        size[0] = Integer.parseInt(st.nextToken());
        size[1] = Integer.parseInt(st.nextToken());
        size[2] = Integer.parseInt(st.nextToken());
        answer = new boolean[size[2] + 1];
        visited = new boolean[size[0]+1][size[1]+1];

        Bucket bucket = new Bucket(0, 0);
        bfs(bucket);

        for (int i=0; i<=size[2]; i++) {
            if (answer[i])
                System.out.print(i + " ");
        }
    }

    static void bfs(Bucket start) {
        int[] send = {0, 0, 1, 1, 2, 2};
        int[] receive = {1, 2, 0, 2, 0, 1};
        Queue<Bucket> q = new LinkedList<>();

        q.add(start);
        while (!q.isEmpty()) {
            Bucket bucket = q.poll();
            int A = bucket.a;
            int B = bucket.b;
            int C = size[2] - A - B;

            for (int i=0; i<6; i++) {
                int[] move = {A, B, C};
                move[receive[i]] += move[send[i]];
                move[send[i]] = 0;
                if (move[receive[i]] > size[receive[i]]) {
                    move[send[i]] = move[receive[i]] - size[receive[i]];
                    move[receive[i]] = size[receive[i]];
                }
                if (!visited[move[0]][move[1]]) {
                    q.add(new Bucket(move[0], move[1]));
                    visited[move[0]][move[1]] = true;
                    if (move[0] == 0)
                        answer[move[2]] = true;
                }
            }
        }
    }
}

class Bucket {
    int a;
    int b;

    Bucket(int a, int b) {
        this.a = a;
        this.b = b;
    }
}
