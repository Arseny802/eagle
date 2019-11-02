set(PROJECT_NAME eagle_console)

file(GLOB SOURCE_FILES_C *.c)
file(GLOB SOURCE_FILES_C *.cc)
file(GLOB HEADER_FILES_C *.h)
file(GLOB SOURCE_FILES_CPP *.cpp)
file(GLOB HEADER_FILES_CPP *.hpp)

add_executable(${PROJECT_NAME} 
    ${SOURCE_FILES_C}
	${SOURCE_FILES_CPP}
    ${HEADER_FILES_C}
	${HEADER_FILES_CPP}
)
include_directories(
    #${CMAKE_SOURCE_DIR}/muxa_common
)
#target_link_libraries(${PROJECT_NAME} PUBLIC muxa_convertor)