//
// Created by ΑΔΑΜ ΚΑΡΑΦΥΛΛΙΔΗΣ on 24/1/21.
//

#ifndef UNTITLED_SRC_DART_CLASS_BUILDER_H_
#define UNTITLED_SRC_DART_CLASS_BUILDER_H_
#include "class_builder.h"

class DartClassBuilder : public ClassBuilder
{
 public:
  char *build(ParsedResult &pr) override;
};

#endif //UNTITLED_SRC_DART_CLASS_BUILDER_H_
