package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static ArrayList<Integer> nums = new ArrayList<>();
    static ArrayList<Character> command = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split("-");
        int answer = getSum(input[0]);

        for (int i=1; i<input.length; i++) {
            answer -= getSum(input[i]);
        }
        System.out.println(answer);
    }

    static int getSum(String plus) {
        String[] num = plus.split("\\+");
        int sum = 0;

        for (int i=0; i<num.length; i++) {
            sum += (Integer.parseInt(num[i]));
        }
        return (sum);
    }
}
