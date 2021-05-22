package com.terrykwon;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class FindPrimes {
    public static void main(String[] args) {

        double t1 = System.currentTimeMillis();
//        System.out.println(findPrimes(100000));

        System.out.println(System.currentTimeMillis() - t1 + " ms");

    }

    /**
     * Finds all primes up to n.
     */
    private static List<Integer> findPrimes(int n) {
        List<Integer> candidates = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            candidates.add(i);
        }

        int pindex = 1;
        int p;
        do {
            p = candidates.get(pindex);
            Iterator<Integer> i = candidates.iterator();
            while (i.hasNext()) {
                int cur = i.next();
                if (cur != p && cur % p == 0) i.remove();
            }
            pindex += 1;
        } while (p < candidates.get(candidates.size()-1));

        return candidates;
    }

}
