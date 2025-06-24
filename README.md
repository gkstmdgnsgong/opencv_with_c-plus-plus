# opencv_with_c-plus-plus
opencv(c++)와 cmake 컴파일러를 이용한 영상 처리 프로젝트

## 1. 🗂️ 프로젝트 Git
Repository 구조와 사용설명에 대해 안내합니다.
Push 또는 Commit 하실 때 아래 구조와 사용설명에 따라주시면 감사드리겠습니다.

### 1.1 브랜치를 추가합니다.
*기능 추가* 시 아래와 같이 입력합니다.
```
features/원하는 이름
```
*버그로 인한* 브랜치 추가 시 아래와 같이 입력합니다.
```
bug/버그가 발생한 기능브랜치 이름 사용
```
**기타 사항**
dev: 개발 후 머징될 브랜치입니다.
release: 릴리즈 버전 배포 시 사용될 브랜치입니다.
beta: 베타 테스트 시 사용될 브랜치입니다.

**dev**는 머징만을 위해 사용합니다.
**beta**는 머징 후 테스트 할 때 태그로 버전을 붙여 빌드합니다.
**release**는 실제 라이브러리 배포시 태그로 버전을 붙여 빌드 후 각 플랫폼에 배포합니다.

### 1.2 Commit를 합니다.
*기능추가*
```
[features_add] 원하는 문구 입력
```
*기능수정*
```
[features_modi] 원하는 문구 입력
```
*버그수정*
```
[bug_modi] 원하는 문구입력
```

## 2. 💻 프로젝트 언어

- 언어는 C++

- 빌드는 Cmake로 진행합니다.

### 2.1 사용 IDE

VSCode에 C/C++ 확장팩(C/C++ for Visual Studio Code)을 설치하여 사용합니다.

### 2.2 라이브러리

1. OpenCV C++ 4.x

2. Cmake

## 3. 💾 디버깅 방법 (VSC, Mac 기준)

현재 OpenCV는 이 프로젝트에 포함되어 있습니다.

따라서 OpenCV를 Brew로 설치하지 않아도 되며 설치했더라도 이미 프로젝트 자체에서만 사용되도록 설정되어 있습니다.
    왜 OpenCV를 brew로 설치하지 않고 프로젝트 내에 직접 포함시키나요?
    
    **의존성 관리의 용이성 및 환경 일관성 보장**
    
    프로젝트 내에 OpenCV를 직접 포함함으로써, 개발 환경에 상관없이 모든 개발자가 동일한 버전의 OpenCV를 사용하게 됩니다. 이는 다음과 같은 문제를 방지합니다:
    
    버전 불일치 문제: 개발자마다 다른 버전의 OpenCV가 설치되어 있어 발생하는 호환성 문제를 없앨 수 있습니다. 특정 함수나 기능이 다른 버전에서는 다르게 동작하거나 존재하지 않을 수 있는데, 이를 방지합니다.
    
    설치 환경 의존성 감소: 개발자가 각자의 시스템에 OpenCV를 개별적으로 설치할 필요가 없어집니다. 이는 특히 새로운 개발자가 프로젝트에 합류할 때 설정 시간을 줄여주고, 설치 과정에서의 오류를 방지합니다. Brew나 다른 패키지 관리자를 통해 설치할 경우, 시스템 환경에 따라 설치 과정이 복잡해지거나 예상치 못한 문제가 발생할 수 있습니다.
    
    배포 용이성: 나중에 프로젝트를 배포할 때, 필요한 모든 라이브러리가 프로젝트 내에 포함되어 있으므로 배포 과정이 훨씬 단순해집니다. 외부 라이브러리 의존성을 최소화하여 런타임 환경 설정에 대한 부담을 줄일 수 있습니다.
    
- brew install cmake를 통해 mac에 cmake를 설치하여 주십시오.

- brew install openexr를 통해 openxr를 설치하여 주십시오.

- 프로젝트를 VSCode로 열고 왼쪽 탭에 빌드탭으로 이동합니다.

- Debug OpenCV App with CMake (macOS)를 선택 후 디버깅합니다.

## 4. 🌄 내 프로젝트에 OpenCV 직접 포함하기 (단계별 상세 가이드)

새로운 C++ 프로젝트에 OpenCV 라이브러리를 직접 포함하고 VS Code에서 빌드 및 디버깅할 수 있도록 설정하는 방법을 상세하게 설명합니다. 이 방식은 **환경 의존성을 줄이고, 특정 OpenCV 버전을 고정하여 개발 환경의 일관성을 유지하는 데 큰 장점**이 있습니다.

### 4.1 프로젝트 기본 폴더 구조 생성

빈 프로젝트를 시작할 때 다음과 같이 기본 폴더 구조를 만듭니다.

```
Proj Root/
├── src/
│   └── main.cpp
└── Libraries/
```

- `Proj Root`: 여러분의 프로젝트 최상위 폴더입니다.
- `src`: C++ 소스 코드를 담을 폴더입니다.
- `Libraries`: 외부 라이브러리(여기서는 OpenCV)를 관리할 폴더입니다.

**명령어**:

``` Bash
# 프로젝트 최상위 폴더 생성 (예: my_opencv_project)
mkdir my_opencv_project
cd my_opencv_project

# src 폴더 생성 및 main.cpp 파일 생성
mkdir src
touch src/main.cpp

# Libraries 폴더 생성
mkdir Libraries
```

### 4.2 OpenCV 소스 코드 클론

`Libraries` 폴더 안에 OpenCV의 소스 코드를 GitHub에서 클론합니다.

```Bash
cd Libraries
git clone https://github.com/opencv/opencv.git
cd .. # Proj Root로 다시 이동
```

이제 폴더 구조는 다음과 같습니다.

```
Proj Root/
├── src/
│   └── main.cpp
└── Libraries/
    └── opencv/ # OpenCV 소스 코드 폴더
```

### 4.3 OpenCV 빌드 폴더 생성 및 설정
클론한 OpenCV 소스 코드 내부에 빌드를 위한 폴더를 생성하고 CMake를 사용하여 빌드 설정을 진행합니다.
    왜 CMake를 사용하나요?

    CMake는 단순히 빌드 도구가 아니라, 다양한 플랫폼과 컴파일러에서 C++ 프로젝트를 표준화되고 유연하게 빌드할 수 있도록 돕는 메타 빌드 시스템입니다. "메타 빌드 시스템"이라는 말은 CMake 자체가 코드를 직접 컴파일하는 것이 아니라, 사용자가 작성한 CMakeLists.txt 파일을 기반으로 Makefiles (Unix/Linux), Visual Studio 프로젝트 파일 (Windows), Xcode 프로젝트 파일 (macOS)과 같은 실제 빌드 시스템의 프로젝트 파일을 생성해주는 역할을 한다는 의미입니다.

    다음은 CMake를 사용하는 주요 이유와 장점입니다.

    1. 플랫폼 독립성 (Cross-Platform Compatibility)
    가장 큰 장점 중 하나는 플랫폼 독립성입니다. 개발 환경은 Windows, macOS, Linux 등 다양할 수 있습니다. 각 운영체제마다 사용하는 빌드 시스템(예: Windows의 MSBuild, macOS의 Xcode, Linux의 Make)이 다르기 때문에, CMake가 없다면 각 플랫폼에 맞춰서 빌드에 관련한 작업을 해줘야 합니다.
    
    CMake는 하나의 CMakeLists.txt 파일만 있으면, 이 파일을 통해 어떤 플랫폼에서든 해당 플랫폼에 맞는 빌드 파일을 생성할 수 있습니다. 예를 들어, macOS에서는 Xcode 프로젝트를, Linux에서는 Makefile을, Windows에서는 Visual Studio 솔루션을 생성하여 개발자가 어떤 환경에서든 동일한 코드로 빌드할 수 있게 합니다.

    2. 복잡한 프로젝트 관리 용이성
    규모가 커지고 라이브러리 의존성이 많아지는 C++ 프로젝트에서는 빌드 시스템을 직접 관리하는 것이 매우 복잡해집니다.
    
    의존성 관리: CMake는 프로젝트의 여러 모듈이나 외부 라이브러리(예: OpenCV) 간의 의존성을 쉽게 정의하고 관리할 수 있도록 돕습니다. find_package, target_link_libraries, include_directories 같은 명령어를 통해 필요한 라이브러리를 찾고 링크하는 과정을 간소화합니다.
    
    모듈화: 대규모 프로젝트를 여러 작은 하위 모듈로 나누고, 각 모듈을 CMake를 통해 효율적으로 빌드하고 연결할 수 있습니다.
    
    3. 쉬운 라이브러리 통합
    OpenCV와 같이 널리 사용되는 C++ 라이브러리들은 대부분 CMake를 통해 빌드하고 설치할 수 있도록 제공됩니다. 이는 CMake가 라이브러리 통합을 위한 사실상의 표준이 되었음을 의미합니다.
    
    find_package(): CMake의 find_package() 명령을 사용하면, 시스템에 설치된 또는 특정 경로에 있는 라이브러리를 자동으로 찾아서 프로젝트에 포함시킬 수 있습니다. 이로 인해 라이브러리 경로 설정이나 링크 옵션 지정과 같은 번거로운 수작업을 줄일 수 있습니다.

    4. 강력하고 유연한 설정
    CMake는 단순히 빌드 파일을 생성하는 것을 넘어, 프로젝트 빌드 과정을 매우 유연하게 제어할 수 있습니다.
    
    - 컴파일러 플래그 설정: 디버그/릴리즈 모드, 최적화 수준, 특정 경고 옵션 등 다양한 컴파일러 플래그를 CMakeLists.txt 파일 내에서 쉽게 설정할 수 있습니다.
    
    - 조건부 빌드: 특정 OS나 컴파일러 버전에 따라 다르게 동작해야 하는 코드나 모듈을 조건부로 빌드하거나 제외할 수 있습니다.
    
    - 테스트 및 설치 규칙 정의: add_test() 명령을 통해 테스트를 정의하고, install() 명령을 통해 빌드된 결과물을 특정 경로에 설치하는 규칙을 쉽게 만들 수 있습니다.

    5. IDE 통합
    Visual Studio Code (VS Code)와 같은 최신 IDE들은 CMake를 기본적으로 지원하거나 CMake 통합 확장 기능을 제공합니다.
    
    VS Code의 C/C++ 확장팩은 CMakeLists.txt 파일을 자동으로 인식하고, IntelliSense, 빌드 태스크, 디버깅 설정을 CMake 파일에 기반하여 자동 또는 쉽게 구성할 수 있도록 돕습니다. 이는 개발 워크플로우를 크게 간소화합니다.

```Bash
cd Libraries/opencv
mkdir build && cd build # 'build' 폴더 생성 및 이동
```

이제 OpenCV를 **릴리즈(Release)** 모드로 빌드하고, 설치될 경로를 `Libraries/install`로 지정합니다. 이 `install` 폴더는 나중에 컴파일러가 OpenCV를 찾을 경로가 됩니다.

```Bash
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../../install ..
# .. 은 상위 디렉토리 (opencv 폴더)를 참조하고, ../../install은 Proj Root/Libraries/install을 참조합니다.
```

### 4.4 OpenCV 빌드 및 설치 (가장 오래 걸리는 단계!)

CMake 설정이 완료되면, 실제로 OpenCV 라이브러리를 컴파일하고 `dylib` 형태로 추출합니다.

```Bash
make -j
```

**참고**: `-j` 옵션 뒤에 숫자를 붙여 컴퓨터 코어 수를 지정할 수 있지만, 지정하지 않아도 CMake가 자동으로 코어 수를 감지하여 최적화된 빌드를 시작합니다. 이 과정은 **매우 오래 걸릴 수 있으니** 잠시 쉬는 것을 추천합니다!

빌드가 완료되면, 추출된 라이브러리들을 `install` 폴더로 복사합니다. 이 `install` 폴더는 `Libraries` 폴더 바로 아래에 생성됩니다.

``` Bash
make install
```

이제 폴더 구조는 다음과 같아집니다.

```
Proj Root/
├── src/
│   └── main.cpp
└── Libraries/
    ├── opencv/
    │   └── build/ # OpenCV 빌드 임시 파일들
    └── install/ # ✨ OpenCV 최종 라이브러리 및 헤더 파일 (이동 불필요, 이미 여기에 생성됨)
```

**원래 문서에서는 `Libraries/install`로 옮기라는 지시가 있었으나, 위 `cmake` 명령어(`-DCMAKE_INSTALL_PREFIX=../../install`)를 사용하면 `make install` 시 자동으로 `Proj Root/Libraries/install` 경로에 생성되므로, 별도로 폴더를 옮길 필요가 없습니다.** (불필요한 절차를 제거한 부분입니다.)

### 4.5 VS Code C++ 확장팩 설정 (.vscode 폴더)
VS Code의 C++ 확장팩이 우리가 빌드한 OpenCV를 인식하도록 설정 파일을 생성합니다. 프로젝트 루트 경로 (`Proj Root`)에 `.vscode` 폴더를 생성합니다.

``` Bash
cd Proj Root # 현재 위치가 Proj Root가 아니라면 이동
mkdir .vscode
```
#### 4.5.1 `c_cpp_properties.json` 파일 생성
`.vscode` 폴더 안에 `c_cpp_properties.json` 파일을 만들고 아래 내용을 붙여넣으세요. 이 파일은 IntelliSense가 헤더 파일을 찾을 경로를 지정합니다.

``` JSON
// Proj Root/.vscode/c_cpp_properties.json
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "${workspaceFolder}/Libraries/install/include/opencv4",
                "${workspaceFolder}/src/include" // src 내에 추가 include 폴더가 있다면 이곳에 지정
            ],
            "defines": [],
            "macFrameworkPath": [
                "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks"
            ],
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "macos-clang-arm64",
            "compilerPath": "/usr/bin/clang"
        }
    ],
    "version": 4
}
```

- `"${workspaceFolder}/Libraries/install/include/opencv4"`: 직접 빌드한 OpenCV의 헤더 파일 경로입니다.
- `"${workspaceFolder}/src/include"`: 여러분의 프로젝트 소스 코드 내에 사용자 정의 헤더 파일이 있다면 이 경로를 추가할 수 있습니다. (현재 예시에서는 필수는 아님)

#### 4.5.2 `tasks.json` 파일 생성
`.vscode` 폴더 안에 `tasks.json` 파일을 만들고 아래 내용을 붙여넣으세요. 이 파일은 VS Code의 빌드 태스크를 정의합니다.

```JSON
// Proj Root/.vscode/tasks.json
{
    "version": "2.0.0",
    "runner": "terminal",
    "type": "shell",
    "echoCommand": true,
    "presentation": {
        "reveal": "always"
    },
    "tasks": [
        {
            "type": "shell",
            "label": "C/C++: clang++ Build with OpenCV, CMake (macOS)",
            "command": "cmake",
            "args": ["-S", ".", "-B", "build", "&&", "cmake", "--build", "build"],
            "group": "build",
            "problemMatcher": []
        }
    ]
}
```

- 이 태스크는 CMake를 사용하여 프로젝트를 빌드합니다. `-S .`는 현재 디렉토리(프로젝트 루트)를 소스 디렉토리로, `-B build`는 `build` 폴더를 빌드 결과가 저장될 디렉토리로 지정합니다. `cmake --build build`는 실제 빌드를 수행합니다.

#### 4.5.3 `launch.json` 파일 생성

`.vscode` 폴더 안에 `launch.json` 파일을 만들고 아래 내용을 붙여넣으세요. 이 파일은 VS Code의 디버깅 설정을 정의하며, `tasks.json`에서 정의한 빌드 태스크를 실행하기 전에 실행하도록 지정합니다.

```JSON
// Proj Root/.vscode/launch.json
{
    "version": "0.2.0",
    "configurations": [
      {
        "name": "Debug OpenCV App with CMake (macOS)",
        "type": "cppdbg",
        "request": "launch",
        "program": "${workspaceFolder}/build/BayabasAi",
        "stopAtEntry": false,
        "cwd": "${workspaceFolder}",
        "environment": [],
        "MIMode": "lldb",
        "preLaunchTask": "C/C++: clang++ Build with OpenCV, CMake (macOS)",
        "externalConsole": true //한글 깨짐 방지하기 위해 외부 터미널에서 엽니다
      }
    ]
  }
```

- `"program": "${workspaceFolder}/build/YourProject"`: 이 경로는 빌드된 실행 파일의 경로입니다. `YourProject` 부분을 **여러분이 `CMakeLists.txt`에서 정의할 프로젝트 이름으로 변경해야 합니다.** (아래 4.6 단계 참고)

### 4.6 CMake 프로젝트 파일 (`CMakeLists.txt`) 생성

프로젝트 루트 (`Proj Root`)에 `CMakeLists.txt` 파일을 생성하고 아래 코드를 작성합니다. 이 파일은 CMake에게 프로젝트를 어떻게 빌드할지 알려줍니다.

``` CMake
# Proj Root/CMakeLists.txt
cmake_minimum_required(VERSION 3.10) # CMake 버전 명시 (최신 버전 권장)

project(YourProject LANGUAGES CXX) # 프로젝트 이름 설정, C++ 사용 명시 (원하는 프로젝트 이름으로 변경)

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
```

- `project(YourProject LANGUAGES CXX)`: 여기서 `YourProject` 부분이 여러분의 프로젝트 실행 파일 이름이 됩니다. `launch.json`의 `program` 경로와 일치해야 합니다.
- `set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/Libraries/install/lib/cmake/opencv4")`: 이 경로가 올바르게 설정되었는지 다시 한번 확인하세요. `CMAKE_SOURCE_DIR`는 `CMakeLists.txt`가 있는 프로젝트 루트를 의미합니다.
- `include_directories(${CMAKE_SOURCE_DIR}/src)`: `main.cpp` 파일이 `src` 폴더에 있기 때문에 이 경로를 추가해야 컴파일러가 `main.cpp`를 찾을 수 있습니다.

### 4.7 `main.cpp` 파일 준비
`src/main.cpp` 파일을 열고 아래 코드를 작성합니다. 이 코드는 OpenCV를 사용하여 이미지를 읽고 화면에 표시하는 간단한 예제입니다.

``` C++
// src/main.cpp
#include <iostream>
#include <opencv2/opencv.hpp> // OpenCV 헤더 포함

// OpenCV 네임스페이스 사용
using namespace cv;
using namespace std; // std::string, std::cout 등을 위해 추가

int main()
{
    // 이미지 파일 경로 (반드시 실제 유효한 이미지 파일 경로로 변경하세요!)
    string path = "path/to/your/image.jpg"; // 예: "C:/Users/YourUser/Pictures/my_image.jpg" 또는 "/Users/YourUser/Pictures/my_image.jpg"

    // 이미지 읽기
    Mat imgRead = imread(path);

    // 이미지가 성공적으로 로드되었는지 확인
    if (imgRead.empty()) {
        cerr << "오류: 이미지를 로드할 수 없습니다. 경로를 확인하세요: " << path << endl;
        return -1; // 에러 코드 반환
    }

    // 이미지 창에 표시
    imshow("Hello OpenCV World", imgRead);

    // 키 입력 대기 (0은 무한 대기)
    waitKey(0);

    return 0;
}

```

- **중요**: `string path = "이미지 파일 주소(jpg, bmp 등)";` 부분을 **실제 존재하는 이미지 파일의 절대 또는 상대 경로로 반드시 변경**해야 합니다. 그렇지 않으면 이미지를 찾지 못해 오류가 발생합니다.

### 4.8 🎉 디버깅 시작!

이제 VS Code에서 디버깅할 준비가 완료되었습니다!

1. VS Code 왼쪽 사이드바에서 **'실행 및 디버그' (Run and Debug)** 탭을 클릭합니다.
2. 상단 드롭다운 메뉴에서 **"Debug OpenCV App with CMake (macOS)"**를 선택합니다.
3. 녹색 재생 버튼을 클릭하여 디버깅을 시작합니다.

성공적으로 설정되었다면, 지정한 이미지가 새 창에 나타날 것입니다.