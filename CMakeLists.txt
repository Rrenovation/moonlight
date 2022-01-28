cmake_minimum_required(VERSION 3.5)

project(moonlight LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PYBIND11_PYTHON_VERSION 3.4)

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
  include_directories(${PROJECT_SOURCE_DIR}\\thrid_party\\spdlog\\include)
	link_directories(${PROJECT_SOURCE_DIR}\\thrid_party\\spdlog\\lib) 
endif()

find_package(Qt5 COMPONENTS Core Network AxContainer REQUIRED)
find_package(pybind11 CONFIG)


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