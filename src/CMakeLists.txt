project(SAEventReceiver)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

add_contract( SAEventReceiver SAEventReceiver SAEventReceiver.cpp )
target_include_directories( SAEventReceiver PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( SAEventReceiver ${CMAKE_SOURCE_DIR}/../ricardian )