#ifndef KEY_CHECKER_H
#define KEY_CHECKER_H

#include "aliases.h"

class GenElement;

class KeyChecker {
 protected:
  virtual const bool check_key(
    const Set<Str> &datakeys,
    const Str &needkey,
    Str suffix = "");
  virtual const bool check_keys(
    const Set<Str> &datakeys,
    const List<Str> &needkeys,
    Str suffix = "");
  virtual const bool check_key(
    ShPtr<GenElement> elem,
    const Str &needkey);
  virtual const bool check_keys(
    ShPtr<GenElement> elem,
    const List<Str> &needkeys);
  virtual const Str get_my_class_name();
 public:
  KeyChecker() = default;
  virtual ~KeyChecker() = default;
};

#include <generators/gen_element.h>

#endif