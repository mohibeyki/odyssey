/*
 * scheduler.h
 *
 *  Created on: Nov 12, 2017
 *      Author: mohi
 */

#ifndef TYPES_SCHEDULER_H_
#define TYPES_SCHEDULER_H_

#include <vector>
#include "worker.h"
#include "task.h"

class Scheduler {
public:
    Scheduler();

    virtual ~Scheduler();

    void Schedule(std::vector<Worker *>, std::vector<Task *>);
};

#endif /* TYPES_SCHEDULER_H_ */
