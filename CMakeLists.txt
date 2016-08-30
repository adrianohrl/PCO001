project(PCO001)
cmake_minimum_required(VERSION 2.8)
include_directories(include)

###################
#### UTILITIES ####
###################

set(DISJOINT_SET_FILES
	 src/utilities/lists/disjoint_set/IntegerDisjointSet.cpp
	 src/utilities/lists/disjoint_set/StringDisjointSet.cpp
	 include/utilities/lists/disjoint_set/DisjointSet.h
	 include/utilities/lists/disjoint_set/DisjointSetInterface.h
	 include/utilities/lists/disjoint_set/IntegerDisjointSet.h
	 include/utilities/lists/disjoint_set/Node.h
	 include/utilities/lists/disjoint_set/StringDisjointSet.h
)
set(DOUBLY_LINKED_LIST_FILES
	 include/utilities/lists/doubly_linked_list/DoublyLinkedList.h
	 include/utilities/lists/doubly_linked_list/DoublyLinkedListInterface.h
	 include/utilities/lists/doubly_linked_list/Node.h
)
set(LISTS_FILES
	 ${DISJOINT_SET_FILES}
	 ${DOUBLY_LINKED_LIST_FILES}
)
set(QUEUE_FILES
	 include/utilities/queues/queue/Node.h
	 include/utilities/queues/queue/Queue.h
	 include/utilities/queues/queue/QueueInterface.h
	 include/utilities/queues/queue/QueueInverter.h
)
set(QUEUES_FILES
	 ${QUEUE_FILES}
)
set(STACK_FILES
	 include/utilities/stacks/stack/Node.h
	 include/utilities/stacks/stack/Stack.h
	 include/utilities/stacks/stack/StackInterface.h
)
set(DOUBLE_STACK_FILES
	 include/utilities/stacks/double_stack/Node.h
	 include/utilities/stacks/double_stack/DoubleStack.h
	 include/utilities/stacks/double_stack/DoubleStackInterface.h
)
set(STACKS_FILES
	 ${STACK_FILES}
	 ${DOUBLE_STACK_FILES}
)
set(BINARY_TREE_FILES
	 include/utilities/trees/binary_tree/Node.h
	 include/utilities/trees/binary_tree/BinaryTreeInterface.h
	 include/utilities/trees/binary_tree/BinaryTree.h
)
set(TREES_FILES
	 ${BINARY_TREE_FILES}
)
set(UTIL_FILES
	 ${LISTS_FILES}
	 ${QUEUES_FILES}
	 ${STACKS_FILES}
	 ${TREES_FILES}
)
add_executable(disjoint_set src/utilities/lists/disjoint_set/main.cpp ${UTIL_FILES})
add_executable(doubly_linked_list src/utilities/lists/doubly_linked_list/main.cpp ${UTIL_FILES})
add_executable(stack src/utilities/stacks/stack/main.cpp ${UTIL_FILES})
add_executable(queue src/utilities/queues/queue/main.cpp ${UTIL_FILES})
add_executable(binary_tree src/utilities/trees/binary_tree/main.cpp ${UTIL_FILES})

###################
#### HOMEWORKS ####
###################

set(HOMEWORK1_FILES
	 ${UTIL_FILES}
	 src/homeworks/homework1/PhoneBook.cpp
	 src/homeworks/homework1/PersonInfo.cpp
	 include/homeworks/homework1/PhoneBook.h
	 include/homeworks/homework1/PersonInfo.h
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
	 src/homeworks/homework4/IntegerDisjointSets.cpp
	 include/homeworks/homework4/IntegerDisjointSets.h
)
add_executable(homework4 src/homeworks/homework4/main.cpp ${HOMEWORK4_FILES})

###################
#### EXERCISES ####
###################

set(EXERCISE2_FILES
	 ${UTIL_FILES}
)
add_executable(exercise2 src/exercises/exercise2/main.cpp ${EXERCISE2_FILES})
