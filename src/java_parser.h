//
// Created by ΑΔΑΜ ΚΑΡΑΦΥΛΛΙΔΗΣ on 24/1/21.
//

#ifndef UNTITLED_SRC_JAVA_PARSER_H_
#define UNTITLED_SRC_JAVA_PARSER_H_
#include "class_parser.h"

using namespace std;

class JavaParser : public ClassParser
{
 public:
  bool isComment(string line) override;
  bool isClassNameContainingLine(string line) override;
  bool isStartingBlock(string line) override;
  bool isEndingBlock(string line, int blockCount) override;
  bool isEmptyLine(string line) override;
  bool isMethod(string line) override;
  bool isMethodAnnotation(string line) override;

  string getClassName(string classNameContainingLine) override;
  vector<ClassPropertySGP> getClassProperties(vector<string> rawProps) override;
  ClassPropertySGP parseRawProperty(string propertyRaw) override;
  ParsedResult parse(string classStr) override;
};

#endif //UNTITLED_SRC_JAVA_PARSER_H_
