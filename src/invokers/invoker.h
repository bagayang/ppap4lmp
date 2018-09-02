/* ---------------------------------------------------------------------
Invoker: is an abstract class to execute processes.

create: 2018/06/23 by Takayuki Kobayashi
--------------------------------------------------------------------- */

#ifndef INVOKER_H
#define INVOKER_H

#include <processors/processor.h>

class Invoker {
 protected:
  int n_processors;
  List<ShPtr<Processor>> processors;
  virtual void execute_impl() = 0;
 public:
  Invoker(
    ShPtr<Processor> proc);
  Invoker(
    std::vector<ShPtr<Processor>> procs);
  virtual ~Invoker() = default;
  void execute();
};

#endif