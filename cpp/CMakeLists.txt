# https://qiita.com/kekenonono/items/0fcf042bca2d3d17867a

set(SOURCE_CODE opencv_test CACHE NAME "Target object name")

cmake_minimum_required(VERSION 2.8)

project(test_cmake CXX)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(image1 src/image/image1.cpp)   
target_link_libraries(image1 ${OpenCV_LIBRARIES})

add_executable(image2 src/image/image2.cpp)   
target_link_libraries(image2 ${OpenCV_LIBRARIES})

add_executable(image3 src/image/image3.cpp)   
target_link_libraries(image3 ${OpenCV_LIBRARIES})

add_executable(image4 src/image/image4.cpp)   
target_link_libraries(image4 ${OpenCV_LIBRARIES})

add_executable(image5 src/image/image5.cpp)   
target_link_libraries(image5 ${OpenCV_LIBRARIES})

add_executable(image6 src/image/image6.cpp)   
target_link_libraries(image6 ${OpenCV_LIBRARIES})

add_executable(camera src/camera/camera.cpp)   
target_link_libraries(camera ${OpenCV_LIBRARIES})

add_executable(filter1 src/filter/filter1.cpp)   
target_link_libraries(filter1 ${OpenCV_LIBRARIES})

add_executable(filter2 src/filter/filter2.cpp)   
target_link_libraries(filter2 ${OpenCV_LIBRARIES})

add_executable(filter3 src/filter/filter3.cpp)   
target_link_libraries(filter3 ${OpenCV_LIBRARIES})

add_executable(filter4 src/filter/filter4.cpp)   
target_link_libraries(filter4 ${OpenCV_LIBRARIES})

add_executable(filter5 src/filter/filter5.cpp)   
target_link_libraries(filter5 ${OpenCV_LIBRARIES})