#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


#define WINDOW_WIDTH 500 // largeur de la window
#define WINDOW_HEIGHT 500 // hauteur de la window

#define TIME_FRAMES_PLAYER 20 // temps entre 2 frames d'animation du joueur

#define PLAYER_WIDTH 32 // largeur d'un sprite
#define PLAYER_HEIGTH 32 // hauteur d'un sprite

#define PLAYER_SPEED 0.35 // vitesse de deplacement du joueur

#define IDLE 0 // animation idle (sans mouvement)
#define WALK 2 // animation de marche
#define JUMP 1 // animation de saut

#define LOOK_RIGHT 1 // si le joueur va à droite
#define LOOK_LEFT 2 // si le joueur va à gauche

#define GRAVITY_SPEED 0.8 // pour la gravité des sauts
#define MAX_FALL_SPEED 2 // vitesse de chute du player (1 pixel / frame)
#define JUMP_HEIGHT 11 // hauteur des sauts en pixel