//
// Created by ΑΔΑΜ ΚΑΡΑΦΥΛΛΙΔΗΣ on 24/1/21.
//

#include "string_manip.h"
#include <vector>

vector<string> split(const string &str, const string &delimiter)
{
  char *cstr = const_cast<char *>(str.c_str());
  char *current;
  vector<string> arr;
  current = strtok(cstr, delimiter.c_str());

  while (current != nullptr) {
    arr.emplace_back(current);
    current = strtok(nullptr, delimiter.c_str());
  }

  return arr;
}

void ltrim(string &s)
{
  s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
    return !isspace(ch);
  }));
}

void rtrim(string &s)
{
  s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
    return !isspace(ch);
  }).base(), s.end());
}

void trim(string &s)
{
  ltrim(s);
  rtrim(s);
}

