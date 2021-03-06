cmake_minimum_required(VERSION 2.8)

set(CMAKE_CONFIGURATION_TYPES ${CMAKE_BUILD_TYPE} CACHE STRING "" FORCE)
project(CPP17 CXX)

if(CPP17_CXX_STD)
else()
  set(CPP17_CXX_STD 1z)
endif()

enable_testing()

include_directories(include)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++${CPP17_CXX_STD} -ftemplate-backtrace-limit=0")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything -Werror -pedantic-errors -Wdocumentation")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-old-style-cast")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-documentation-unknown-command -Wno-missing-prototypes")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfatal-errors -Wno-padded -Wno-shadow -Wno-switch-enum")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-gnu-string-literal-operator-template")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-variable")
  set(CMAKE_CXX_FLAGS_DEBUG "-O0 -fno-inline -g3 -fstack-protector-all")
  set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -g0 -march=native -mtune=native -DNDEBUG")
elseif(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++${CPP17_CXX_STD} -ftemplate-backtrace-limit=0")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror -pedantic-errors")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=deprecated-declarations")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-missing-field-initializers")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-variable")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfatal-errors")
  set(CMAKE_CXX_FLAGS_DEBUG "-O0 -fno-inline -g3 -fstack-protector-all")
  set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -g0 -march=native -mtune=native -DNDEBUG")
endif()

macro(mk_test NAME)
  add_executable(${NAME} ${NAME}.cpp)
  add_test(${NAME} ${NAME})
endmacro()

macro(compile_fail NAME)
  add_executable(${NAME} ${NAME}.cpp)
  set_target_properties(${NAME} PROPERTIES
                        EXCLUDE_FROM_ALL TRUE
                        EXCLUDE_FROM_DEFAULT_BUILD TRUE)
  add_test(NAME ${NAME}
           COMMAND ${CMAKE_COMMAND} --build . --target ${NAME} --config $<CONFIGURATION>
           WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
  set_tests_properties(${NAME} PROPERTIES WILL_FAIL TRUE)
endmacro()


add_subdirectory(test)

