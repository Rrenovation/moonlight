cmake_minimum_required(VERSION 3.5)

project(moonlight LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
#  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
#  set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKR_FLAGS} /SAFESEH:NO")
  add_compile_options(
    $<$<CONFIG:>:/MT> #---------|
    $<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
    $<$<CONFIG:Release>:/MT> #--|
  )
  set(Qt5_DIR C:\\qt5_static\\lib\\cmake\\Qt5) # Statically link patch
	include_directories(${PROJECT_SOURCE_DIR}\\thrid_party\\ffmpeg_new\\include)
	link_directories(${PROJECT_SOURCE_DIR}\\thrid_party\\ffmpeg_new\\lib)
endif()

find_package(Qt5 COMPONENTS Core Network AxContainer REQUIRED)

include(FetchContent)

FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11
    GIT_TAG v2.9.0)
FetchContent_MakeAvailable(pybind11)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.9.2)
FetchContent_MakeAvailable(spdlog)


aux_source_directory(${PROJECT_SOURCE_DIR} SrcList)
aux_source_directory(${PROJECT_SOURCE_DIR}/log Logs)
aux_source_directory(${PROJECT_SOURCE_DIR}/lewone Lewone)
aux_source_directory(${PROJECT_SOURCE_DIR}/scrcpy DeviceList)
aux_source_directory(${PROJECT_SOURCE_DIR}/pybindmoon PybindList)
aux_source_directory(${PROJECT_SOURCE_DIR}/scrcpy/decoder DecoderList)
aux_source_directory(${PROJECT_SOURCE_DIR}/scrcpy/controller ControllerList)


pybind11_add_module(moonlight
    SHARED
    ${Logs}
    ${Lewone}
    ${SrcList}
    ${DeviceList}
    ${PybindList}
    ${DecoderList}
    ${ControllerList}
)

target_link_libraries(moonlight PUBLIC Qt5::Core Qt5::Network Qt5::AxContainer avcodec avformat avutil swscale spdlog)