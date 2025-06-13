class FizzBuzz {
private:
    int n;
    int curr;
    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        curr = 1;
    }

    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() {
                return (curr > n || (curr % 3 == 0 && curr % 5 != 0));
            });
            if (curr > n) break;
            printFizz();
            curr++;
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() {
                return (curr > n || (curr % 5 == 0 && curr % 3 != 0));
            });
            if (curr > n) break;
            printBuzz();
            curr++;
            cv.notify_all();
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() {
                return (curr > n || (curr % 3 == 0 && curr % 5 == 0));
            });
            if (curr > n) break;
            printFizzBuzz();
            curr++;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() {
                return (curr > n || (curr % 3 != 0 && curr % 5 != 0));
            });
            if (curr > n) break;
            printNumber(curr);
            curr++;
            cv.notify_all();
        }
    }
};
