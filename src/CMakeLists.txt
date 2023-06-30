project(warpdriver-example-binary)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC 
    warpdriver
)
