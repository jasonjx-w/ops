#ifndef EXECUTOR_EXECUTOR_H_
#define EXECUTOR_EXECUTOR_H_

#include "kernels.h"
#include "graph.h"
#include "worker.h"
#include <iostream>
#include <queue>
#include <vector>

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

