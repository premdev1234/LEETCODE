int lengthOfLongestSubstring(char* s) {
    int longest = 0;
    int n = strlen(s);
    int *lastIndex = (int *)malloc(256 * sizeof(int));
    memset(lastIndex, -1, 256 * sizeof(int));

    int start = 0;

    for (int i = 0; i < n; i++) {
        if (lastIndex[s[i]] >= start) {
            start = lastIndex[s[i]] + 1;
        }
        lastIndex[s[i]] = i;
        longest = (i - start + 1) > longest ? (i - start + 1) : longest;
    }

    free(lastIndex);

    return longest;
}