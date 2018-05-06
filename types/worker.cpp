#include <mutex>
#include <thread>
#include <iostream>
#include "worker.h"

using namespace std;

Worker::Worker(int id, bool low_perf) {
    this->alive = true;
    this->job = nullptr;
    this->busy = false;
    this->id = id;
    this->low_perf = low_perf;
}

void Worker::Start(std::mutex &iomutex) {
    while (this->isAlive()) {
        while (this->isAlive() && !this->getBusy()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        this->Tick();
    }
}

void Worker::setTask(Task *task) {
    this->job = task;
}

void Worker::Load() {
    for (unsigned long i = 1; this->busy; ++i) {
        if (this->low_perf && i % 15000 == 0) { // This number should be re-calculated for a new host machine
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}

void Worker::Tick() {
    if (this->job != nullptr && this->job->isExecutable()) {
        this->job->Tick();
        this->Load();
    }
    if (this->job->isFinished())
        this->job = nullptr;
}

bool Worker::getBusy() {
    return this->busy;
}

void Worker::Stop() {
    this->busy = false;
}

bool Worker::isAlive() {
    return this->alive;
}

void Worker::Kill() {
    this->alive = false;
}

void Worker::Resume() {
    this->busy = true;
}

bool Worker::hasJob() {
    return this->job != nullptr;
}

int Worker::getId() const {
    return id;
}
