
#include <fstream>
#include <iostream>
#include "tgparser.h"

using namespace std;

std::vector<Task> TGParser::Parse(std::string filename) {
    vector<Task> tg;
    ifstream fin(filename, ios::in);
    int size;
    fin >> size;
    for (int i = 0; i < size; ++i) {
        unsigned int taskID, taskExecutionTime, deps;
        fin >> taskID >> taskExecutionTime >> deps;
        Task task(taskID, taskExecutionTime);
        for (unsigned int j = 0; j < deps; ++j) {
            int dep;
            fin >> dep;
            task.addDep(&tg[dep]);
        }
    }
    return tg;
}
