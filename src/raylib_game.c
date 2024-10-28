/*******************************************************************************************
*
*   raylib gamejam template
*
*   Template originally created with raylib 4.5-dev, last time updated with raylib 5.0
*
*   Template licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2022-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#if defined(PLATFORM_WEB)
    #define CUSTOM_MODAL_DIALOGS            // Force custom modal dialogs usage
    #include <emscripten/emscripten.h>      // Emscripten library - LLVM to JavaScript compiler
#endif

#include <stdio.h>                          // Required for: printf()
#include <stdlib.h>                         // Required for: 
#include <string.h>                         // Required for: 
#include <math.h>
#include <raymath.h>

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
// Simple log system to avoid printf() calls if required
// NOTE: Avoiding those calls, also avoids const strings memory usage
#define SUPPORT_LOG_INFO
#if defined(SUPPORT_LOG_INFO)
    #define LOG(...) printf(__VA_ARGS__)
#else
    #define LOG(...)
#endif

#define PLAYER_SIZE 40
//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum { 
    SCREEN_LOGO = 0, 
    SCREEN_TITLE, 
    SCREEN_GAMEPLAY, 
    SCREEN_ENDING
} GameScreen;

typedef struct Player {
    Vector2 position;
    float speed;
} Player;
// TODO: Define your custom data types here

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;

static RenderTexture2D target = { 0 };  // Render texture to render our game

// TODO: Define global variables here, recommended to make them static

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
static void UpdateDrawFrame(void);      // Update and Draw one frame

double getAngleDeg(Vector2 p1, Vector2 p2) {
    double thing1 = p2.x - p2.x;
    double thing2 = p2.y - p1.y;
    double angle_rad = atan2(thing1, thing2);
    double angle_deg = angle_rad * (180.0 / PI);
    return angle_deg;
}

double getAngleRad(Vector2 p1, Vector2 p2) {
    double thing1 = p2.x - p2.x;
    double thing2 = p2.y - p1.y;
    double angle_rad = atan2(thing1, thing2);
    double angle_deg = angle_rad * (180.0 / PI);
    return angle_rad;
}

Vector2 getPointOnCircle(float radius, Vector2 p1, Vector2 p2) {
    float cx, cy;
    double angle_rad = getAngleRad(p1, p2);
    cx = radius * cos(angle_rad);
    cy = radius * sin(angle_rad);
    return (Vector2){cx,cy};
}

//----------------------- -------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
#if !defined(_DEBUG)
    SetTraceLogLevel(LOG_NONE);         // Disable raylib trace log messages
#endif

    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "v0.0.1");
    Player player = { 0 };
    player.position = (Vector2){ screenWidth / 2 , screenHeight / 2 };
    player.speed = 0;
    //Rectangle wand = { 400, 400, 20, 40};
    //Vector2 mousePos;
    // TODO: Load resources / Initialize variables at this point
    
    // Render texture to draw full screen, enables screen scaling
    // NOTE: If screen is scaled, mouse input should be scaled proportionally
    target = LoadRenderTexture(screenWidth, screenHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);     // Set our game frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button
    {
        //mousePos = (Vector2){GetMouseX(), GetMouseY()};
        BeginTextureMode(target);
        ClearBackground(RAYWHITE);
        // TODO: Draw your game screen here
        Vector2 wandPos = Vector2Rotate(player.position, Vector2Angle(player.position, GetMousePosition()));
        //wandPos.x += player.position.x / 4;
       // wandPos.y += player.position.y / 4;
        //DrawText(result, screenWidth / 2, (screenHeight / 2) + 50, 30, BLACK);
        printf("%f", player.position.y);
        EndTextureMode();
    
        // Render to screen (main framebuffer)
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        // Draw render texture to screen, scaled if required
        DrawTexturePro(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, -(float)target.texture.height }, (Rectangle){ 0, 0, (float)target.texture.width, (float)target.texture.height }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        

        Rectangle playerRect = {player.position.x, player.position.y, 40.0f, 40.0f};
        DrawRectanglePro(playerRect, player.position, 0.0f, RED);
        DrawCircleLinesV(player.position, 50.0f, BLUE);
        DrawCircleV(wandPos, 5, ORANGE);
        //Vector2Rotate(player.position, Vector2Angle(player.position, GetMousePosition()));

        // TODO: Draw everything that requires to be drawn at this point, maybe UI?
        EndDrawing();

    }
#endif

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadRenderTexture(target);
    
    // TODO: Unload all loaded resources at this point

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//--------------------------------------------------------------------------------------------
// Module functions definition
//--------------------------------------------------------------------------------------------
// Update and draw frame
void UpdateDrawFrame(void)
{
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update variables / Implement example logic at this point
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    // Render game screen to a texture, 
    // it could be useful for scaling or further shader postprocessing
    BeginTextureMode(target);
        ClearBackground(RAYWHITE);
        // TODO: Draw your game screen here
        DrawText("build test", screenWidth / 2, screenHeight / 2, 30, BLACK);
    EndTextureMode();
    
    // Render to screen (main framebuffer)
    BeginDrawing();
        ClearBackground(RAYWHITE);
        
        // Draw render texture to screen, scaled if required
        

        // TODO: Draw everything that requires to be drawn at this point, maybe UI?

    EndDrawing();
    //----------------------------------------------------------------------------------  
}
