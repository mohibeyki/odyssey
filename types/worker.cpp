#include <mutex>
#include <thread>
#include <iostream>
#include "worker.h"

using namespace std;

void Worker::Start(int id, std::mutex &iomutex) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    {
        std::lock_guard<std::mutex> iolock(iomutex);
        cout << "Thread #" << id << "\n";
    }
    auto start = std::chrono::steady_clock::now();
    this->Tick();
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now() - start);
    {
        std::lock_guard<std::mutex> iolock(iomutex);
        cout << dur.count() << "\n";
    }
}

void Worker::setTask(Task *task) {
    this->job = task;
}

void Worker::Load() {
    unsigned long i, num;
    for (num = 1; num < this->max; ++num) {
        for (i = 2; i < num && num % i != 0; ++i);
    }
}

void Worker::Tick() {
    if (this->job->isExecutable()) {
        this->job->Tick();
    } else {
        cerr << "something went wrong task with task id of " << this->job->getID() << " is not executable" << endl;
    }
}

bool Worker::isIdle() {
    return this->job == NULL || this->job->isFinished();
}
