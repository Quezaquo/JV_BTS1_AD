#include "prototypes.h"


SDL_Window* window;
SDL_Renderer* renderer;


SDL_Renderer* getrenderer(void)
{
    return renderer;
}


void init(char* title)
{
    window = SDL_CreateWindow(										// on cree la fenetre selon les parametres :
        title,											            // recuperation du titre via title
        SDL_WINDOWPOS_UNDEFINED,									// init x
        SDL_WINDOWPOS_UNDEFINED,									// init y
        WINDOW_WIDTH,												// largeur (en pixel)
        WINDOW_HEIGHT,											    // hauteur
        SDL_WINDOW_OPENGL
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // on cree le renderer ici 

    if (window == NULL)	// verification si la fenêtre a bien été créée sans erreur
    {
        printf("Impossible de creer la fenetre : %s\n", SDL_GetError());
        fprintf(stdout, "Message d’erreur (%s) (avec la window)\n", SDL_GetError()); // ecrit le message d'erreur dans un fichier txt externe
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))  // init de la lib des imgs
    {
        printf("SDL_image n'a pu être initialisée! SDL_image Error: %s\n", IMG_GetError());
        fprintf(stdout, "Message d’erreur (%s) (avec le IMG)\n", IMG_GetError()); // ecrit le message d'erreur dans un fichier txt externe
        exit(1);
    }

    if (TTF_Init() < 0) // init de la lib de gestion de texte ttf
    {
        printf("Impossible d'initialiser SDL TTF: %s\n", TTF_GetError());
        fprintf(stdout, "Message d’erreur (%s) (avec le TTF)\n", TTF_GetError()); // ecrit le message d'erreur dans un fichier txt externe
        exit(1);
    }
}


void loadGame(void) // appel au chargement de notre map
{
    initMap();
    initPlayerSprites();
}

void cleanup() // pour clean le jeu | et libérer de la memoire 
{
    cleanMap();
    cleanPlayer();

    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;

    TTF_Quit();
    SDL_Quit();
}