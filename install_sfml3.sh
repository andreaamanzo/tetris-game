#!/usr/bin/env bash

set -e

echo "=== Installing dependencies for SFML 3 ==="
sudo apt update
sudo apt install -y git cmake g++ build-essential \
  libx11-dev libxrandr-dev libudev-dev libfreetype6-dev \
  libgl1-mesa-dev libopengl-dev libxrender-dev libxcb1-dev libxcb-image0-dev \
  libflac-dev libvorbis-dev libvorbisenc2 libvorbisfile3 libogg-dev \
  libpthread-stubs0-dev libjpeg-dev libxinerama-dev libxcursor-dev libxi-dev \
  libharfbuzz-dev

echo "=== Cloning SFML repository (master branch) ==="
if [ -d "SFML" ]; then
  echo "The SFML directory already exists, performing git pull..."
  cd SFML
  git pull
else
  git clone https://github.com/SFML/SFML.git /tmp/SFML
  cd /tmp/SFML
fi

echo "=== Creating build directory ==="
mkdir -p build
cd build

echo "=== Configuring CMake (Release, install to /usr/local) ==="
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local

echo "=== Building SFML 3 (using all available CPU cores) ==="
cmake --build . --parallel

echo "=== Installing SFML 3 to /usr/local (requires sudo) ==="
sudo cmake --install .

echo "=== Updating system linker cache (ldconfig) ==="
if [ -d "/usr/local/lib" ]; then
  echo "/usr/local/lib" | sudo tee /etc/ld.so.conf.d/usr-local-lib.conf >/dev/null
  sudo ldconfig
fi

echo
echo "SFML 3 installation completed!"
