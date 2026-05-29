cmake_minimum_required(VERSION 3.20)
project(emulador_arm C)

set(CMAKE_C_STANDARD 11)

include(FetchContent)

FetchContent_Declare(
        unity
        GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
        GIT_TAG master
)

FetchContent_MakeAvailable(unity)

# Lib Unity
add_library(unity_lib
        ${unity_SOURCE_DIR}/src/unity.c
)

target_include_directories(unity_lib PUBLIC
        ${unity_SOURCE_DIR}/src
)

# Executável principal
add_executable(emulador_arm
        main.c
        cpu/cpu.c
        memory/memory.c
        decode/decode.c
        execute/execute.c
        decode/dpi/BuildInstructionDPI.h
        decode/dpi/BuildInstructionDPI.h
        decode/dpi/BuildInstructionDPI.h
        decode/dpr/BuildInstructionDPR.h
        decode/dpr/BuildInstructionDPR.h
        decode/m/buildInstructionM.h
        decode/m/buildInstructionM.h
        decode/b/buildInstructionB.h
        decode/b/buildInstructionB.h
        decode/dpi/buildInstructionDPI.c
        encode/encode.h
)

# Executável de teste
add_executable(tests
        tests/test_cpu.c
        cpu/cpu.c
        memory/memory.c
        decode/decode.c
        execute/execute.c
)

target_link_libraries(tests unity_lib)