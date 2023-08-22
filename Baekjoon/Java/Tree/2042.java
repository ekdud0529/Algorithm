package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static long[] tree;
    static long[] num;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader((System.in)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int level = 1;

        while (level < n) {
            level *= 2;
        }
        tree = new long[level * 2];
        num = new long[level];

        for (int i=0; i<n; i++) {
            num[i] = Long.parseLong(br.readLine());
        }

        init(n, level);

        for (int i=0; i<m+k; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            long c = Long.parseLong(st.nextToken());
            if (a == 1) {
                update(1, 1, level, b, c - num[b-1]);
                num[b-1] = c;
            }
            else {
                System.out.println(sum(1, 1, level, b, (int)c));
            }
        }
    }

    static void init(int n, int level) {
        for (int i=0; i<n; i++) {
            tree[i + level] = num[i];
        }
        for (int i=level-1; i>0; i--) {
            tree[i] = tree[i*2] + tree[i*2+1];
        }
    }

    static void update(int node, int start, int end, int index, long diff) {
        if (index < start || index > end) return ;
        tree[node] += diff;
        if (start == end) return ;
        update(node*2, start, (start+end)/2, index, diff);
        update(node*2+1, (start+end)/2+1, end, index, diff);
    }

    static long sum(int node, int start, int end, int left, int right) {
        if (left > end || right < start) return (0);
        if (left <= start && end <= right) return tree[node];
        return sum(node*2, start, (start+end)/2, left, right) +
                sum(node*2+1, (start+end)/2+1, end, left, right);
    }
}
