cmake_minimum_required(VERSION 4.2.3)

project(memory_pool)

add_executable(
	memory_pool_demo
	src/main.cpp
)

target_compile_features(memory_pool_demo PUBLIC cxx_std_20)
