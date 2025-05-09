# SDL2 CMake Starter

## Overview
This repo serves as a starter template for building a C++ project with **CMake**, configured to work with **SDL2** and **SDL2_image** libraries.

It provides a minimal `CMakeLists.txt` that sets up compilation and linking for SDL2 and SDL2_image, assuming the libraries are installed via **Homebrew** and symlinked into local `include` and `lib` directories inside the project.

## 📁 Project Structure
.
├── build/             # Out-of-source build directory
├── include/           # Local include folder
│   ├── SDL2 -> /opt/homebrew/Cellar/sdl2/2.x.x/include/SDL2
│   └── SDL2_image -> /opt/homebrew/Cellar/sdl2_image/2.x.x/include/SDL2
├── lib/               # Local lib folder
│   ├── SDL2 -> /opt/homebrew/Cellar/sdl2/2.x.x/lib
│   └── SDL2_image -> /opt/homebrew/Cellar/sdl2_image/2.x.x/lib
├── src/               # Source files
│   └── main.cpp
├── CMakeLists.txt     # Build configuration
└── README.md

## 🛠️ Setup Instructions

1. Install SDL2 and SDL2_image via Homebrew:

```bash
brew install sdl2 sdl2_image
```

2. Create symlinks inside include/ and lib/:

```bash
ln -s <target_path> <link_path>
```

On my machine I use the following commands:

```bash
ln -s /opt/homebrew/Cellar/sdl2/2.32.6/include/SDL2 ./include/SDL2
ln -s /opt/homebrew/Cellar/sdl2_image/2.8.8/include/SDL2 ./include/SDL2_image
ln -s /opt/homebrew/Cellar/sdl2_image/2.8.8/lib ./lib/SDL2_image
ln -s /opt/homebrew/Cellar/sdl2/2.32.6/include/SDL2 ./include/SDL2
```

3. Create a build directory and build the project:

```bash
mkdir build
cd build
cmake ..
make
```

4. Run the executable:
```bash
./<project_name>
```

## Configure

1. Change the project name in the project() call in the root CMakeLists.txt to your liking.