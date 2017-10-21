set(OF_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../../../of/" CACHE PATH "The root directory of ofnode/of project.")
include(${OF_ROOT}/openFrameworks.cmake)


find_package(Boost COMPONENTS system filesystem signals REQUIRED)

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIRS} ) 

set(OPENFRAMEWORKSARBOTIX_SRCS
  ofArbotix.cpp
  )

set(OPENFRAMEWORKSARBOTIX_H
  ofArbotix.h
)

#include(openFrameworks)

add_library(openframeworksarbotix SHARED ${OPENFRAMEWORKSARBOTIX_SRCS} ${OPENFRAMEWORKSARBOTIX_H})

target_link_libraries(openframeworksarbotix ${OPENFRAMEWORKS_LIBRARIES} ${Boost_LIBRARIES})
SET_TARGET_PROPERTIES(openframeworksarbotix PROPERTIES OUTPUT_NAME openframeworksarbotix)



