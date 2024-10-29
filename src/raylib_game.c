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

typedef struct Enemy {
    Vector2 position;
    float speed;
    bool alive; 
    Rectangle collision;
} Enemy;

typedef struct MouseCol {
    Rectangle collision;
} MouseCol;

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

<<<<<<< HEAD
Vector2 getTargetRoundPoint(Vector2 p, Vector2 t, float radius) {
    Vector2 radiusVec = Vector2Subtract(t, p);
    Vector2 normVec = Vector2Normalize(radiusVec);
    Vector2 bigVec = Vector2Scale(normVec, radius);
    Vector2 lastVec = Vector2Add(bigVec, p);
    return lastVec;
}

=======
double getAngleDeg(Vector2 p1, Vector2 p2) {
    double thing1 = p2.x - p1.x;
    double thing2 = p2.y - p1.y;
    double angle_rad = atan2(thing1, thing2);
    double angle_deg = angle_rad * (180.0 / PI);
    return angle_deg;
}

double getAngleRad(Vector2 p1, Vector2 p2) {
    double thing1 = p2.x - p1.x;
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
>>>>>>> e81b1d1 (yuh)
int main(void)
{
#if !defined(_DEBUG)
    SetTraceLogLevel(LOG_NONE);         // Disable raylib trace log messages
#endif
    InitWindow(screenWidth, screenHeight, "v0.0.1");
    Player player = { 0 };
    player.position = (Vector2){ screenWidth / 2 , screenHeight / 2 };

    player.speed = 0;
    Rectangle playerRect = {player.position.x, player.position.y, 40.0f, 40.0f};
    Rectangle wand = {player.position.x, player.position.y, 40.0f, 20.0f};
    printf("%f \n", player.position.x);
    // TODO: Load resources / Initialize variables at this point
    
    target = LoadRenderTexture(screenWidth, screenHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);
    MouseCol mouse;
    mouse.collision.height = 10;
    mouse.collision.width = 10;
    Enemy enemy = { 0 };
    enemy.collision.x = 40;
    enemy.collision.y = 300;
    enemy.collision.width = 40;
    enemy.collision.height = 40;

    

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginTextureMode(target);
        ClearBackground(RAYWHITE);
<<<<<<< HEAD
=======
        // TODO: Draw your game screen here
        Vector2 wandPos = getPointOnCircle(50.0f, player.position, GetMousePosition());
        //DrawText(result, screenWidth / 2, (screenHeight / 2) + 50, 30, BLACK);
        Vector2 radiusVec = Vector2Subtract(GetMousePosition(), player.position);
        Vector2 normVec = Vector2Normalize(radiusVec);
        Vector2 bigVec = Vector2Scale(normVec, 50.0f);
>>>>>>> e81b1d1 (yuh)
        EndTextureMode();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            DrawText("%i\n", GetMouseX(), GetMouseY(), 15, BLACK);
        }
        mouse.collision.x = GetMouseX() - (mouse.collision.width / 2);
        mouse.collision.y = GetMouseY() - (mouse.collision.height / 2);


        BeginDrawing();
        ClearBackground(RAYWHITE);
<<<<<<< HEAD
        DrawRectangleRec(playerRect, RED);
        DrawCircleLinesV(player.position, 50.0f, BLUE);
        DrawRectanglePro(wand, (Vector2){ 0, 0 }, 0.0f, BLUE);

        DrawCircleV(getTargetRoundPoint(player.position, GetMousePosition(), 50.0f), 10.0f, ORANGE);
        DrawRectangleRec(enemy.collision, BLUE);
        DrawRectangleRec(mouse.collision, BLACK);
=======
        
        
        Rectangle playerRect = {player.position.x, player.position.y, 40.0f, 40.0f};
        DrawRectanglePro(playerRect, player.position, 0.0f, RED);
        DrawCircleLinesV(player.position, 50.0f, BLUE);

        DrawCircleV(Vector2Add(bigVec, player.position), 10.0f, ORANGE);


        //DrawLine(player.position.x, player.position.y, getPointOnCircle(20.0f, player.position, GetMousePosition()).x, getPointOnCircle(20.0f, player.position, GetMousePosition()).y, BLACK);
        //Vector2Rotate(player.position, Vector2Angle(player.position, GetMousePosition()));
>>>>>>> e81b1d1 (yuh)

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
