#include "head.h"
#include <chrono>



void Product() {
    while (true) {
        std::unique_lock<std::mutex> lock(mut);
        cond.wait(lock, []{
            return queData.size() > MAX_NUM ? false : true;
        });
        queData.emplace(nCnt);
        std::cout << "this id " << std::this_thread::get_id() << ", Insert a num, cur que size " << queData.size() << std::endl;
        ++nCnt;
        cond.notify_one();
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}