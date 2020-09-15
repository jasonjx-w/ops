#ifndef EXECUTOR_EXECUTOR_H_
#define EXECUTOR_EXECUTOR_H_

#include <iostream>
#include <queue>
#include <vector>
#include "graph.h"
#include "kernels.h"
#include "worker.h"

namespace ops {

class Executor {
 public:
  void Init(std::vector<const Graph *> sub_graph) {}
  void SetUp() {}     // set up env
  void TearDown() {}  // tear down env
  void Run() {}       //
 private:
  // std::vector<Worker> workers_;
 private:
  Kernel NodeToKernel(const Node *node);
};

}  // namespace ops

#endif
