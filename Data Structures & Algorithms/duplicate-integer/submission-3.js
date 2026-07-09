class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        const duplicates = new Map();
        for (let i = 0; i < nums.length; i++) {
            if (duplicates.has(nums[i])) {
                return true;
            }
            else {
               duplicates.set(nums[i], true)
            }
        }
        return false;
    }
}
