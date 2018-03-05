//
//  main.cpp
//  odyssey
//
//  Created by Mohi Beyki on 11/12/17.
//  Copyright © 2017 Mohi Beyki. All rights reserved.
//

#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "utils/tgparser.h"
#include "types/worker.h"
#include "types/Scheduler.h"

using namespace std;

int main(int argc, const char **argv) {
    constexpr unsigned n_cpu = 8;

    TGParser parser;
    vector<Task *> tg = parser.Parse("../robot.stg");

    mutex iomutex;
    vector<thread> threads(n_cpu);
    vector<Worker *> workers;

    for (unsigned i = 0; i < n_cpu; ++i)
        workers.push_back(new Worker(i, i < n_cpu / 2));

    for (unsigned i = 0; i < n_cpu; ++i) {
        threads[i] = thread(&Worker::Start, workers[i], std::ref(iomutex));
//		cpu_set_t cpuset;
//		CPU_ZERO(&cpuset);
//		CPU_SET(i, &cpuset);
//		int rc = pthread_setaffinity_np(threads[i].native_handle(),
//				sizeof(cpu_set_t), &cpuset);
//		if (rc != 0) {
//			cerr << "Error calling pthread_setaffinity_np: " << rc << endl;
//		}
    }

    auto *scheduler = new Scheduler;
    scheduler->Schedule(workers, tg);

    cout << "joining" << endl;
    for (auto &t : threads) {
        t.join();
    }
    cout << "exiting" << endl;
    return 0;
}
