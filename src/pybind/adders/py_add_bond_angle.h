/*!
  @file src/pybind/adders/py_add_bond_angle.h
  @brief This file is for binding AddBondAngle class to Python.
  @author Yang Juntao
  @date 2018/12/20
*/

#ifndef PYBIND_ADD_BOND_ANGLE_H
#define PYBIND_ADD_BOND_ANGLE_H

#include <adders/add_bond_angle.h>
#include <pybind/adders/py_adder.h>

//! Namespace for functions to bind C++ classes to Python.
namespace pybind
{
  /*!
    @brief Bind AddBondAngle class to Python.
    @param m : A mutable reference to Python module.
    @return None.

    <table class="py_constructor">
      <caption class="py_constructor">
        Python-side constructor of AddBondAngle
      </caption>
      <tr class="py_constructor">
        <th class="py_constructor">C++</th>
        <th class="py_constructor" colspan="2">Description</th>
        <th class="py_constructor" colspan="2">Parameters</th>
      </tr>
      <tr class="py_constructor">
        <td class="py_constructor">
          AddBondAngle::AddBondAngle
        </td>
        <td class="py_constructor" colspan="2">
          @copybrief AddBondAngle::AddBondAngle
          @copydetails AddBondAngle::compute_impl
        </td>
        <td class="py_constructor" colspan="2">
          @copydetails AddBondAngle::AddBondAngle
        </td>
      </tr>
    </table>

    ---modify
    Usage example of the constructor to add \c xu, \c yu and \c zu
    property to an Element object for molecules.

    @htmlonly
    <pre class="prettyprint"><code class="lang-py"># python

    atoms = create(StaDumpAtoms("path/to/dump", 0))
    molecules = create(StaMolecules(atoms))

    molecules.append_updater(AddBondAngle(atoms))
    </code></pre>
    @endhtmlonly
    ----
  */
  void py_add_bond_angle(py::module &m);
}

#endif