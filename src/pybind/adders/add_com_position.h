#ifndef PYBIND_ADD_COM_POSITION_H
#define PYBIND_ADD_COM_POSITION_H

#include <adders/add_com_position.h>
#include <pybind/adders/adder.h>

static void pybind_add_com_position(py::module &m)
{
  py::class_<AddCoMPosition,PyUpdater<AddCoMPosition>,Adder,Updater,ShPtr<AddCoMPosition>>(m, "AddCoMPosition")
    .def(py::init<const ElPtr &>());
}

#endif