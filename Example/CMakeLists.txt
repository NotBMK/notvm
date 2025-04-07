set(TARGET "Example")

add_executable(${TARGET} main.cpp)

target_link_libraries(${TARGET} notvm)
    
add_custom_command(
    TARGET ${TARGET}
    COMMAND "./${TARGET}"
    USES_TARGETS ${TARGET})