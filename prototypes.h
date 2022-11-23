#include "structs.h"

// extern permet de dire au programme que la fonction se trouve dans un fichier du projet mais pas forcément celui en cours


extern void getInput(Input* input); // recupere l'etat des differents inputs du clavier (q d a space_bar)
extern void gestionInputs(Input* input); // traite la fonction getInput()

extern void cleanup(void); // pour clean le jeu | et libérer de la memoire 
extern void cleanMap(void); // pour clean la map
extern void cleanPlayer(void); // pour clean le player

extern void drawGame(void); // dessine le background du jeu aux coo 0 0
extern void drawOneImage(SDL_Texture*, int, int); // dessine une image choisie à l'ecran selon des coo x et y
extern void drawPlayer(void); // dessine le player a l'ecran

extern void init(char*); // initialisation generale du jeu (window + lib + gestion des erreurs via un fichier .txt)
extern void initMap(void); // initialisation du chargement du background de la map
extern void loadGame(void); // appel du chargement de notre map
extern void initPlayerSprites(void); // initialisation des sprites de player
extern void initPlayer(void); // initialisation du chargement du player
extern void updatePlayer(Input* input); // lié a l'update des animations du personnage
extern void mapCollider(GameSprite* entity); // gestion de limitation de terrain par rapport a la fenetre de jeu

extern int getX(void); // obtention des coo X et Y
extern int getY(void);
extern int getPlayerX(void); // fonction créer mais encore non utiliser, utile pour les differentes gestion d'item a ramasser ou autre collision complexe
extern int getPlayerY(void);

extern SDL_Renderer* getrenderer(void); // permet d'eviter la repetition de l'appel du renderer + gestion POO
extern SDL_Texture* getBackground(void); // permet d'eviter la repetition de l'appel de la texture + gestion POO
extern SDL_Texture* loadImage(char* name); // permet d'eviter la repetition de l'appel de la texture de l'image prechargé + gestion POO
extern GameSprite* getPlayer(void); // permet d'eviter la repetition de l'appel de la struct + gestion POO