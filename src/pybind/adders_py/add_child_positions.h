/*!
  @file src/pybind/adders_py/add_child_positions.h
  @brief This file has a function to bind AddChildPositions class to
  Python.
  @author Takayuki Kobayashi
  @date 2018/09/03
  @details

  <b>Python-side constructor of AddChildPositions class</b>:
  <table class="py_table">
    <tr class="py_tr">
      <th class="py_th">Name</th>
      <th class="py_th">C++-side</th>
      <th class="py_th">Description</th>
      <th class="py_th">Argument</th>
      <th class="py_th">Return</th>
    </tr>
    <tr class="py_tr">
      <td class="py_td">\c %AddChildPositions</td>
      <td class="py_td">AddChildPositions::AddChildPositions</td>
      <td class="py_td">
        Constructor of AddChildPositions class.
      </td>
      <td class="py_td">
        <ul class="py_ul">
          <li>
            \c elem : Child object (such as an Element object
            containing atoms data).
          </li>
          <li>
            \c child_name_ : A string for name of the above child
            object.
          </li>
        </ul>
      </td>
      <td class="py_td">
        Constructed AddChildPositions object.
      </td>
    </tr>
  </table>
*/

#ifndef PYBIND_ADD_CHILD_POSITIONS_H
#define PYBIND_ADD_CHILD_POSITIONS_H

#include <adders/add_child_positions.h>
#include <pybind/adders_py/adder.h>

/*!
  @brief Function to bind AddChildPositions class to Python.
*/
static void pybind_add_child_positions(py::module &m)
{
  py::class_<AddChildPositions,PyUpdater<AddChildPositions>,Adder,Updater,ShPtr<AddChildPositions>>(m, "AddChildPositions")
    .def(py::init<const ElPtr &,const Str &>());
}

#endif