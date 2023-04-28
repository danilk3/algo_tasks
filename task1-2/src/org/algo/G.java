package org.algo;

import java.util.Arrays;
import java.util.Scanner;

public class G {

    static class Pair {
        public Character symbol;
        public Integer index;

        public Pair(Character symbol, Integer index) {
            this.symbol = symbol;
            this.index = index;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();

        Pair[] list = new Pair[n * 2];
        int[] dots = new int[m];

        for (int i = 0; i < n * 2; i += 2) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            list[i] = new Pair('+', a);
            list[i + 1] = new Pair('-', b);
        }

        for (int i = 0; i < m; i++) {
            dots[i] = scanner.nextInt();
        }

        Arrays.sort(list, (o1, o2) -> {
            if (o1.index > o2.index) {
                return 1;
            }

            if (o1.index < o2.index) {
                return -1;
            }

            if (o1.symbol == '-' && o2.symbol == '+') {
                return 1;
            }
            return -1;
        });

        int counter = 0;
        int dotsPointer = 0;

        for (Pair pair : list) {
            if (pair.symbol == '+') {
                while (dotsPointer < m && dots[dotsPointer] < pair.index) {
                    System.out.print(0 + " ");
                    ++dotsPointer;
                }
                ++counter;
            } else {
                while (dotsPointer < m && dots[dotsPointer] <= pair.index) {
                    System.out.print(counter + " ");
                    ++dotsPointer;
                }
                --counter;
            }
        }
    }
}
