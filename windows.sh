mkdir build
cd build
cmake .. -D CMAKE_C_COMPILER="C:\Program Files\LLVM\bin\clang.exe" -D CMAKE_CXX_COMPILER="C:\Program Files\LLVM\bin\clang++.exe"
cmake --build . --target ALL_BUILD --config Release
