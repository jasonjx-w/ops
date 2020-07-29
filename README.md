# ops
ops lib

* 模拟测试tf mxnet的特性
* 各算子使用不同指令集(库)的实现


* 文件结构
# |  
# |-kernels/
# |  |-add/
# |  |  |-avx
# |  |  |-cuda
# |  |  |- .. #else instruction
# |  |  \
# |  |-abs/
# |  |- ..
# |  
# |-executor/
# |  |-src/   #call kernels
# |  |-include/
# |  |- ..
# |  
# |-tests/
#    |-add/  #all test case saved here
#    |- ..


*  数据结构
1. Kernel, 即算子实现
2. Executor(Worker), 即图执行器, 接受一个或多个图, 内部起多个worker, 计算子图. executor自己持有runtime资源, 这些资源被多个worker共享.
3. Graph, 图的构建和拆分
4. Joint, 连接点, 用于连接Kernel和Executor

 
总体来看, 一个网络用Graph表示, 经过拆分变成多个子图SubGraph.
每个子图对应一个Worker负责执行, 不同Worker之间使用Joint实现通信(此处的Joint是对tensor data_ptr以及其他数据结构的抽象).
每个Worker内调用多个Kernel实现计算, 不同Kernel间用Joint交互(此处的Joint是对算子间传递的tensor data_ptr及其他数据结构的抽象, 算子间和Executor间穿的信息类似但不完全一致,因此使用Joint进行抽象).
