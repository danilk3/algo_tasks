package org.algo;

/*
 * Вам дан массив из n целых чисел, и ваша задача - найти два значения (в разных позициях), сумма которых равна x.
 *
 * Первая строка ввода содержит два целых числа n и x: размер массива и целевую сумму.
 * Вторая строка содержит n целых чисел a1, ... , an: значения массива.
 *
 * Выведите два целых числа: позиции значений. Если существует несколько решений, вы можете распечатать любое из них. Если решений нет, выведите IMPOSSIBLE.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class C {

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

        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            Integer mapValue = map.get(x - a);
            if (mapValue != null) {
                System.out.println(++mapValue + " " + ++i);
                return;
            }
            map.put(a, i);
        }
        System.out.println("IMPOSSIBLE");
    }
}
