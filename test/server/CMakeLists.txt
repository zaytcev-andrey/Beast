# Part of Beast

GroupSources(example/server-framework framework)
GroupSources(extras/beast extras)
GroupSources(include/beast beast)

GroupSources(test/server "/")

add_executable (server-test
    ${BEAST_INCLUDES}
    ${SERVER_INCLUDES}
    ../../extras/beast/unit_test/main.cpp
    file_body.cpp
    file_service.cpp
    framework.cpp
    http_async_port.cpp
    http_base.cpp
    http_sync_port.cpp
    https_ports.cpp
    multi_port.cpp
    rfc7231.cpp
    server.cpp
    service_list.cpp
    ssl_certificate
    ssl_stream.cpp
    tests.cpp
    write_msg.cpp
    ws_async_port.cpp
    ws_sync_port.cpp
    ws_upgrade_service.cpp
    wss_ports.cpp
)

target_link_libraries(server-test
    Beast
    ${Boost_PROGRAM_OPTIONS_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
    )

if (OPENSSL_FOUND)
    target_link_libraries (server-test ${OPENSSL_LIBRARIES})
endif()
