list(APPEND WORKSHOP02_FILES ICPC-winner letter-to-john points-list-dividing sort-and-distinct)
# Run <Build> for all targets specified to this workshop
foreach (file IN LISTS WORKSHOP02_FILES)
    message(CHECK_START "Project ${file} is building")
    project(${file})
    add_executable(${file} ${file}.cpp)
    message(CHECK_PASS "Passed")
endforeach ()