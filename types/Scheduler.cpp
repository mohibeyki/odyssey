/*
 * scheduler.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: mohi
 */

#include "Scheduler.h"
#include <thread>
#include <chrono>
#include <deque>
#include <iostream>

using namespace std;

Scheduler::Scheduler() = default;

Scheduler::~Scheduler() = default;

void Scheduler::Schedule(std::vector<Worker *> workers, std::vector<Task *> tg) {
    std::deque<Task *> taskPool;
    std::deque<Task *> activePool;

    for (auto task : tg) {
        taskPool.push_back(task);
    }

    taskPool.pop_front();

    while (!taskPool.empty()) {
        for (auto worker: workers) {
            if (!worker->hasJob()) {
                for (auto t : taskPool) {
                    if (t->isExecutable()) {
                        taskPool.erase(std::remove(taskPool.begin(), taskPool.end(), t), taskPool.end());
                        worker->setTask(t);
                        cout << "Assigning new task " << t->getId() << " to " << worker->getId() << endl;
                        break;
                    }
                }
            }
            if (worker->hasJob()) {
                worker->Resume();
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        for (auto worker: workers) {
            worker->Stop();
        }
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }

    for (auto worker: workers) {
        worker->Stop();
        worker->Kill();
    }
}
