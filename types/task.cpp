//
//  task.cpp
//  odyssey
//
//  Created by Mohi Beyki on 11/12/17.
//  Copyright © 2017 Mohi Beyki. All rights reserved.
//

#include "task.h"

Task::Task(unsigned int id, unsigned int total) {
    this->id = id;
    this->total = total;
    this->executed = 0;
}

unsigned int Task::getID() {
    return this->id;
}

void Task::addDep(Task *dep) {
    this->deps.push_back(dep);
}

void Task::Finish() {
    this->executed = total;
}

bool Task::isExecutable() {
    for (auto dep: this->deps)
        if (!dep->isFinished())
            return false;
    return true;
}

bool Task::isFinished() {
    return this->executed >= this->total;
}

void Task::Tick() {
    if (this->executed < this->total) {
        this->executed++;
    }
    if (this->executed >= this->total) {
        this->Finish();
    }
}
