package com.terrykwon;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Given an unordered set of points in a 2-D plane, find the pair with the closest Euclidean distance.
 */
public class ClosestPair {

    public static void main(String[] args) {
        int[][] t1 = { {1,2}, {19, 19}, {1,4}, {-5,-2}, {-1,-1}, {-5,1}, {25,20}, {25,26},
                {5,5}, {13,-2}, {25,23}, {24,24}, {37,2}, {-2,-3}, {-14,-5}, {2,7}, {1,6} };
        List<int[][]> tests = new ArrayList<int[][]>();

        System.out.println(euclideanDistance(t1[0], t1[2]));
        printPairs(naiveClosestPair(t1));
        printPairs(closestPair(t1));
    }

    private static void print2dArray(int[][] a) {
        for (int[] i : a) {
            System.out.print("[ ");
            for (int j : i) {
                System.out.print(j + " ");
            }
            System.out.print("]");
        }
        System.out.println("");
    }

    private static void printPairs(int[][] a) {
        System.out.println(a[0][0] + " " + a[0][1] + ", " + a[1][0] + " " + a[1][1]);
    }

    /**
     * Returns [ [p1_x, p1_y], [p2_x, p2_y] ]
     */
    private static int[][] naiveClosestPair(int[][] points) {
        if (points.length < 3) {
            return points;
        }

        double minDist = euclideanDistance(points[0], points[1]);
        int[][] minPair = { points[0], points[1] };

        for (int i = 0; i < points.length-1; i++) {
            for (int j = i+1; j < points.length; j++) {
                double dist = euclideanDistance(points[i], points[j]);
                if (dist < minDist) {
                    minDist = dist;
                    minPair[0] = points[i];
                    minPair[1] = points[j];
                }
            }
        }

        return minPair;
    }

    private static void sortX(int[][] points) {
        Arrays.sort(points, (p1, p2) -> Integer.compare(p1[0], p2[0]));
    }

    private static void sortY(int[][] points) {
        Arrays.sort(points, (p1, p2) -> Integer.compare(p1[1], p2[1]));
    }

    /**
     * Calling function.
     *
     * Time complexity: O(n*log(n))
     * Space complexity: O(n)
     */
    private static int[][] closestPair(int[][] points) {
        int[][] px = points.clone();
//        int[][] py = points.clone();

        sortX(px);
//        sortY(py);

        return closestPairSub(px);
    }

    /**
     * Combines two arrays so that the result is sorted by y-coordinates.
     *
     * Replaces the contents of `full` with the result.
     */
    private static void merge(int[][] full, int[][] a, int[][] b) {
        int i = 0; // a index
        int j = 0; // b index

        for (int k = 0; k < full.length; k++) {
            if (i >= a.length) { // All remaining elements are in b
                full[k] = b[j++];
            } else if (j >= b.length) { // All remaining elements are in a
                full[k] = a[i++];
            } else if (a[i][1] < b[j][1]) {
                full[k] = a[i++];
            } else {
                full[k] = b[j++];
            }
        }

    }

    /**
     * When passed, p is sorted by X. But by the end of the call, p is sorted by Y.
     */
    private static int[][] closestPairSub(int[][] p) {
        if (p.length <= 3) {
            sortY(p); // Consider as O(N) since the sorting is performed only on the leaf nodes.
            return naiveClosestPair(p);
        }

        int[][] minPair = null;

        int m = p.length / 2;

        int[][] lx = Arrays.copyOfRange(p, 0, m); // [start, end)
        int[][] rx = Arrays.copyOfRange(p, m, p.length);

        // Handle boundary case!
        double xBoundary = (double) lx[lx.length-1][0]; // Rightmost X coordinate

        // Construct a list of lx points sorted by y in O(n) time.

        // *** This is wrong in the case of X boundary splitting points with same x
//        int[][] ly = new int[lx.length][];
//        int[][] ry = new int[rx.length][];
//        int lyIndex = 0;
//        int ryIndex = 0;
//
//        for (int[] p : py) {
//            if ((double) p[0] <= xBoundary) ly[lyIndex++] = p;
//            else ry[ryIndex++] = p;
//        }

        int[][] closestLeft = closestPairSub(lx);
        int[][] closestRight = closestPairSub(rx);
        double leftDist = euclideanDistance(closestLeft[0], closestLeft[1]);
        double rightDist = euclideanDistance(closestRight[0], closestRight[1]);

        double minDist;
        if (leftDist <= rightDist) {
            minDist = leftDist;
            minPair = closestLeft;
        } else {
            minDist = rightDist;
            minPair = closestRight;
        }

        List<int[]> withinBoundaryList = new ArrayList<>();

        merge(p, lx, rx); // Now p is sorted by Y.

        for (int[] point : p) { // withinBoundary is naturally sorted by Y.
            if (point[0] > xBoundary - minDist && point[0] < xBoundary + minDist) {
                withinBoundaryList.add(point);
            }
        }

        int[][] withinBoundary = withinBoundaryList.toArray(new int[withinBoundaryList.size()][]);

        if (withinBoundary.length < 2) {
            return minPair;
        }

//        sortY(withinBoundary);
        // Compare with adjacent 7 points in Y axis, if exists
        int i = 0;
        double minDistBoundary = euclideanDistance(withinBoundary[0], withinBoundary[1]);
        int[][] minPairBoundary = new int[][] {withinBoundary[0], withinBoundary[1]};

        while (i < withinBoundary.length - 1) {
            int j = i+1;
            while (j < withinBoundary.length && j < i+8) { // Compares n-1 times
                double dist = euclideanDistance(withinBoundary[i], withinBoundary[j]);
                if (dist < minDistBoundary) {
                    minDistBoundary = dist;
                    minPairBoundary = new int[][] {withinBoundary[i], withinBoundary[j]};
                }
                j++;
            }
            i++;
        }

        if (minDistBoundary < minDist) {
            minPair = minPairBoundary;
        }

//        int[][] closestMid = naiveClosestPair(withinBoundary);
//        if (closestMid.length >= 2) {
//            double midDist = euclideanDistance(closestMid[0], closestMid[1]);
//            if (midDist < minDist) {
//                minDist = midDist;
//                minPair = closestMid;
//            }
//        }

        return minPair;
    }

    private static double euclideanDistance(int[] p1, int[] p2) {
        return Math.sqrt((p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]));
    }
}


