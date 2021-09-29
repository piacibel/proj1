include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(main.out main.cpp matrix.cpp termview.cpp eventloop.cpp snake.cpp)
target_link_libraries(main.out ncurses)
