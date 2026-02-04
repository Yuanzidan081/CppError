file(GLOB_RECURSE Provider_Src RELATIVE "${Root}/Provider" "*.cpp")
add_library(Provider SHARED ${Provider_Src})
target_include_directories(Provider PRIVATE ${Root})
target_link_libraries(Provider Base)