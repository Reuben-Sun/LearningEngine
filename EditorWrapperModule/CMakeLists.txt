project(EditorWrapperModule)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.h")
set(ALL_FILES ${HEADERS} ${SOURCES})
add_library(EditorWrapperModule SHARED ${ALL_FILES})

# swig generate
set(SWIG_EXE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/swigwin-4.2.0/swig.exe")
set(SWIG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/swigwin-4.2.0/Lib")
set(WRAPPER_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../EditorWrapper/Source")
STRING(REPLACE "/" "\\" REPLACED ${WRAPPER_SOURCE_DIR})
add_custom_command(TARGET ${PROJECT_NAME} 
    COMMAND ${CMAKE_COMMAND} -E make_directory ${WRAPPER_SOURCE_DIR}
    COMMAND del /f /s /q ${REPLACED}\\*.cs
    COMMAND ${SWIG_EXE_PATH} -c++ -outdir ${WRAPPER_SOURCE_DIR} -namespace EditorWrapperModule -csharp -cpperraswarn -DFORCEINLINE=inline -dllimport editorwrappermodule -debug-classes -o ${CMAKE_CURRENT_SOURCE_DIR}/EngineWrapperFile.cpp ${CMAKE_CURRENT_SOURCE_DIR}/interface.i
    COMMAND echo [*******swig.exe_Done*******])