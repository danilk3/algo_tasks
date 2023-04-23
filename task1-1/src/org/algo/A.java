package org.algo;

/*
 * Вам даны три числа a, b и c. Определите, является ли одно суммой двух других.
 *
 * Первая строка содержит одно число t -  количество тестовых случаев.
 * Каждый тест задается тремя числами a,b,c
 *
 * Для каждого тестового случая выведите "YES" если одно из чисел является суммой двух других и "NO" в противном случае.
 */

import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        int a, b, c;

        for (int i = 0; i < t; i++) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            c = scanner.nextInt();

            if (a == b + c || b == a + c || c == b + a) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
