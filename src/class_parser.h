//
// Created by ΑΔΑΜ ΚΑΡΑΦΥΛΛΙΔΗΣ on 24/1/21.
//

#ifndef UNTITLED_SRC_CLASS_PARSER_H_
#define UNTITLED_SRC_CLASS_PARSER_H_
#include "class_property.h"
#include "parsed_result.h"

using namespace std;

class ClassParser
{
 public:
  virtual bool isComment(string line) = 0;
  virtual bool isClassNameContainingLine(string line) = 0;
  virtual bool isStartingBlock(string line) = 0;
  virtual bool isEndingBlock(string line, int blockCount) = 0;
  virtual bool isEmptyLine(string line) = 0;
  virtual bool isMethod(string line) = 0;
  virtual bool isMethodAnnotation(string line) = 0;

  virtual string getClassName(string classNameContainingLine) = 0;
  virtual vector <ClassPropertySGP> getClassProperties(vector <string> rawProps) = 0;
  virtual ClassPropertySGP parseRawProperty(string propertyRaw) = 0;
  virtual ParsedResult parse(string classStr) = 0;
};

#endif //UNTITLED_SRC_CLASS_PARSER_H_
