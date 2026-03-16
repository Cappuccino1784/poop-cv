# poop-cv

A C + raylib desktop app that opens a resizable window and lets you drag and drop an image for full-window display.

## Project Structure

- `src/main.c`: Main application entry point.
- `include/`: Header files (if/when added).
- `tests/`: Test files (if/when added).
- `build/`: Generated build output (ignored by Git).

## Requirements

### Windows (MSYS2 + MinGW)

- CMake 3.16+
- GCC / MinGW toolchain
- raylib installed in `C:/msys64/ucrt64`

Current CMake configuration uses the MSYS2 path above on Windows.

### Linux / Docker

- Docker 24+

The Linux build uses `find_package(raylib REQUIRED)`.

## Build and Run Locally

### Option 1: VS Code task (single file compile)

From your current task setup:

```bash
C:\MinGW\bin\gcc.exe -fdiagnostics-color=always -g src\main.c -o src\main.exe
```

### Option 2: CMake (recommended)

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

On Windows, the executable is typically in `build/` as `my_window.exe`.

## Docker

### Build image

```bash
docker build -t poop-cv:latest .
```

### Run container

This is a GUI app; to display the window from a container you need X11/Wayland forwarding.

Example (Linux with X11):

```bash
docker run --rm -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix poop-cv:latest
```

If you only want to verify compilation in Docker, the build step above is enough.

## Prepare for GitHub Upload

1. Initialize repository (if needed):

```bash
git init
```

2. Add files:

```bash
git add .
```

3. Commit:

```bash
git commit -m "Initial project setup: CMake, Docker, docs"
```

4. Add remote:

```bash
git remote add origin https://github.com/<your-user>/<your-repo>.git
```

5. Push main branch:

```bash
git branch -M main
git push -u origin main
```

## Notes

- `build/` is intentionally ignored in `.gitignore`.
- If your Windows raylib path differs from `C:/msys64/ucrt64`, update `CmakeLists.txt`.
- For cross-platform local builds outside Docker, install raylib and ensure CMake can find it.
