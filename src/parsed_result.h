//
// Created by ΑΔΑΜ ΚΑΡΑΦΥΛΛΙΔΗΣ on 24/1/21.
//

#ifndef UNTITLED_SRC_PARSED_RESULT_H_
#define UNTITLED_SRC_PARSED_RESULT_H_

#include <vector>
#include <string>
#include "class_property.h"
using namespace std;

struct ParsedResult
{
  string className;
  vector<ClassPropertySGP> classProperties;
};

#endif //UNTITLED_SRC_PARSED_RESULT_H_
