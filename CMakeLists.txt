# Generated from books.pro.

cmake_minimum_required(VERSION 3.16)
project(sampleSQLite LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(NOT DEFINED INSTALL_DIR)
  set(INSTALL_DIR "${CMAKE_BINARY_DIR}/install")
endif()

find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS Sql)
find_package(Qt6 COMPONENTS Widgets)

qt_add_executable(${PROJECT_NAME}
    src/main.cpp
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
)
target_include_directories(${PROJECT_NAME} PUBLIC
    /src
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Sql
    Qt::Widgets
)

set_property (DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION "${INSTALL_DIR}"
        BUNDLE DESTINATION "${INSTALL_DIR}"
        LIBRARY DESTINATION "${INSTALL_DIR}"
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Core> $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Gui> $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Widgets> $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMAND ${CMAKE_COMMAND} -E make_directory    $<TARGET_FILE_DIR:${PROJECT_NAME}>/platforms/
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::QWindowsIntegrationPlugin> 
                                                  $<TARGET_FILE_DIR:${PROJECT_NAME}>/platforms/

    COMMAND ${CMAKE_COMMAND} -E make_directory    ${INSTALL_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Core> ${INSTALL_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Gui> ${INSTALL_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Widgets> ${INSTALL_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory    ${INSTALL_DIR}/platforms/
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::QWindowsIntegrationPlugin>
                                                  ${INSTALL_DIR}/platforms/
)
