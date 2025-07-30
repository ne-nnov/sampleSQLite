project(sampleSQLite LANGUAGES CXX)

qt_add_executable(${PROJECT_NAME}
    app_tableModel.cpp
    app_tableModel.h
    app_widgetMain.cpp
    app_widgetMain.h
    main.cpp
    model_counters.cpp
    model_counters.h
    model_dataBase.cpp
    model_dataBase.h
    thread_manager.cpp
    thread_manager.h
)

target_include_directories(${PROJECT_NAME} PUBLIC
    .
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Sql
    Qt::Widgets
)

set (USE_CONSOLE_DEBUG ON CACHE BOOL "Using of debug console")
set_target_properties (${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:CONSOLE /ENTRY:mainCRTStartup")

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION "${INSTALL_DIR}"
        BUNDLE DESTINATION "${INSTALL_DIR}"
        LIBRARY DESTINATION "${INSTALL_DIR}"
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Core> $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Gui> $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Widgets> $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Sql> $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMAND ${CMAKE_COMMAND} -E make_directory    $<TARGET_FILE_DIR:${PROJECT_NAME}>/platforms/
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::QWindowsIntegrationPlugin> 
                                                  $<TARGET_FILE_DIR:${PROJECT_NAME}>/platforms/
    COMMAND ${CMAKE_COMMAND} -E make_directory    $<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/
    COMMAND ${CMAKE_COMMAND} -E make_directory    $<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/sqldrivers/
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::QSQLiteDriverPlugin> 
                                                  $<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/sqldrivers/

    COMMAND ${CMAKE_COMMAND} -E make_directory    ${INSTALL_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Core> ${INSTALL_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Gui> ${INSTALL_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Widgets> ${INSTALL_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Sql> ${INSTALL_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory    ${INSTALL_DIR}/platforms/
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::QWindowsIntegrationPlugin>
                                                  ${INSTALL_DIR}/platforms/
    COMMAND ${CMAKE_COMMAND} -E make_directory    ${INSTALL_DIR}/plugins/
    COMMAND ${CMAKE_COMMAND} -E make_directory    ${INSTALL_DIR}/plugins/sqldrivers/
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::QSQLiteDriverPlugin> 
                                                  ${INSTALL_DIR}/plugins/sqldrivers/
)
