project(PostService)

file(GLOB LIB_POST_FILES lib/*.cpp lib/*.h )
add_library(post ${LIB_POST_FILES})

add_executable(PostService main.cpp)
target_include_directories(PostService PRIVATE lib)
target_link_libraries(PostService PRIVATE post)
