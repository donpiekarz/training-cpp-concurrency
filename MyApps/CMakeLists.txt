
set(
    COMPONENTS 

    hello

    )

foreach(COMPONENT ${COMPONENTS})
  add_subdirectory( ${COMPONENT} )
endforeach()
