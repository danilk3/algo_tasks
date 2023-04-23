package org.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/*
 * Задан массив из n положительных целых чисел, ваша задача - подсчитать количество подмассивов, имеющих сумму x.
 */

public class D {
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
        int n = scanner.nextInt();
        int x = scanner.nextInt();

        // value: number of repetitions
        Map<Integer, Integer> map = new HashMap<>();
        int[] prefix = new int[n + 1];

        int res = 0;

        for (int i = 1; i <= n; i++) {
            int num = scanner.nextInt();
            prefix[i] = prefix[i - 1] + num;

            Integer rep = map.get(num - x);

            if (rep != null) {
                res += rep + 1;
                map.put(num - x, rep + 1);
            }
            map.put(num, map.getOrDefault(num, 1));
        }

        System.out.println(res);
    }
}
