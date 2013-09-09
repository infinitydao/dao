function(add_idl_headers)
add_custom_command(
                OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_NAME}.h"
"${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_NAME}.tlb" "${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_NAME}_i.c"
"${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_NAME}_p.c" "${CMAKE_CURRENT_BINARY_DIR}/dlldata.c"
                COMMAND  midl.exe ${CMAKE_CURRENT_SOURCE_DIR}/src/${OUTPUT_NAME}.idl
                DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/${OUTPUT_NAME}.idl" )
#set_source_files_properties(
            #${CMAKE_CURRENT_BINARY_DIR}/XMLDataModule.h ${CMAKE_CURRENT_BINARY_DIR}/XMLDataModule.c
            #PROPERTIES GENERATED TRUE)
set_source_files_properties("${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_NAME}_i.c" PROPERTIES COMPILE_FLAGS "/TC")
include_directories(${CMAKE_CURRENT_BINARY_DIR})
endfunction(add_idl_headers)