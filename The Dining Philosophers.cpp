class DiningPhilosophers {
public:
    DiningPhilosophers() {
        
    }
    mutex m;
    mutex mtx[5];
    condition_variable cv;
    int eating = 0;
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        int left = philosopher;
        int right = (philosopher+1)%5;

        unique_lock<mutex> sem(m);
        cv.wait(sem , [&](){ return eating < 4; });
        eating++;
        sem.unlock();

		unique_lock<mutex> ul1(mtx[left]);
        unique_lock<mutex> ul2(mtx[right]);

        pickLeftFork();
        pickRightFork();
        eat();
        putRightFork();
        putLeftFork();

        ul1.unlock();
        ul2.unlock();

        sem.lock();
        eating--;
        sem.unlock();
        cv.notify_all();
    }
};
