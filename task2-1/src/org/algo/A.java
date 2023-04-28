package org.algo;

import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Stack;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();

        List<Character> closed = List.of(')', ']', '}');

        Map<Character, Character> map = Map.of(')', '(', ']', '[', '}', '{');

        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < str.length(); i++) {
            Character c = str.charAt(i);

            if (closed.contains(c)) {
                if (stack.isEmpty() || stack.pop() != map.get(c)) {
                    System.out.println("no");
                    return;
                }
            } else {
                stack.push(c);
            }
        }

        if (stack.isEmpty()) {
            System.out.println("yes");
        } else {
            System.out.println("no");
        }
    }
}

