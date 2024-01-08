project(Client)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Client WIN32 main.cpp)

target_link_libraries(Client PRIVATE Engine)

target_link_libraries(Client PRIVATE
        d3d12.lib dxgi.lib dxguid.lib uuid.lib
        kernel32.lib user32.lib
        comdlg32.lib advapi32.lib shell32.lib
        ole32.lib oleaut32.lib
        runtimeobject.lib
        )