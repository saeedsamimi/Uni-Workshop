list(APPEND COMPETITION01_FILES convertable-matrix liberation noise-math)
# Run <Build> for all targets specified to this competition
foreach (file IN LISTS COMPETITION01_FILES)
    message(CHECK_START "Project ${file} is building")
    project(${file})
    add_executable(${file} ${file}.cpp)
    message(CHECK_PASS "Passed")
endforeach ()