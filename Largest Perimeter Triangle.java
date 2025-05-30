class Solution {
    public int largestPerimeter(int[] nums) {
        int[] arr = nums.clone();

        int n = nums.length;
        sortMax(arr, n - 1);
        sortMax(arr, n - 2);

        for (int i = n - 1; i > 1; i--) {
            sortMax(arr, i - 2);
            if (arr[i] < arr[i - 1] + arr[i - 2]) {
                return arr[i] + arr[i - 1] + arr[i - 2];
            }
        }
        
        return 0;
    }

    private void sortMax(int[] nums, int idx) {
        int max = nums[0];
        int maxidx = 0;

        for (int i = 0; i <= idx; i++) {
            if (nums[i] > max) {
                max = nums[i];
                maxidx = i;
            }
        }

        nums[maxidx] = nums[idx];
        nums[idx] = max;

    }
}
