package org.algo;

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
