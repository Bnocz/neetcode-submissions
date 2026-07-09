class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        const word1 = {};
        const word2 = {};
        if (s.length != t.length) {
            return false;
        }
        
        for (let i = 0; i < s.length; i++) {
            word1[s[i]] = (word1[s[i]] || 0) + 1;
        }
        for (let i = 0; i < t.length; i++) {
            word2[t[i]] = (word2[t[i]] || 0) + 1;
        }
        
        for (let key in word1) {
            if (word1[key] !== word2[key]) return false;
        }
        return true;
    }
}