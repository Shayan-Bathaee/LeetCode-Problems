// Runtime on this algorithm is O(n) since we only pass through the array linearly. Space complexity is also O(n), 
// because we only make a single array to hold every value. There's room for improvement, I think I could come up with a 
// solution that only works with nums1 and nums2 so I don't have to create a new array.

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    
    int allNums[m + n];
    int index1 = 0;
    int index2 = 0;

    // compare and add numbers from nums1 and nums2 into allNums in sorted order
    while ((index1 < m) && (index2 < n)) {
        if (nums1[index1] < nums2[index2]) {
            allNums[index1 + index2] = nums1[index1];
            index1 += 1;
        }
        else {
            allNums[index1 + index2] = nums2[index2];
            index2 += 1;
        }
    }

    if (index1 == m) {
        // fill in rest of nums2
        while (index2 < n) {
            allNums[index1 + index2] = nums2[index2];
            index2 += 1;
        }
    }
    else {
        // fill in rest of nums1
        while (index1 < m) {
            allNums[index1 + index2] = nums1[index1];
            index1 += 1;
        }
    }

    // copy allNums into nums1
    for (int i = 0; i < m + n; i++) {
        nums1[i] = allNums[i];
    }

    return;

}