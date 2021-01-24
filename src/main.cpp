#include <iostream>
#include "java_parser.h"
#include "dart_class_builder.h"

int main()
{
  const char mockDartFileName[] = "mockDart.dart";
  const char mockJavaFileName[] = "mockJava.java";

  JavaParser jp;
  DartClassBuilder dcb;

  auto result = jp.parse("class Arous {}");
  char *dc = dcb.build(result);

  std::cout << dc << endl;

  return 0;
}
