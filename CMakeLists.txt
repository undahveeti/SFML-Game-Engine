CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

PROJECT(GAMEENGINE100)

include(FetchContent)

# fetch googletest 
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# fetch SFML
set(SFML_VERSION "2.5.1")
FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        "${SFML_VERSION}"
)
FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()
FetchContent_MakeAvailable(sfml)

ADD_EXECUTABLE(main
	src/main.cpp
)

ADD_EXECUTABLE(test
	src/test.cpp
)

TARGET_LINK_LIBRARIES(test gtest_main)
TARGET_LINK_LIBRARIES(main sfml-graphics)