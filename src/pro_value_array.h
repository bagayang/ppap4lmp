/* ---------------------------------------------------------------------
ProValueArray: stands for Processor returning selected (double) Values
contained in Arrays.

create: 2018/07/16 by Takayuki Kobayashi
--------------------------------------------------------------------- */

#ifndef PRO_VALUE_ARRAY_H
#define PRO_VALUE_ARRAY_H

#include "processor.h"

class ProValueArray : public Processor {
  Set<Str> selected_keys;
  Dict<Str,ArrayXXd> results;
  Dict<Str,List<RowArrayXd>> results_tmp;
 protected:
  virtual void run_impl(int) override;
 public:
  ProValueArray(ShPtr<GenElement>);
  ProValueArray(List<ShPtr<GenElement>>);
  virtual ~ProValueArray() = default;
  virtual void prepare() override;
  virtual void finish() override;
  void select(py::args);
  const Dict<Str,ArrayXXd> &get_results();
};

/* ------------------------------------------------------------------ */
// for pybind11

static void pybind_pro_value_array(py::module &m)
{
  // DO NOT BREAK LINE until `.def()` for setup.py's parsing
  py::class_<ProValueArray,PyProcessor<ProValueArray>,Processor,ShPtr<ProValueArray>>(m, "ProValueArray")
    .def(py::init<ShPtr<GenElement>>())
    .def(py::init<List<ShPtr<GenElement>>>())
    .def("select", &ProValueArray::select)
    .def(
      "get_results", &ProValueArray::get_results,
      py::return_value_policy::reference_internal);
}

#endif
