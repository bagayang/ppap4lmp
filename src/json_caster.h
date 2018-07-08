#ifndef JSON_CASTER_H
#define JSON_CASTER_H

#include <string>

#include <nlohmann/json.hpp>
#include <pybind11/pybind11.h>

namespace py = pybind11;

using json = nlohmann::json;

static py::object json_dumps
  = py::module::import("json").attr("dumps");

static py::object json_loads
  = py::module::import("json").attr("loads");

namespace pybind11
{
  namespace detail
  {
    template <>
    struct type_caster<json> {
     public:

      PYBIND11_TYPE_CASTER(json, _("json"));

      bool load(handle src, bool)
      {
        try
        {
          value = json::parse(
            py::cast<std::string>(json_dumps(py::cast<py::object>(src))));
        } catch (...)
        {
          return false;
        }
        return true;
      }

      static handle cast(
        json src, return_value_policy, handle)
      {
        return json_loads(src.dump()).release();
      }
    };
  }
} // namespace pybind11::detail

#endif