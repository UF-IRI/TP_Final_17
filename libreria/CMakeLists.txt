## >>>>>>>>>>>>>>>
## >>>>>>>>>>>>>>>
add_library(libreria dummy.cpp contactar.h contactar.cpp structs.cpp)
## <<<<<<<<<<<<<<<
## <<<<<<<<<<<<<<<

target_include_directories(libreria PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
