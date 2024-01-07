project(EditorWrapper CSharp)
set_property(GLOBAL PROPERTY VS_STARTUP_PROJECT EditorWrapper)

file(GLOB_RECURSE SOURCES "Source/*cs")

add_library(EditorWrapper SHARED ${SOURCES} "Empty.cs")
set_property(TARGET EditorWrapper PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.7.2")
add_dependencies(EditorWrapper EditorWrapperModule)