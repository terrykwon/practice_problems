package com.terrykwon;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class HuntingMobs {

    public static void main(String[] args) {
        int[] s1 = new int[] {1,4,11,16,24,3};
        int[] d1 = new int[] {5,9,15,21,29,30};
        int[] a1 = new int[] {2,5,13,20,25};
        int[] b1 = new int[] {3,12,17,26,320};

        System.out.println(findFewestItems(s1, d1, a1, b1));
    }

    private static class Tuple {
        int x;
        int y;
        int order;

        Tuple(int x, int y, int order) {
           this.x = x;
           this.y = y;
           this.order = order;
        }
    }

    private static boolean intersects(Tuple a, Tuple b) {
        return a.x < b.y && b.x < a.y;
    }

    private static List<Integer> findFewestItems(int[] s, int[] d, int[] a, int[] b) {
        int n = s.length;
        int m = a.length;
        List<Integer> result = new ArrayList<>();

        List<Tuple> mobs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            mobs.add(new Tuple(s[i], d[i], i));
        }

        List<Tuple> items = new ArrayList<>();
        for (int j = 0; j < m; j++) {
            items.add(new Tuple(a[j], b[j], j));
        }

        mobs.sort((o1, o2) -> Integer.compare(o1.y, o2.y)); // Descending order
        items.sort((o1, o2) -> Integer.compare(o1.y, o2.y));

//        for (Tuple mob : mobs) {
//            System.out.println(mob.y);
//        }

        int i = 0;
        int j = 0;
        Tuple lastChosen = null;
        while (i < n) {
            System.out.println("start loop " + i);

            while (i < n && lastChosen != null && intersects(mobs.get(i), lastChosen)) {
                System.out.println("skip " + i);
                i += 1;
            }
            if (i == n) break;

            System.out.println("j " + j);

            while (j < m && !intersects(mobs.get(i), items.get(j))) {
                System.out.println("doesn't intersect " + i + " " + j);
                j += 1;
            }
            if (j == m) return null;

            while (j < m && intersects(mobs.get(i), items.get(j))) {
                System.out.println("intersect " + i + " " + j);
                j += 1;
            }

            lastChosen = items.get(j-1);
            result.add(items.get(j-1).order);

            i += 1;
        }

        return result;
    }
}
