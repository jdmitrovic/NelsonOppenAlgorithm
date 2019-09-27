include_directories(${CMAKE_CURRENT_LIST_DIR})

add_executable(program ${CMAKE_CURRENT_LIST_DIR}/main.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/common.h
                 ${CMAKE_CURRENT_LIST_DIR}/term.h
                 ${CMAKE_CURRENT_LIST_DIR}/term.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/eq.h
                 ${CMAKE_CURRENT_LIST_DIR}/eq.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/nelson_oppen.h
                 ${CMAKE_CURRENT_LIST_DIR}/nelson_oppen.cpp)
