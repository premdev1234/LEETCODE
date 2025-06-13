class ZeroEvenOdd {
private:
    int n;
    int curr;
    int state; // 0: zero, 1: odd, 2: even
    mutex mtx;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) : n(n), curr(1), state(0) {}

    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return state == 0; });

            printNumber(0);

            state = (curr % 2 == 0) ? 2 : 1; // even or odd
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return (curr > n || state == 2); });

            if (curr > n) break;

            printNumber(curr++);
            state = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return (curr > n || state == 1); });

            if (curr > n) break;

            printNumber(curr++);
            state = 0;
            cv.notify_all();
        }
    }
};
