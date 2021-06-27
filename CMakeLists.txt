cmake_minimum_required(VERSION 3.19)
project(ProyectoIII_TECFileSystem_)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH "-DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProyectoIII_TECFileSystem_ Sources/ConnectionManager.cpp Sources/cesearch.cpp Headers/cesearch.h Sources/cesearch.ui Headers/ConnectionManager.h Sources/main.cpp)

find_package(Qt${QT_VERSION} COMPONENTS Network ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Network ${REQUIRED_LIBS_QUALIFIED})