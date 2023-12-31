cmake_minimum_required(VERSION 3.5)
project(RHI-GL)

add_subdirectory(ThirdParty/glad ThirdParty/glad)
add_subdirectory(ThirdParty/fwog ThirdParty/fwog)

file(GLOB ONEIRO_RHI_GL_SOURCE_FILES
        "Source/*.cpp"
)

add_library(Oneiro-Module-RHI-GL SHARED ${ONEIRO_RHI_GL_SOURCE_FILES})
target_link_libraries(Oneiro-Module-RHI-GL PUBLIC Oneiro-Common Oneiro-Rendering fwog)
target_include_directories(Oneiro-Module-RHI-GL PUBLIC "Include/")
set_target_properties(Oneiro-Module-RHI-GL
        PROPERTIES
        CXX_STANDARD 23
        UNITY_BUILD ON
        UNITY_BUILD_BATCH_SIZE 3
        WINDOWS_EXPORT_ALL_SYMBOLS ON

        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Modules/Oneiro-Module-RHI-GL/"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Modules/Oneiro-Module-RHI-GL/"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Modules/Oneiro-Module-RHI-GL/"
)
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/module.json" DESTINATION "${CMAKE_BINARY_DIR}/Modules/Oneiro-Module-RHI-GL/")