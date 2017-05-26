project(PCO001)
cmake_minimum_required(VERSION 2.8)
include_directories(include)

###################
#### UTILITIES ####
###################

set(DISJOINT_SET_FILES
  src/utilities/lists/disjoint_set/integer_disjoint_set.cpp
  src/utilities/lists/disjoint_set/string_disjoint_set.cpp
  src/utilities/lists/disjoint_set/integer_expression_parser.cpp
  src/utilities/lists/disjoint_set/string_expression_parser.cpp
  include/utilities/lists/disjoint_set/disjoint_set.h
  include/utilities/lists/disjoint_set/disjoint_set_interface.h
  include/utilities/lists/disjoint_set/node.h
  include/utilities/lists/disjoint_set/string_disjoint_set.h
  include/utilities/lists/disjoint_set/integer_disjoint_set.h
  include/utilities/lists/disjoint_set/expression_parser.h
  include/utilities/lists/disjoint_set/integer_expression_parser.h
  include/utilities/lists/disjoint_set/string_expression_parser.h
)
set(DOUBLY_LINKED_LIST_FILES
  include/utilities/lists/doubly_linked_list/doubly_linked_list.h
  include/utilities/lists/doubly_linked_list/doubly_linked_list_interface.h
  include/utilities/lists/doubly_linked_list/node.h
)
set(LISTS_FILES
  ${DISJOINT_SET_FILES}
  ${DOUBLY_LINKED_LIST_FILES}
)
set(QUEUE_FILES
  include/utilities/queues/queue/node.h
  include/utilities/queues/queue/queue.h
  include/utilities/queues/queue/queue_interface.h
  include/utilities/queues/queue/queue_inverter.h
)
set(QUEUES_FILES
  ${QUEUE_FILES}
)
set(STACK_FILES
  include/utilities/stacks/stack/node.h
  include/utilities/stacks/stack/stack.h
  include/utilities/stacks/stack/stack_interface.h
)
set(DOUBLE_STACK_FILES
  include/utilities/stacks/double_stack/node.h
  include/utilities/stacks/double_stack/double_stack.h
  include/utilities/stacks/double_stack/double_stack_interface.h
)
set(STACKS_FILES
  ${STACK_FILES}
  ${DOUBLE_STACK_FILES}
)
set(BINARY_SEARCH_TREE_FILES
  src/utilities/trees/binary_search_tree/integer_binary_search_tree.cpp
  include/utilities/trees/binary_search_tree/node.h
  include/utilities/trees/binary_search_tree/binary_search_tree_interface.h
  include/utilities/trees/binary_search_tree/binary_search_tree.h
  include/utilities/trees/binary_search_tree/integer_binary_search_tree.h
)
set(EXPRESSION_BINARY_TREE_FILES
  #src/utilities/trees/expression_binary_tree/string_expression_parser.cpp
  src/utilities/trees/expression_binary_tree/arithmetic/double_operand.cpp
  src/utilities/trees/expression_binary_tree/logical/bool_operand.cpp
  #include/utilities/trees/expression_binary_tree/expression_parser.h
  #include/utilities/trees/expression_binary_tree/string_expression_parser.h
  include/utilities/trees/expression_binary_tree/expression_binary_tree.h
  include/utilities/trees/expression_binary_tree/node.h
  include/utilities/trees/expression_binary_tree/operand.h
  include/utilities/trees/expression_binary_tree/unary_operand.h
  include/utilities/trees/expression_binary_tree/operator.h
  include/utilities/trees/expression_binary_tree/arithmetic/arithmetic_operator.h
  include/utilities/trees/expression_binary_tree/arithmetic/negation.h
  include/utilities/trees/expression_binary_tree/arithmetic/addition.h
  include/utilities/trees/expression_binary_tree/arithmetic/subtraction.h
  include/utilities/trees/expression_binary_tree/arithmetic/multiplication.h
  include/utilities/trees/expression_binary_tree/arithmetic/division.h
  include/utilities/trees/expression_binary_tree/arithmetic/double_operand.h
  include/utilities/trees/expression_binary_tree/logical/logical_operator.h
  include/utilities/trees/expression_binary_tree/logical/not.h
  include/utilities/trees/expression_binary_tree/logical/bool_logical_operator.h
  include/utilities/trees/expression_binary_tree/logical/and.h
  include/utilities/trees/expression_binary_tree/logical/or.h
  include/utilities/trees/expression_binary_tree/logical/beq.h
  include/utilities/trees/expression_binary_tree/logical/bneq.h
  include/utilities/trees/expression_binary_tree/logical/double_logical_operator.h
  include/utilities/trees/expression_binary_tree/logical/ngeq.h
  include/utilities/trees/expression_binary_tree/logical/leq.h
  include/utilities/trees/expression_binary_tree/logical/eq.h
  include/utilities/trees/expression_binary_tree/logical/neq.h
  include/utilities/trees/expression_binary_tree/logical/geq.h
  include/utilities/trees/expression_binary_tree/logical/nleq.h
  include/utilities/trees/expression_binary_tree/logical/bool_operand.h
)
set(TREES_FILES
  ${BINARY_SEARCH_TREE_FILES}
  ${EXPRESSION_BINARY_TREE_FILES}
)
set(GRAPHES_FILES
  src/utilities/graphes/adjacency_matrix.cpp
  include/utilities/graphes/adjacency_list.h
  include/utilities/graphes/adjacency_matrix.h
  include/utilities/graphes/arc.h
  include/utilities/graphes/dijkstra_adjacency_list.h
  include/utilities/graphes/dijkstra_vertex.h
  include/utilities/graphes/vertex.h
)
set(COMPRESSION_FILES
  src/utilities/compression/converter.cpp
  src/utilities/compression/huffman/decoder.cpp
  src/utilities/compression/huffman/encoder.cpp
  include/utilities/compression/converter.h
  include/utilities/compression/huffman/decoder.h
  include/utilities/compression/huffman/encoder.h
)
set(UTIL_FILES
  src/utilities/exception.cpp
  include/utilities/exception.h
  ${LISTS_FILES}
  ${QUEUES_FILES}
  ${STACKS_FILES}
  ${TREES_FILES}
  ${GRAPHES_FILES}
  ${COMPRESSION_FILES}
)
add_executable(disjoint_set src/utilities/lists/disjoint_set/main.cpp ${UTIL_FILES})
add_executable(doubly_linked_list src/utilities/lists/doubly_linked_list/main.cpp ${UTIL_FILES})
add_executable(stack src/utilities/stacks/stack/main.cpp ${UTIL_FILES})
add_executable(queue src/utilities/queues/queue/main.cpp ${UTIL_FILES})
add_executable(binary_tree src/utilities/trees/binary_search_tree/main.cpp ${UTIL_FILES})
add_executable(expression_binary_tree src/utilities/trees/expression_binary_tree/main.cpp ${UTIL_FILES})
add_executable(adjacency_list src/utilities/graphes/adjacency_list/main.cpp ${UTIL_FILES})
add_executable(adjacency_matrix src/utilities/graphes/adjacency_matrix/main.cpp ${UTIL_FILES})
add_executable(compression_huffman src/utilities/compression/huffman/main.cpp ${UTIL_FILES})

