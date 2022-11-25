add_library(mylib)
target_sources(mylib PRIVATE mylib.c)
target_include_directories(mylib PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)