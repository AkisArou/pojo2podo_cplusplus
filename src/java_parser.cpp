//
// Created by ΑΔΑΜ ΚΑΡΑΦΥΛΛΙΔΗΣ on 24/1/21.
//

#include <string>
#include <regex>
#include <sstream>
#include "class_parser.h"
#include "java_parser.h"
#include "string_manip.h"
#include "java_property.h"
using namespace std;

bool JavaParser::isComment(string line)
{
  trim(line);
  return line.starts_with("/") || line.starts_with("*");
}

bool JavaParser::isClassNameContainingLine(string line)
{
  return regex_match(line, regex("class\\s(\\w+)"));
}

bool JavaParser::JavaParser::isStartingBlock(string line)
{
  return line.ends_with("{") || line.starts_with("}");
};

bool JavaParser::isEndingBlock(string line, int blockCount)
{
  return blockCount >= 1 && (line.starts_with("}") || line.ends_with("}"));
};

bool JavaParser::isEmptyLine(string line)
{
  return line.empty() || line == " ";
};

bool JavaParser::isMethod(string line)
{
  return regex_match(line, regex("\\(([^)]+)\\)"));
};

bool JavaParser::isMethodAnnotation(string line)
{
  trim(line);
  return line.starts_with("@");
};

string JavaParser::getClassName(string classNameContainingLine)
{
  string splat = split(classNameContainingLine, "class")[1];
  return split(splat, " ")[1];
};

ClassPropertySGP JavaParser::parseRawProperty(string propertyRaw)
{
  trim(propertyRaw);
  char endColumnIdx = propertyRaw.find(';');
  string javaPropUnparsed = propertyRaw.replace(endColumnIdx, propertyRaw.size(), "");
  JavaProperty javaProp;

  vector<string> parts = split(javaPropUnparsed, " ");

  if (parts[0] != JAccessors::JPROTECTED &&
      parts[0] != JAccessors::JPUBLIC &&
      parts[0] != JAccessors::JPRIVATE) {
    parts.insert(parts.begin(), JAccessors::JPUBLIC);
  }

  javaProp.setName(parts[2]);
  javaProp.setPropType(parts[1]);
  javaProp.setAccessor(parts[0]);

  bool hasDefaultValue = javaPropUnparsed.find('=') != string::npos;

  if (hasDefaultValue) {
    javaProp.setDefaultValue(parts.at(parts.size() - 1));
  } else {
    javaProp.setDefaultValue("");
  }

  return javaProp
};

vector<ClassPropertySGP> JavaParser::getClassProperties(vector<string> rawProps)
{
  vector<ClassPropertySGP> cp;

  for (const auto &prop : rawProps) {
    if (prop.find(',') != string::npos) {
      vector<string> pProps;
      string defaultValue;

      vector<string> multiProps = split(prop, ",");
      auto multiPropsLen = multiProps.size();
      vector<string> indexProp = split(multiProps[0], " ");
      string lastProp = multiProps[multiPropsLen - 1];
      auto defaultValueIdx = lastProp.find('=');

      if (defaultValueIdx != string::npos) {
        defaultValue = lastProp.substr(defaultValueIdx, lastProp.size());
        multiProps[multiPropsLen - 1] = lastProp.replace(defaultValueIdx, defaultValue.size(), "");
      }

      std::stringstream propAccType;
      for (auto &i : indexProp) {
        propAccType << i << " ";
      }

      std::stringstream fmt;
      fmt << multiProps[0] << " " << defaultValue;
      pProps.push_back(fmt.str());

      for (auto &multiProp : multiProps) {
        std::stringstream fmtmp;
        trim(multiProp);
        fmtmp << propAccType.str() << " " << multiProp << " " << defaultValue;
        pProps.push_back(fmtmp.str());
      }

      for (auto &pProp : pProps) {
        cp.push_back(parseRawProperty(pProp));
      }
    } else {
      cp.push_back(parseRawProperty(prop));
    }
  }
  return cp;
}

ParsedResult JavaParser::parse(string classStr)
{
  vector<string> classBodyLines = split(classStr, "\n");

  vector<string> classProperties;
  string classNameContainingLine;

  int blockCount = 0;

  for (auto &line : classBodyLines) {
    if (isComment(line) || isMethodAnnotation(line) || blockCount >= 1 || isEmptyLine(line) || isMethod(line))
      continue;
    else if (isClassNameContainingLine(line))
      classNameContainingLine = line;
    else if (isStartingBlock(line))
      blockCount += 1;
    else if (isEndingBlock(line, blockCount))
      blockCount -= 1;
    else
      classProperties.push_back(line);
  }

  auto pr = ParsedResult{};
  pr.className = getClassName(classNameContainingLine);
  pr.classProperties = getClassProperties(classProperties);
  return pr;
};
