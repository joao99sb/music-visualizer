cmake_minimum_required(VERSION 3.16)
project(music_visualizer)

set(CMAKE_CXX_STANDARD 17) 

# Dependencies
include(FetchContent)

set(RAYLIB_VERSION 4.5.0)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)

set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

# Configuração do diretório de build
set(BUILD_DIR ${CMAKE_BINARY_DIR})

if(NOT EXISTS ${BUILD_DIR})
    file(MAKE_DIRECTORY ${BUILD_DIR})
endif()

file(GLOB SRC  src/*.c src/utils/*.c )
# Adicionando o diretório de includes
include_directories(${PROJECT_SOURCE_DIR}/src/includes)

# Adicionando o target principal
add_executable(${PROJECT_NAME} ${SRC})

# Adicionando o target de depuração
add_executable(${PROJECT_NAME}_debug ${SRC})

# Linkando as bibliotecas ao target principal
target_link_libraries(${PROJECT_NAME} raylib)

# Linkando as bibliotecas ao target de depuração
target_link_libraries(${PROJECT_NAME}_debug raylib)

# Adicionando flags de depuração ao target de depuração
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(${PROJECT_NAME}_debug PRIVATE -ggdb -O0)
endif()

# Configurando o diretório de saída para o target de depuração
set_target_properties(${PROJECT_NAME}_debug PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY debug
)
