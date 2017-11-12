//
//  Task.h
//  odyssey
//
//  Created by Mohi Beyki on 11/12/17.
//  Copyright © 2017 Mohi Beyki. All rights reserved.
//

#ifndef Task_h
#define Task_h

#include <vector>

typedef int TaskID;
typedef long unsigned int ExecutionTime;

class Task {
private:
    TaskID id;
    ExecutionTime total;
    ExecutionTime executed;
    bool done;
    std::vector<TaskID> deps;
public:
    Task(TaskID, ExecutionTime, std::vector<TaskID>);
    
    TaskID getID();
    ExecutionTime getExecutionTime();
    void Done();
    void Execute();
};

#endif /* Task_h */
