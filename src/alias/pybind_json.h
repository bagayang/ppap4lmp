/*!
  @file src/alias/pybind_json.h
  @brief To bind ::Json to Python, a custom type caster of
  *pybind11* is required.
  @author Takayuki Kobayashi
  @date 2018/09/09
*/

#ifndef ALIAS_PYBIND_JSON_H
#define ALIAS_PYBIND_JSON_H

//! `dumps` attribute of Python's `json` module
static py::object json_dumps = py::module::import("json").attr("dumps");
//! `loads` attribute of Python's `json` module
static py::object json_loads = py::module::import("json").attr("loads");

namespace pybind11
{
  namespace detail
  {
    //! A type caster of *pybind11* for ::Json.
    template <> struct type_caster<Json> {
     public:

      //! Macro for casting ::Json.
      PYBIND11_TYPE_CASTER(Json, _("json"));

      /*!
        @brief Loading a ::Json object from Python to C++.

        First, a JSON-like object in Python (complex of dictionary
        and list) is dumped as a string by `dumps` attribute of
        Python's `json` module (serialization). Then the string is
        parsed by `parse` function of *nlohmann/json* and converted
        to a ::Json object. Since this conversion process might take
        a long time, using other containers is preferable (if you can).
      */
      bool load(handle src, bool)
      {
        try
        {
          value = Json::parse(
            py::cast<std::string>(json_dumps(py::cast<object>(src))));
        }
        catch (...)
        {
          return false;
        }

        return true;
      }

      /*!
        @brief Casting a ::Json object from C++ to Python.

        First, a ::Json object is serialized to a string by
        its `dump`  method. Then the string is loaded by `loads`
        attribute of Python's `json` module and released as a complex
        of dictionary and list. Since this conversion process might take
        a long time, using other containers is preferable (if you can).
      */
      static handle cast(Json src, return_value_policy, handle)
      {
        return json_loads(src.dump()).release();
      }
    };
  } // namespace detail
} // namespace pybind11

#endif