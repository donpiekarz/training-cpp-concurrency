set(TARGET testSocket)

file( GLOB SOURCES *.cpp )

get_cmake_property(_variableNames VARIABLES)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

include_directories(
    ${MyFramework_SOURCE_DIR}

    )

add_executable(${TARGET} ${SOURCES})

target_link_libraries(
    ${TARGET} 

    MyFramework
    )