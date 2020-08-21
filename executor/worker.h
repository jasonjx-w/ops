#ifndef EXECUTOR_WORKER_H_
#define EXECUTOR_WORKER_H_

#include "kernels.h"
#include "executor.h"
#include <algorithm>
#include <queue>

namespace ops {

enum Device {
   DEFAULT_DEVICE,
   DEFAULT_CPU,
   DEFAULT_GPU
};

class Worker {
 public:
  Worker(ops::Device device, std::queue<Kernel> kernels) {}
  virtual ~Worker() {} 
  virtual void SetUp();
  virtual void TearDown();
 private:
  std::queue<Kernel> kernels_;
};


// set up cpu run env.
// and run whatever op
class CPUWorker : public Worker {};

// set up gpu run env.
// and run whatever op
class CUDAWorker : public Worker {};

// set up gpu run env.
// and run whatever op
class CUDNNWorker : public Worker {};

}

#endif

