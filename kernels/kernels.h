#ifndef KERNELS_H_
#define KERNELS_H_

#include "node.h"

namespace ops {

enum KernelType {
  SOURCE,  //  子图起始卫兵
  SINK,    //  子图终止卫兵
  LOAD,    //  获取数据, 其中保存数据来源, 如文件或地址,
           //  可用于连接子图或从磁盘读取数据
  STORE,   //  写入数据, 将数据保存至某文件或地址
  PRINT,   //  打印数据
};

// every op inherbit from kernel.
class Kernel {
 public:
  Kernel() {}
  virtual ~Kernel() {}
  virtual void Forward();
  virtual void Backward();
  KernelType Type();

 private:
  KernelType type_;
};

}  // namespace ops

#endif
