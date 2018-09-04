#ifndef PYBIND_PRO_VALUE_ARRAY_H
#define PYBIND_PRO_VALUE_ARRAY_H

#include <processors/pro_value_array.h>
#include <pybind/processors/processor.h>

static void pybind_pro_value_array(py::module &m)
{
  py::class_<ProValueArray,PyProcessor<ProValueArray>,Processor,ShPtr<ProValueArray>>(m, "ProValueArray")
    .def(py::init<const ElPtr &>())
    .def(py::init<const Vec<ElPtr> &>())
    .def("select", &ProValueArray::select)
    .def("get_results", &ProValueArray::get_results);
}

#endif
