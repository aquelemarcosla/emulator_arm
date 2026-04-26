cmake_minimum_required(VERSION 4.2)
project(emulador_arm C)

set(CMAKE_C_STANDARD 11)

add_executable(emulador_arm
        main.c
        cpu/cpu.c
        memory/memory.c
        decode/decode.c
        execute/execute.c
)
