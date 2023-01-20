cmake_minimum_required(VERSION 3.0.0)
project(observer VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include_directories(include)

set(SRC
"src/main.cpp"
"src/StatusMonitor.cpp"
"src/BackendService.cpp"
)

add_executable(observer ${SRC})