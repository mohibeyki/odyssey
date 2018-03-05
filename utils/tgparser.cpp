
#include <fstream>
#include <iostream>
#include "tgparser.h"

using namespace std;

std::vector<Task *> TGParser::Parse(std::string filename) {
    vector<Task *> tg;
    ifstream fin(filename);
    int size;
    fin >> size;
    for (int i = 0; i < size; ++i) {
        int taskID, taskExecutionTime, deps;
        fin >> taskID >> taskExecutionTime >> deps;
        auto task = new Task(static_cast<unsigned int>(taskID), static_cast<unsigned int>(taskExecutionTime));
        tg.push_back(task);
        for (int j = 0; j < deps; ++j) {
            int dep;
            fin >> dep;
            task->addDep(tg[dep]);
        }
    }
    return tg;
}
