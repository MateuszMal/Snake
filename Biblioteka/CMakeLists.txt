cmake_minimum_required(VERSION 3.4)
project(Biblioteka)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES
        include/Food.h src/Food.cpp
        include/Snake.h src/Snake.cpp
        test/master.cpp
        src/Settings.cpp include/Settings.h src/gameFunctions.cpp include/gameFunctions.h src/Menu.cpp include/Menu.h src/Options.cpp include/Options.h src/Controls.cpp include/Controls.h src/GameExceptions.cpp include/GameExceptions.h)

add_library(Biblioteka ${SOURCE_FILES})

target_include_directories(Biblioteka PUBLIC include)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
target_link_libraries (Biblioteka sfml-graphics sfml-window sfml-system)

#Sekcja testów
find_package(Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_Snake_FILES
        test/master.cpp
        test/SnakeTest.cpp
        test/FoodTest.cpp test/MenuTest.cpp test/gameFunctionsTest.cpp test/OptionsTest.cpp)

add_executable (TestSnake ${SOURCE_TEST_Snake_FILES} )

#dołącz bibliotekę z testowanymi klasami do programu testów
target_link_libraries (TestSnake
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestClient. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(TestBiblioteki1 TestCRent
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})


enable_testing()


