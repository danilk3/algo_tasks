package org.algo;

/*
 * Даны N целых чисел, подсчитайте общее количество пар целых чисел, которые имеют разность K. Каждое из N целых чисел больше 0 и не превосходит 2^31 - 1
 * 1-я строка содержит N и K (целые числа).
 * 2-я строка содержит N номеров набора. Предполагается, что все числа различны.
 * Output Format
 * Одно целое число, указывающее количество пар чисел, которые имеют разность K.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

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
        int k = scanner.nextInt();

        Map<Integer, Integer> numsMap = new HashMap<>();
        int res = 0;

        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            Integer mapValue1 = numsMap.getOrDefault(num - k, 0);
            Integer mapValue2 = numsMap.getOrDefault(k + num, 0);

            res += mapValue1 + mapValue2;

            numsMap.put(num, numsMap.getOrDefault(num, 1));
        }

        System.out.println(res);
    }
}
