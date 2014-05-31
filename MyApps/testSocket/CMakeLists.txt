set(TARGET testSocket)

file( GLOB SOURCES *.cpp )

include_directories(
    ${MyFramework_SOURCE_DIR}

    )

add_executable(${TARGET} ${SOURCES})

target_link_libraries(
    ${TARGET} 

    MyFramework
    )