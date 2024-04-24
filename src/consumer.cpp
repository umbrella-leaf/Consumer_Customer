#include "head.h"

void Customer() {
    while (true) {
        std::cout << "wait " << std::endl;
        std::unique_lock<std::mutex> lock(mut);
        cond.wait(lock, []{
            return queData.size() > 0;
        });

        int cmd = queData.front();
        queData.pop();
        std::cout << "this id " << std::this_thread::get_id() <<", pop a num is " << cmd << ",cur que size is " << queData.size() << std::endl;
        cond.notify_one();
    }
}