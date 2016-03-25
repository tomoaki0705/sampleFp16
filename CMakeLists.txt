cmake_minimum_required(VERSION 2.8)

project(sampleFp16)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(arm.*|ARM.*)")
	set(ARM 1)
endif()

if (ARM)
	message(STATUS "detected ARM architecture")
	if (UNIX)
		add_compile_options("-mfp16-format=ieee")
		add_compile_options("-std=c99")
	endif()
endif()


add_executable(sampleFp16 main.c)
