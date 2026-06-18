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
        encode/encode.c
        encode/opcode_table/opcode_table.c
        cpu/registers_table/registers_table.c
        cpu/labels_table/labels_table.c

        # Decode builders
        decode/buildersDecode/b/buildInstructionB.c
        decode/buildersDecode/dpi/buildInstructionDPI.c
        decode/buildersDecode/dpr/buildInstructionDPR.c
        decode/buildersDecode/m/buildInstructionM.c

        # Encode builders
        encode/builders/builderB/b_Branch/builderB.c
        encode/builders/builderDPI/dpi_Arithmetic/builderDPI_A.c
        encode/builders/builderDPI/dpi_Logic/builderDPI_L.c
        encode/builders/builderDPI/dpi_Move/builderDPI_MOV.c
        encode/builders/builderDPI/dpi_Shift/builderDPI_Shift.c
        encode/builders/builderDPR/dpi_Shift/builderDPR_Shift.c
        encode/builders/builderDPR/dpr_Arithmetic/builderDPR_A.c
        encode/builders/builderDPR/dpr_Logic/builderDPR_L.c
        encode/builders/builderM/m_Access/builderM.c
        cpu/program_table/program_table.h
        tests/test_exit_encode.c
        tests/test_main.c
)

target_include_directories(emulador_arm PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Executável de teste
add_executable(tests
        tests/test_cpu.c
        cpu/cpu.c
        memory/memory.c
        decode/decode.c
        execute/execute.c
        encode/encode.c
        cpu/labels_table/labels_table.c
        encode/opcode_table/opcode_table.c
        cpu/registers_table/registers_table.c

        # Decode builders
        decode/buildersDecode/b/buildInstructionB.c
        decode/buildersDecode/dpi/buildInstructionDPI.c
        decode/buildersDecode/dpr/buildInstructionDPR.c
        decode/buildersDecode/m/buildInstructionM.c

        # Encode builders
        encode/builders/builderB/b_Branch/builderB.c
        encode/builders/builderDPI/dpi_Arithmetic/builderDPI_A.c
        encode/builders/builderDPI/dpi_Logic/builderDPI_L.c
        encode/builders/builderDPI/dpi_Move/builderDPI_MOV.c
        encode/builders/builderDPI/dpi_Shift/builderDPI_Shift.c
        encode/builders/builderDPR/dpi_Shift/builderDPR_Shift.c
        encode/builders/builderDPR/dpr_Arithmetic/builderDPR_A.c
        encode/builders/builderDPR/dpr_Logic/builderDPR_L.c
        encode/builders/builderM/m_Access/builderM.c
        tests/test_exit_encode.c
        tests/test_main.c
)

target_include_directories(tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(tests unity_lib)