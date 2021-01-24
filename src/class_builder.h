//
// Created by ΑΔΑΜ ΚΑΡΑΦΥΛΛΙΔΗΣ on 24/1/21.
//

#ifndef UNTITLED_SRC_CLASS_BUILDER_H_
#define UNTITLED_SRC_CLASS_BUILDER_H_
#include "parsed_result.h"

class ClassBuilder
{
 public:
  virtual char *build(ParsedResult &pr) = 0;
};

#endif //UNTITLED_SRC_CLASS_BUILDER_H_
