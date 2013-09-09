macro(set_mfc_flags)
	set(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MDd /ZI /Ob0 /Od /RTC1")
	set(CMAKE_MFC_FLAG 2)
	set(CMAKE_EXE_LINKER_FLAGS "/ENTRY:\"wWinMainCRTStartup\"")
endmacro(set_mfc_flags)

function(use_precompiled_header HeaderFileName SourceFileName)
  if(MSVC)
    #GET_FILENAME_COMPONENT(PrecompiledBasename ${PrecompiledHeader} NAME_WE)
    #message("############### 1 ${PrecompiledBasename}")
    set(${PROJECT_NAME}_PRECOMPILED "${CMAKE_BINARY_DIR}/${MODULE_NAME}/${CMAKE_CFG_INTDIR}/${PROJECT_NAME}.pch")
	foreach(${PROJECT_NAME}_SOURCE ${SOURCES})
		get_filename_component(${PROJECT_NAME}_SOURCE_NAME ${${PROJECT_NAME}_SOURCE} NAME)
		if(${${PROJECT_NAME}_SOURCE_NAME} STREQUAL ${SourceFileName})
			set(${PROJECT_NAME}_PRECOMPILED_SOURCE ${${PROJECT_NAME}_SOURCE})
		else(${${PROJECT_NAME}_SOURCE_NAME} STREQUAL ${SourceFileName})
			set(${PROJECT_NAME}_SOURCES ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_SOURCE})
		endif(${${PROJECT_NAME}_SOURCE_NAME} STREQUAL ${SourceFileName})
	endforeach(${PROJECT_NAME}_SOURCE ${SOURCES})
	foreach(${PROJECT_NAME}_HEADER ${HEADERS})
		get_filename_component(${PROJECT_NAME}_HEADER_NAME ${${PROJECT_NAME}_HEADER} NAME)
		if(${${PROJECT_NAME}_HEADER_NAME} STREQUAL ${HeaderFileName})
			set(${PROJECT_NAME}_PRECOMPILED_HEADER ${${PROJECT_NAME}_HEADER_NAME})
		endif(${${PROJECT_NAME}_HEADER_NAME} STREQUAL ${HeaderFileName})
	endforeach(${PROJECT_NAME}_HEADER ${HEADERS})
	
    set_source_files_properties(${${PROJECT_NAME}_PRECOMPILED_SOURCE}
                                PROPERTIES COMPILE_FLAGS "/Yc\"${HeaderFileName}\" /Fp\"${${PROJECT_NAME}_PRECOMPILED}\""
                                           OBJECT_OUTPUTS "${${PROJECT_NAME}_PRECOMPILED}")
    set_source_files_properties(${${PROJECT_NAME}_SOURCES}
                                PROPERTIES COMPILE_FLAGS "/Yu\"${HeaderFileName}\" /FI\"${HeaderFileName}\" /Fp\"${${PROJECT_NAME}_PRECOMPILED}\""
                                           OBJECT_DEPENDS "${${PROJECT_NAME}_PRECOMPILED}")  
  endif(MSVC)
endfunction(use_precompiled_header HeaderFileName SourceFileName)