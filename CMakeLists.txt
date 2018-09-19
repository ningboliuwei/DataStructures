cmake_minimum_required(VERSION 3.6)
project(DataStructures C)

set(CMAKE_C_STANDARD 99)

add_executable(SequenceQueue_1 Chapter4/SequenceQueue/SequenceQueue_1.c Chapter4/SequenceQueue/SequenceQueue_2.c)
add_executable(SequenceStack_1 Chapter3/SequenceStack/SequenceStack_1.c)
add_executable(LinkListQueue_1 Chapter4/LinkQueue/LinkQueue_1.c)
add_executable(LoopQueue_1 Chapter4/LoopQueue/LoopQueue_1.c)
add_executable(SequenceQueue_2 Chapter4/SequenceQueue/SequenceQueue_2.c)