list(APPEND WORKSHOP01_FILES CafeNet Encryption Sort Spiral ComplicatedPrime)
# Run <Build> for all targets specified to this workshop
foreach (file IN LISTS WORKSHOP01_FILES)
    message(CHECK_START "Project ${file} is building")
    project(${file})
    add_executable(${file} ${file}.cpp)
    message(CHECK_PASS "Passed")
endforeach ()