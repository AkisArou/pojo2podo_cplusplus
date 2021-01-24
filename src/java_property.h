//
// Created by ΑΔΑΜ ΚΑΡΑΦΥΛΛΙΔΗΣ on 24/1/21.
//

#pragma one

#include "class_property.h"
#include <string>

class JAccessors
{
 public:
  static const string JPUBLIC;
  static const string JPRIVATE;
  static const string JPROTECTED;
};

class JavaProperty : public ClassPropertySGP
{
 public:
  using ClassPropertySGP::ClassPropertySGP;

  void setAccessor(string acc) override;
  void setDefaultValue(string defaultVal) override;
  void setName(string name) override;
  void setPropType(string propType) override;
  string getAccessor() override;
  string getDefaultValue() override;
  string getName() override;
  string getPropType() override;
  string getPropertyString(bool isForConstructor) override;
};
