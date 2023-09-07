#CMake
sudo apt install libssl-dev
wget https://github.com/Kitware/CMake/releases/download/v3.24.2/cmake-3.24.2.tar.gz
tar -zxvf cmake-3.24.2.tar.gz
cd cmake-3.24.2
sudo ./bootstrap
sudo gmake
sudo make install


#Clang
apt install clang

