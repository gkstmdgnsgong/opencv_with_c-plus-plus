# Proj Root/CMakeLists.txt
cmake_minimum_required(VERSION 3.10) # CMake 버전 명시 (최신 버전 권장)

project(BayabasAi LANGUAGES CXX) # 프로젝트 이름 설정, C++ 사용 명시 (원하는 프로젝트 이름으로 변경)

set(CMAKE_CXX_STANDARD 17) # C++17 표준 사용
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # macOS에서 dylib 링크 시 필요

# 디버그 빌드 시 디버그 정보 포함
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

# OpenCV 라이브러리 경로 설정
# Proj Root/Libraries/install/lib/cmake/opencv4 경로를 직접 지정
set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/Libraries/install/lib/cmake/opencv4")

# OpenCV 찾기 (REQUIRED: 필수 라이브러리임을 명시)
find_package(OpenCV REQUIRED)

# 인클루드 디렉토리 추가
include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src # src 폴더를 인클루드 경로에 추가 (main.cpp가 여기 있으므로)
)

# 소스 파일 목록 가져오기
file(GLOB SOURCES "src/*.cpp")
message(STATUS "SOURCES: ${SOURCES}") # 빌드 시 소스 파일 목록 출력

# 실행 파일 생성
add_executable(${PROJECT_NAME} ${SOURCES}) # PROJECT_NAME은 project()에서 정의한 이름

# OpenCV 라이브러리와 링크
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})