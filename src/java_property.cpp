//
// Created by ΑΔΑΜ ΚΑΡΑΦΥΛΛΙΔΗΣ on 24/1/21.
//

#include "java_property.h"
using namespace std;

const string JAccessors::JPUBLIC = "public";
const string JAccessors::JPRIVATE = "private";
const string JAccessors::JPROTECTED = "protected";

void JavaProperty::setAccessor(string acc)
{
  this->accessor = acc;
}

void JavaProperty::setDefaultValue(string defaultVal)
{
  this->defaultVal = defaultVal;
}

void JavaProperty::setName(string name)
{
  this->name = name;
}

void JavaProperty::setPropType(string propType)
{
  this->propType = propType;
}

string JavaProperty::getAccessor()
{
  return this->accessor;
}

string JavaProperty::getDefaultValue()
{
  return this->defaultVal;
}

string JavaProperty::getName()
{
  return this->name;
}

string JavaProperty::getPropType()
{
  return this->propType;
}

string JavaProperty::getPropertyString(bool isForConstructor)
{
  return "To be implemented";
}















