project(Editor VERSION 0.1.0 LANGUAGES CSharp)

include(CSharpUtilities)

add_executable(Editor
	App.config
	App.xaml
	App.xaml.cs
	MainWindow.xaml
	MainWindow.xaml.cs

	Properties/AssemblyInfo.cs)

csharp_set_designer_cs_properties(
	Properties/AssemblyInfo.cs)

csharp_set_xaml_cs_properties(
	App.xaml
	App.xaml.cs
	MainWindow.xaml
	MainWindow.xaml.cs)

set_property(SOURCE App.xaml PROPERTY VS_XAML_TYPE "ApplicationDefinition")

set_property(TARGET Editor PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.7.2")
set_property(TARGET Editor PROPERTY WIN32_EXECUTABLE TRUE)

set_property(TARGET Editor PROPERTY VS_DOTNET_REFERENCES
	"Microsoft.CSharp"
	"PresentationCore"
	"PresentationFramework"
	"System"
	"System.Core"
	"System.Data"
	"System.Data.DataSetExtensions"
	"System.Net.Http"
	"System.Xaml"
	"System.Xml"
	"System.Xml.Linq"
	"WindowsBase")

#add_dependencies(Editor Wrapper)
#target_link_libraries(Editor PRIVATE Wrapper)
#add_custom_command(TARGET Editor POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different
#    $<TARGET_FILE:Engine>
#    $<TARGET_FILE_DIR:Editor>
#)