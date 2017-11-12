//
//  Task.cpp
//  odyssey
//
//  Created by Mohi Beyki on 11/12/17.
//  Copyright © 2017 Mohi Beyki. All rights reserved.
//

#include "Task.h"

Task::Task(TaskID id, ExecutionTime total, std::vector<TaskID> deps) {
    this->id = id;
    this->total = total;
    this->deps = deps;
}

TaskID Task::getID() {
    return this->id;
}

ExecutionTime Task::getExecutionTime() {
    return this->executed;
}

void Task::Done() {
    this->done = true;
    this->executed = total;
}

void Task::Execute() {
    if (this->executed < this->total) {
        this->executed ++;
    }
    if (this->executed == this->total) {
        this->Done();
    }
}
