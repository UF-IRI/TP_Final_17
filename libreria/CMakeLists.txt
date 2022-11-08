## >>>>>>>>>>>>>>>
## >>>>>>>>>>>>>>>
add_library(libreria dummy.cpp structs.h contactar.h contactar.cpp)
## <<<<<<<<<<<<<<<
## <<<<<<<<<<<<<<<

target_include_directories(libreria PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
