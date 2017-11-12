//
//  tgparser.h
//  odyssey
//
//  Created by Mohi Beyki on 11/12/17.
//  Copyright © 2017 Mohi Beyki. All rights reserved.
//

#ifndef tgparser_h
#define tgparser_h

#include <string>
#include <vector>
#include "../types/task.h"

class TGParser {
public:
    std::vector<Task> Parse(std::string);
};

#endif
