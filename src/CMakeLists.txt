file(GLOB_RECURSE srcfiles.vclib RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)

if(MSVC)
    add_library(rindowclblast.vclib STATIC ${srcfiles.vclib})
    set_target_properties(rindowclblast.vclib PROPERTIES OUTPUT_NAME rindowclblast)
    target_compile_options(rindowclblast.vclib PRIVATE /Zl)
    target_include_directories(rindowclblast.vclib PUBLIC
        "${PROJECT_SOURCE_DIR}/include"
        "${CLBLAST_INCLUDE_DIR}"
        "${OPENCL_INCLUDE_DIR}"
    )
endif()

if(MSVC)
    install(
        TARGETS rindowclblast.vclib
        ARCHIVE DESTINATION lib
        RENAME rindowclblast.lib
        COMPONENT ${PROJECT_NAME}
    )
endif()
