#include "definitions.h" // pour inclure le fichier .h des define du jeu evitant la repetition de grosse var

typedef struct Input    // inputs de touche du clavier
{

    int left, right, jump, attack; // q d space_bar a

} Input;

typedef struct Map     // gestion du fond (map)
{

    SDL_Texture* background;
    SDL_Texture* tileSet, * tileSetB;

    int beginX, beginY; // coo de depart du player

    int startX, startY; // coo du debut de la map

} Map;

typedef struct GameSprite // gestion des differents sprite du projet
{
    float x, y; // coordonnees du sprite

    int h, w; // largeur et hauteur du sprite

    int initX, initY; // coordonnes d'init du sprite

    int frameNumber; // num de la frame en cours
    int frameTimer; // temps de la frame
    int frameMax; // num de la frame max de la ligne du sprite sheet

    int etat; // etat du deplacement
    int direction; // direction de deplacement (gauche / droite => LOOK_LEFT / LOOK_RIGHT)

    int onGround; // test de presence sur le sol ou non

    float dirX, dirY; // var de collision 

    int saveX, saveY; // save des coo 

    int jump; // test de l'activation du saut 


} GameSprite;