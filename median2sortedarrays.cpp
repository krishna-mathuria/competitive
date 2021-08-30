double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double median, prev;
    int mid = (nums1Size + nums2Size) / 2;
    for (int i = 0, j = 0; ;) {
        if (j == nums2Size) {
            median = nums1[i++];
        } else if (i == nums1Size) {
            median = nums2[j++];
        } else if (nums1[i] < nums2[j]) {
            median = nums1[i++];
        } else {
            median = nums2[j++];
        }
        if (i + j > mid) {
            if ((nums1Size + nums2Size) % 2 == 0) {
                median = (prev + median) / 2;
            }
            return median;
        }
        prev = median;
    }
}