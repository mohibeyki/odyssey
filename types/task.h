//
//  task.h
//  odyssey
//
//  Created by Mohi Beyki on 11/12/17.
//  Copyright © 2017 Mohi Beyki. All rights reserved.
//

#ifndef task_h
#define task_h

#include <vector>

class Task {
private:
    unsigned int id;
    unsigned int total;
    unsigned int executed;
public:
    unsigned int getExecuted() const;

private:
    std::vector<Task *> deps;
public:
    Task(unsigned int, unsigned int);

    unsigned int getId();

    void addDep(Task *task);

    bool isFinished();

    void Finish();

    void Tick();

    bool isExecutable();
};

#endif
