package org.algo;

/*
 * Назовем целое положительное число суперкруглым, если в нем только одна цифра отлична от нуля.
 * Например, числа 5000, 4, 1, 10, 200 — суперкруглые; 42, 13, 666, 77, 101 — не суперкруглые.
 * Вам дано целое число n. Найдите количество таких суперкруглых чисел x, что 1≤x≤n.
 * */

import java.util.Scanner;

public class G {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();

            int res = 0;

            while (n != 0) {
                res += 9;
                n /= 10;
            }
            System.out.println(res);
        }
    }

}
