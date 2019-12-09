cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11 -O3)

project(DSST)
#修改成捏OpenCV路径即可
set(OpenCV_DIR "/home/xz/opencv3.4.3/opencv-3.4.3/build")
set(OpenCV_INCLUDE_DIRS "/home/xz/opencv3.4.3/opencv-3.4.3/include") 
find_package(OpenCV REQUIRED)

find_package(OpenMP REQUIRED)
if (OPENMP_FOUND)
    message("OpenMP found!")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# 返回hog特征的大小
add_executable(bg_multi Main.cpp mainWindow.cpp MultiCue.cpp algorithms.cpp)
target_link_libraries(bg_multi ${OpenCV_LIBS} -lpthread -fopenmp -lsqlite3 openblas)


