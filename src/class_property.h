#include <utility>

//
// Created by ΑΔΑΜ ΚΑΡΑΦΥΛΛΙΔΗΣ on 24/1/21.
//
#pragma one
using namespace std;

class ClassProperty
{
 public:
  string name;
  string accessor;
  string defaultVal;
  string propType;

  ClassProperty(string name, string accessor, string defaultVal, string propType)
      : name(std::move(name)),
        accessor(std::move(accessor)),
        defaultVal(std::move(defaultVal)),
        propType(std::move(propType))
  {}

  ClassProperty()
  = default;

};

class ClassPropertySetter
{
  virtual void setAccessor(string acc) = 0;
  virtual void setDefaultValue(string defaultVal) = 0;
  virtual void setName(string name) = 0;
  virtual void setPropType(string propType) = 0;
};

class ClassPropertyGetter
{
  virtual string getAccessor() = 0;
  virtual string getDefaultValue() = 0;
  virtual string getName() = 0;
  virtual string getPropType() = 0;
};

class ClassPropertyResultProvider
{
  virtual string getPropertyString(bool isForConstructor) = 0;
};

class ClassPropertySGP : public ClassProperty,
                         public ClassPropertySetter,
                         public ClassPropertyGetter,
                         public ClassPropertyResultProvider
{
 public:
  using ClassProperty::ClassProperty;
};
