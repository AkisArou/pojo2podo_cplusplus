//
// Created by ΑΔΑΜ ΚΑΡΑΦΥΛΛΙΔΗΣ on 24/1/21.
//

#include "dart_property.h"
#include "java_property.h"

const string DAccessors::DPUBLIC;
const string DAccessors::DPRIVATE = "_";
const string DAccessors::DPROTECTED = "@protected";

void DartProperty::setAccessor(string acc)
{
  if (acc == JAccessors::JPUBLIC)
    this->accessor = DAccessors::DPUBLIC;
  else if (acc == JAccessors::JPRIVATE)
    this->accessor = DAccessors::DPRIVATE;
  else if (acc == JAccessors::JPROTECTED)
    this->accessor = DAccessors::DPRIVATE;
}

void DartProperty::setDefaultValue(string defaultVal)
{
  this->defaultVal = defaultVal;
}

void DartProperty::setName(string name)
{
  this->name = name;
}

void DartProperty::setPropType(string propType)
{
  this->propType = propType;
}

string DartProperty::getAccessor()
{
  return this->accessor;
}

string DartProperty::getDefaultValue()
{
  return this->defaultVal;
}

string DartProperty::getName()
{
  return this->name;
}

string DartProperty::getPropType()
{
  return this->propType;
}

string DartProperty::getPropertyString(bool isForConstructor)
{
  string propertyString;

  if (accessor == DAccessors::DPROTECTED && !isForConstructor) {
    propertyString += accessor + "\n\t";
  }

  if (accessor == DAccessors::DPRIVATE) {
    propertyString += propType + " " + DAccessors::DPRIVATE + name;
  } else {
    propertyString = propType + " " + name;
  }

  if (!defaultVal.empty()) {
    propertyString += " =" + defaultVal;
  }

  if (!isForConstructor) {
    propertyString += ";";
  }

  return propertyString;
}