###################
#### HOMEWORKS ####
###################

set(HOMEWORK1_FILES
  ${UTIL_FILES}
  src/homeworks/homework1/phone_book.cpp
  src/homeworks/homework1/person_info.cpp
  include/homeworks/homework1/phone_book.h
  include/homeworks/homework1/person_info.h
)
add_executable(homework1 src/homeworks/homework1/main.cpp ${HOMEWORK1_FILES})

set(HOMEWORK2_FILES
  ${UTIL_FILES}
)
add_executable(homework2 src/homeworks/homework2/main.cpp ${HOMEWORK2_FILES})

set(HOMEWORK3_FILES
  ${UTIL_FILES}
)
add_executable(homework3 src/homeworks/homework3/main.cpp ${HOMEWORK3_FILES})

set(HOMEWORK4_FILES
  ${UTIL_FILES}
  src/homeworks/homework4/integer_disjoint_sets.cpp
  include/homeworks/homework4/integer_disjoint_sets.h
)
add_executable(homework4 src/homeworks/homework4/main.cpp ${HOMEWORK4_FILES})

set(HOMEWORK5_FILES
  ${UTIL_FILES}
)
add_executable(homework5 src/homeworks/homework5/main.cpp ${HOMEWORK5_FILES})

set(HOMEWORK8_FILES
  ${UTIL_FILES}
)
add_executable(homework8 src/homeworks/homework8/main.cpp ${HOMEWORK8_FILES})

set(HOMEWORK9_FILES
  src/homeworks/homework9/city.cpp
  src/homeworks/homework9/highway.cpp
  src/homeworks/homework9/highway_map.cpp
  include/homeworks/homework9/city.h
  include/homeworks/homework9/highway.h
  include/homeworks/homework9/highway_map.h
  ${UTIL_FILES}
)
add_executable(homework9 src/homeworks/homework9/main.cpp ${HOMEWORK9_FILES})

set(HOMEWORK11_FILES
  src/homeworks/homework11/activity.cpp
  src/homeworks/homework11/cpm.cpp
  include/homeworks/homework11/activity.h
  include/homeworks/homework11/cpm.h
  ${UTIL_FILES}
)
add_executable(homework11 src/homeworks/homework11/main.cpp ${HOMEWORK11_FILES})

set(HOMEWORK12_FILES
  ${UTIL_FILES}
)
add_executable(homework12 src/homeworks/homework12/main.cpp ${HOMEWORK12_FILES})

###################
#### EXERCISES ####
###################

set(EXERCISE2_FILES
  ${UTIL_FILES}
)
add_executable(exercise2 src/exercises/exercise2/main.cpp ${EXERCISE2_FILES})

