#pragma once
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>

#define MAX_NUM 20

extern std::mutex mut;
extern std::queue<int> queData;
extern std::condition_variable cond;
extern int nCnt;


void Product();
void Customer();