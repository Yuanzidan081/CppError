file(GLOB Base_Src "*.cpp")
add_library(Base SHARED ${Base_Src})
target_include_directories(Base PRIVATE ${Root})