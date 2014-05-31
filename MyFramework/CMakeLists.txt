
project(MyFramework)

set(TARGET MyFramework)


file( GLOB SOURCES *.cpp )

add_library(${TARGET} SHARED ${SOURCES})

target_link_libraries(
    ${TARGET} 


    )
