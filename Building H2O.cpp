class H2O {
public:
    std::mutex h,o;
    int flag=false;
    H2O() {
        o.lock();
    }

    void hydrogen(function<void()> releaseHydrogen) {
        h.lock();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        flag=!flag;
        if(flag) h.unlock();
        else o.unlock();
    }

    void oxygen(function<void()> releaseOxygen) {
        o.lock();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        h.unlock();
    }
};
