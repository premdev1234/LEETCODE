int minOperations(int n) {
    int x = 1, y = 1;
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    while (x * 2 < n)
        x *= 2;
    y = x * 2 - n;
    x = n - x;
    int low = minOperations(x);
    int high = minOperations(y);
    int result = (low < high) ? low + 1 : high + 1;
    return result;
}