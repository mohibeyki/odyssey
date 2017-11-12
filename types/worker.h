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
    const unsigned int max = 15300;
    std::deque<Task*> queue;

public:
    void Start(int, std::mutex&);
    void addTask(Task*);
    void Load();
    void Tick();
};

#endif
