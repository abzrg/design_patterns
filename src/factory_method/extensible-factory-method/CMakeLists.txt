add_executable(extensible_factory_method
    main.cpp
    Factory.cpp
    GameObject.cpp
)

target_include_directories(extensible_factory_method PUBLIC CMAKE_CURRENT_SOURCE_DIR)
