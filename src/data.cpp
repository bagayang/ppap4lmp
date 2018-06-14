/* ---------------------------------------------------------------------
This file is for Data class.

create: 2018/06/14 by Takayuki Kobayashi
--------------------------------------------------------------------- */

#include "data.h"

Data::Data(const std::string &name_) {
  name = name_;
}

void Data::set_name(const std::string &name_) {
  name = name_;
}

const std::string &Data::get_name() {
  return name;
}
