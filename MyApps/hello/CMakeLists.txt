
set(TARGET hello)

file( GLOB SOURCES *.cpp )

add_executable(${TARGET} ${SOURCES})

target_link_libraries(
    ${TARGET} 

    )