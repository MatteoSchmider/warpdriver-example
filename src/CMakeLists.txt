project(warpdriver-example-app)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin) 

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC 
    warpdriver
)
