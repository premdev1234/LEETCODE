class CustomStack {
    int* arr;
    int maxSize;
    int top;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        top = -1;
    }
    
    void push(int x) {
        if (top + 1 < maxSize) {
            arr[++top] = x;
        }
    }
    
    int pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i <= top && i < k; ++i) {
            arr[i] += val;
        }
    }

    ~CustomStack() {
        delete[] arr;
    }
};


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */