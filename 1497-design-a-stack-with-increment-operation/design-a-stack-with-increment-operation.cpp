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
        if(maxSize-top > 1){
            top++;
            arr[top] = x;
        }
    }
    
    int pop() {
       if(top >= 0){
        int ans = arr[top];
        top--;
        return ans;
       }
       else{
        return -1;
       }
    }
    
    void increment(int k, int val) {
        int temp = top;
        top = 0;
        while(top < k && top < maxSize){
            arr[top] += val;
            top++;
        }
        top = temp;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */