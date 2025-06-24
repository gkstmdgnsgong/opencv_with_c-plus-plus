// src/main.cpp
#include <iostream>
#include <opencv2/opencv.hpp> // OpenCV 헤더 포함

// OpenCV 네임스페이스 사용
using namespace cv;
using namespace std; // std::string, std::cout 등을 위해 추가

int main()
{

    // 이미지 파일 경로 (반드시 실제 유효한 이미지 파일 경로로 변경하세요!)
    // 예: "C:/Users/YourUser/Pictures/my_image.jpg" 또는 "/Users/YourUser/Pictures/my_image.jpg"
    string path = "/Users/shhan/code/opencv_with_c-plus-plus/src/test-img.png";
    

    // 이미지 읽기
    Mat imgRead = imread(path);

    // 이미지가 성공적으로 로드되었는지 확인
    if (imgRead.empty()) {
        cerr << "오류: 이미지를 로드할 수 없습니다. 경로를 확인하세요: " << path << endl;
        return -1; // 에러 코드 반환
    }

    // 이미지 창에 표시
    imshow("Hello OpenCV World, but you cant use korean-hangul", imgRead);

    // 키 입력 대기 (0은 무한 대기)
    waitKey(0);

    return 0;
}