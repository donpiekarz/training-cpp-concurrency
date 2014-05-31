
set(
    COMPONENTS 

    hello
    testSocket

    )

foreach(COMPONENT ${COMPONENTS})
  add_subdirectory( ${COMPONENT} )
endforeach()
