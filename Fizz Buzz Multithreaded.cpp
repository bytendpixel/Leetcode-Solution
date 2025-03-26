class FizzBuzz {
private:
    int n;
    int count;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->count = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(; count<=n;){
            unique_lock<mutex> lock(m);
            while(count<=n && !(count%3 == 0 && count%5 != 0)){
                cv.wait(lock);
            }
            if(count<=n){
                printFizz();
                count++;
            }
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for(; count<=n;){
            unique_lock<mutex> lock(m);
            while(count<=n && !(count%3 != 0 && count%5 == 0)){
                cv.wait(lock);
            }
            if(count<=n){
                printBuzz();
                count++;
            }
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for(; count<=n;){
            unique_lock<mutex> lock(m);
            while(count<=n && !(count%3 == 0 && count%5 == 0)){
                cv.wait(lock);
            }
            if(count<=n){
                printFizzBuzz();
                count++;
            }
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(; count<=n;){
            unique_lock<mutex> lock(m);
            while(count<=n && !(count%3 != 0 && count%5 != 0)){
                cv.wait(lock);
            }
            if(count<=n){
                printNumber(count);
                count++;
            }
            cv.notify_all();
        }
    }
};
