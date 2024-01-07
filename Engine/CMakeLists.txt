project(Engine)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.h" "*.ixx")
set(ALL_FILES ${HEADERS} ${SOURCES})
add_library(Engine STATIC ${ALL_FILES})
target_include_directories(Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# visual studio folder
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})

# module in C++20
if(MSVC)
    target_compile_options(Engine PUBLIC "/Zc:preprocessor")
    target_compile_options(Engine PUBLIC "/std:c++latest")
    target_compile_options(Engine PUBLIC "/experimental:module")
endif()