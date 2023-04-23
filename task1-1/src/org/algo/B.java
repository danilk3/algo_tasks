package org.algo;

/*
 * Вам дается список из n целых чисел, и ваша задача - вычислить количество различных значений в списке.
 *
 * Первая строка ввода содержит целое число n: количество значений. Вторая строка содержит n целых чисел x1, ... , xn
 *
 * Выведите одно целое число: количество различных значений.
 */

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Integer x;

        Set<Integer> set = new HashSet<>();

        for (int i = 0; i < n; i++) {
            x = scanner.nextInt();
            set.add(x);
        }

        System.out.println(set.size());
    }
}
