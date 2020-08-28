# OPS
[![Build Status](https://travis-ci.org/jasonjx-w/ops.svg?branch=master)](https://travis-ci.org/jasonjx-w/ops) 
[![License](https://img.shields.io/badge/License-MIT%20License-blue.svg)](https://opensource.org/licenses/MIT)

# 关于
1. 模拟复现深度学习框架(tensorflow, mxnet)的特性
2. 使用不同指令集(库)的实现算子


# 简述
## 1.文件结构
```
|-- ops
    |-- kernels/   # 算子的实现
    |    |-- add/  # 各个算子 ...
    |    |-- abs/
    |    |-- ..
    |  
    |-- executor/  # (子)图执行器
    |-- runtime/   # 运行时资源管理，包含线程池和内存池
    |-- graph/     # 图的构建和拆分
    |-- node/      # 算子在图上的表示
    |-- tests/     # 测试代码
    |-- tools/     # 工具和脚本

```

## 2. 数据结构
* 表示侧:
    * Graph, 图, 实现图的构建和拆分
    * Node, 结点, 用于图的表示.
* 执行侧:
    * Kernel, 即算子实现, 使用不同的指令集或库
    * Executor(Worker), 即图执行器, 接受一个或多个子图, 内部起多个worker, 在不同设备上计算子图. Executor自己持有运行时资源, 这些资源被多个worker共享.
    * Joint, 连接点, 用于连接Kernel和Executor

总体而言, 一个网络用Graph表示, 经过拆分变成多个子图(必须顺序执行且只能在一个设备上执行)SubGraph.

执行时, 将这些子图交给Executor, Executor根据子图数量和拓扑连接关系调用多个Worker执行, 不同Worker之间使用Joint实现通信.

根据子图结构, 每个Worker调用多个Kernel实现计算, 不同Kernel间用Joint交互.
