project(code)

set(HEADER_FILES
        headers/deque_header.h
        headers/list_header.h
        headers/main_header.h
        headers/studentas.h
        headers/v0.2.h
        headers/zmogus.h
        )

set(SOURCE_FILES
        functions/studentas.cpp
        )

add_library(code STATIC ${SOURCE_FILES} ${HEADER_FILES})