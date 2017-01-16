INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/LNode)

SET(LNode_test_SRC
        main.c
        )
ADD_EXECUTABLE(LNode_test ${LNode_test_SRC})
TARGET_LINK_LIBRARIES(LNode_test LNode)