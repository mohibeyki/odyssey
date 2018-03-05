//
//  worker.h
//  odyssey
//
//  Created by Mohi Beyki on 11/12/17.
//  Copyright © 2017 Mohi Beyki. All rights reserved.
//

#ifndef worker_h
#define worker_h

#include <deque>
#include <mutex>
#include "task.h"

class Worker {
private:
    const unsigned int max = 1024 * 1024;
    int id;
    bool low_perf;
public:
    int getId() const;

private:
    Task *job;
    bool busy;
    bool alive;
public:
    explicit Worker(int, bool);

    void Start(std::mutex &);

    bool isAlive();

    void Kill();

    void setTask(Task *);

    bool hasJob();

    void Load();

    void Tick();

    bool getBusy();

    void Resume();

    void Stop();
};

#endif
