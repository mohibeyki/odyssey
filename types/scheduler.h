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

class scheduler {
public:
    scheduler();

    virtual ~scheduler();

    void schedule(std::vector<Worker *>, std::vector<Task *>);
};

#endif /* TYPES_SCHEDULER_H_ */
