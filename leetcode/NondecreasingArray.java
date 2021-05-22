package com.terrykwon;

public class NondecreasingArray {
    public static void main(String[] args) {
        int[] n1 = {1, 2, 3};
        int[] n2 = {4, 2, 1};
        int[] n3 = {4, 2, 3};

        assert check(n1);
        assert !check(n2);
        assert check(n3);
    }

    private static boolean check(int[] nums) {
        if (nums.length <= 2) return true;

        int modCount = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            int j = i + 1;
            int k = i + 2;

            if (nums[i] > nums[j]) {
                nums[i] = nums[j];
                modCount += 1;
            }
            if (nums[j] > nums[k]) {
                if (nums[k] >= nums[i]) nums[j] = nums[i];
                else nums[k] = nums[j]; // k < i
                modCount += 1;
            }

            if (modCount > 1) return false;
        }
        return true;
    }
}
