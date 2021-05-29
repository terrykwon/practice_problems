package com.terrykwon;

import java.util.ArrayDeque;
import java.util.Deque;

public class InPostFixConverter {

    public static void main(String[] args) {
        String i1 = "(4-3)*5+((5-2)*4+3)*2";
        System.out.println(infixToPostfix(i1));
    }

    /**
     * Numbers are always printed.
     * Operands are stored in a stack, with the condition that higher order operands than the current
     * are always popped.
     */
    private static String infixToPostfix(String s) {
        StringBuilder sb = new StringBuilder();
        Deque<String> stack = new ArrayDeque<String>();

        String[] split = s.split("");

        for (String t: split) {
            switch (t) {
                case "(":
                    stack.push(t);
                    break;
                case ")":
                    while (!stack.peek().equals("(")) {
                        sb.append(stack.pop());
                    }
                    stack.pop(); // "("
                    break;
                case "*":
                    stack.push(t);
                    break;
                case "+":
                case "-":
                    while (stack.peek() != null && stack.peek().equals("*")) {
                        sb.append(stack.pop());
                    }
                    stack.push(t);
                    break;
                default:  // t is number
                    sb.append(t);
                    break;
            }
        }

        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }

        return sb.toString();
    }

}
