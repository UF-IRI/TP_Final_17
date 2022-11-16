## >>>>>>>>>>>>>>>
## >>>>>>>>>>>>>>>
add_library(libreria dummy.cpp contactar.h contactar.cpp structs.h resize.h resize.cpp resizeCont.cpp resizeCons.cpp resizeMed.cpp copiarPacCont.h copiarPacCont.cpp copiarPacCons.h copiarPacCons.cpp copiarConsMed.h copiarConsMed.cpp archivar.h TengoQueArchivar?.cpp archivar.cpp activo.cpp notfound.cpp)
## <<<<<<<<<<<<<<<
## <<<<<<<<<<<<<<<

target_include_directories(libreria PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
