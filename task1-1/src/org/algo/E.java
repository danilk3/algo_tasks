package org.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;


/*
 * Поликарп очень любит квадраты и кубы положительных целых чисел.
 * Вот начало ряда чисел, которые ему нравятся: 1, 4, 8, 9, .... Для заданного числа n посчитайте количество чисел от 1 до n,
 * которые нравятся Поликарпу. Иными словами, найдите количество таких x, что x является квадратом натурального числа или кубом
 *  натурального числа (или и квадратом и кубом одновременно).
 *
 * В первой строке записано целое число t (1≤t≤20) — количество наборов входных данных в тесте.
 * Далее в t строках записаны наборы входных данных по одному в строке. Каждая из строк содержит одно целое число n.
 * */

public class E {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] args) {
        FastReader scanner = new FastReader();
        int t = scanner.nextInt();


        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();

            Set<Integer> set = new HashSet<>();

            int val = 1;
            while (val * val <= n) {
                set.add(val * val);
                ++val;
            }

            val = 1;
            while (val * val * val <= n) {
                set.add(val * val * val);
                ++val;
            }

            System.out.println(set.size());
        }
    }
}
