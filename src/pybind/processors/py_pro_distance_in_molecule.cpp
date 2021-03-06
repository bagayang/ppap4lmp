/*!
  @file src/pybind/processors/py_pro_distance_in_molecule.cpp
  @brief This file is for binding ProDistanceInMolecule class to Python.
  @author Takayuki Kobayashi
  @date 2018/09/23
*/

#include "py_pro_distance_in_molecule.h"

void pybind::py_pro_distance_in_molecule(py::module &m)
{
  py::class_<ProDistanceInMolecule,PyProcessor<ProDistanceInMolecule>,Processor,ShPtr<ProDistanceInMolecule>>(m, "ProDistanceInMolecule")
    .def(py::init<const ElPtr &,const ElPtr &>())
    .def(py::init<const Vec<std::pair<ElPtr,ElPtr>> &>())
    .def("set_indices", &ProDistanceInMolecule::set_indices)
    .def("set_moltype", &ProDistanceInMolecule::set_moltype)
    .def(
      "get_distance_array",
      &ProDistanceInMolecule::get_distance_array)
    .def(
      "get_distance2_array",
      &ProDistanceInMolecule::get_distance2_array);
}
