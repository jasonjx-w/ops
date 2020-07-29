@startuml

' base part
class MemoryPool{
    + allocator(size_t bytes) void
    + deallocator(void *ptr) void
}
class ThreadPool{}
class Runtime {}

' joint part
class Joint << Kernel >> {}
class Joint << Executor >> {}


' executor part
class Executor {
   + SetUp(const Graph *graph) void
   + TearDown() void
   + Run() void
}

class CPUExecutor {}
class GPUExecutor {}

' op part
class Kernel {
    + SetUp(const Node *node) void
    + TearDown() void
    + Run() void
}

class Add {}
class Sub {}




' link part
Add -|> Kernel
Sub -|> Kernel


Runtime o-> Executor
ThreadPool o-> Runtime
MemoryPool o-> Runtime

CPUExecutor "bind to device" -|> Executor
GPUExecutor -|> Executor



@enduml


