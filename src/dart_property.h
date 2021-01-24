//
// Created by ΑΔΑΜ ΚΑΡΑΦΥΛΛΙΔΗΣ on 24/1/21.
//

#pragma one

#include <string>
#include "class_property.h"
using namespace std;

class DAccessors {
 public:
  static const string DPUBLIC;
  static const string DPRIVATE;
  static const string DPROTECTED;
};



class DartProperty : public ClassPropertySGP
{
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
