class DiningPhilosophers {
public:
    bitset<5> arr;              
    condition_variable cv;
    mutex m;

    DiningPhilosophers() {} 

    void wantsToEat(int p,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
                        int left = p;
                        int right = (p + 1)%5;
        unique_lock<mutex> lock(m);
        while(!(arr[left] == 0 && arr[right] == 0)) {
            cv.wait(lock);
        }
        arr[left] = 1;
        arr[right] = 1;
        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();

        arr[left] = 0;
        arr[right] = 0;
        cv.notify_all();
		
    }
};