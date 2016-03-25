cmake_minimum_required(VERSION 2.8)

project(sampleFp16)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(arm.*|ARM.*)")
	message(STATUS "detected ARM architecture")
	add_compile_options("-mfp16-format=ieee")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "^(aarch64)")
	message(STATUS "detected aarch64")
endif()

add_compile_options("-std=c99")
add_executable(sampleFp16 main.c)
