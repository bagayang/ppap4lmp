/*!
  @file src/adders/adder.cpp
  @brief This file has implementations of the Adder class, which is a
  subclass of the Updater class.
  @author Takayuki Kobayashi
  @date 2018/06/29
  @details Please see the header file for more details.
*/

#include "adder.h"
#include "../utils/runtime_error.h"

namespace ut =  utils;

/* ------------------------------------------------------------------ */

void Adder::compute(
  Json &data,
  DataKeys &datakeys,
  const int dataid)
{
  if (check_blacklist(dataid))
  {
    if (data == nullptr)
    {
      ut::runtime_error("Adder accepts nonempty data only");
    }

    auto id_exists = datakeys.optional("id");

    compute_impl(data, datakeys);

    if (id_exists != datakeys.optional("id"))
    {
      ut::runtime_error("Adder cannot add 'id'");
    }
  }
}

/* ------------------------------------------------------------------ */
