# Project Dependences Configuration

# Backup and set build type to release
if(NOT MSVC)
set(CMAKE_BUILD_TYPE_BAK ${CMAKE_BUILD_TYPE})
set(CMAKE_BUILD_TYPE Release)
endif()

# Include subdirectories
include_directories(${DEPS_PATHS})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Mysql REQUIRED)
include_directories(${MYSQL_INCLUDE_DIRS})
find_package(Glpk REQUIRED)
include_directories($GLPK_INCLUDE_DIRS})


# Add subdirectory
foreach(DEPS_PATH ${DEPS_PATHS})
add_subdirectory(${DEPS_PATH})
endforeach()

# Restore origin build type
if(NOT MSVC)
set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE_BAK})
endif()


