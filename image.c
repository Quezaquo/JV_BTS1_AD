#include "prototypes.h"


SDL_Texture* loadImage(char* name)
{
    SDL_Surface* loadedImage = NULL;
    SDL_Texture* texture = NULL;
    loadedImage = IMG_Load(name);

    if (loadedImage != NULL) // si l'image a pu etre charge
    {
        texture = SDL_CreateTextureFromSurface(getrenderer(), loadedImage);

        SDL_FreeSurface(loadedImage); // on libere l'espace
        loadedImage = NULL; // on remet la valeur de loadedImage a NULL pour eviter une sur-recharge
    }
    else
        printf("L'image n'a pas pu être chargée! SDL_Error : %s\n", SDL_GetError());
    fprintf(stdout, "Message d’erreur (%s) (avec le chargement de l'image)\n", SDL_GetError()); // ecrit le message d'erreur dans un fichier txt externe

    return texture;

}


void drawGame(void)
{
    drawOneImage(getBackground(), 0, 0); // appel de la fonction pour afficher le bg aux coo 0 0
    drawPlayer(); // appel de la fonction pour afficher le player
    SDL_RenderPresent(getrenderer()); // appel du renderer pour le refresh et donc afficher
    SDL_Delay(5); // pause sinon mon proc va dead

}


void drawOneImage(SDL_Texture* image, int x, int y)
{
    SDL_Rect dest;

    dest.x = x; // taille du rect a afficher 
    dest.y = y;

    SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h); // on interroge les attributs de la texture
    SDL_RenderCopy(getrenderer(), image, NULL, &dest); // on le copie a l'ecran
}