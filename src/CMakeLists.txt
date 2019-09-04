# Source files (except the `main.cc` for the executable):
set(APP_LIB_src
  foo.cc
  sum.cc
)

set(APP_MAIN_src
  main.cc
)

# Compile the library
add_library(${APP_LIB_NAME} ${APP_LIB_src})

# Compile the executable
add_executable(${APP_EXE_NAME} ${APP_MAIN_src})

# Link the executable to the App's library (and thread/math libs).
target_link_libraries(${APP_EXE_NAME} ${APP_LIB_NAME} ${CMAKE_THREAD_LIBS_INIT} ${MATH_LIBS})

# How and what to install
install(TARGETS ${APP_LIB_NAME} LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(TARGETS ${APP_EXE_NAME} RUNTIME DESTINATION bin)
install(DIRECTORY ../include/demo DESTINATION include)
