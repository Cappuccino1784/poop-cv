#include "raylib.h"

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1200, 800, "Poop Analyzer");
    SetTargetFPS(60);

    Texture2D image = {0};   // empty texture to start

    while (!WindowShouldClose()) {

        // ── check if a file was dropped ──
        if (IsFileDropped()) {
            FilePathList files = LoadDroppedFiles();

            // unload previous image if any
            if (image.id != 0) UnloadTexture(image);

            // load the dropped file as a texture
            image = LoadTexture(files.paths[0]);

            UnloadDroppedFiles(files);
        }

        // ── draw ──
        BeginDrawing();
            ClearBackground((Color){20, 20, 40, 255});

            if (image.id != 0) {
                // draw image scaled to fit window
                DrawTexturePro(image,
                    (Rectangle){0, 0, image.width*2, image.height*2},
                    (Rectangle){0, 0, GetScreenWidth(), GetScreenHeight()},
                    (Vector2){0, 0}, 0.0f, WHITE);
            } else {
                // show instructions when no image loaded
                DrawText("Drop an image onto this window", 20, 20, 20, GRAY);
            }

        EndDrawing();
    }

    if (image.id != 0) UnloadTexture(image);
    CloseWindow();
    return 0;
}