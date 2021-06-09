cmake_minimum_required(VERSION 3.19)
project(CompileEx)

set(CMAKE_CXX_STANDARD 14)

add_executable(CompileEx main.cpp
        include/PreProcess.h
        include/natural_cut_word.h
        source/PreProcess.cpp
        source/natural_cut_word.cpp
        include/utils.h)
#        source/Reg2NFA.cpp
#        include/Reg2NFA.h
#        source/person_wolf_sheep_vegetable.cpp
#        include/person_wolf_sheep_vegetable.h)
#        source/removeleftrecursion.cpp
#        include/RemoveLeftRecursion.h)