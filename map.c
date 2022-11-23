#include "prototypes.h"


Map map;


SDL_Texture* getBackground(void)
{
	return map.background;
}

void initMap(void)
{
	map.background = loadImage("./include/image/background.png"); // charge le background depuis le dossier image 

	map.startX = 0;
	map.startY = 0;
}

void cleanMap(void) // pour libérer de l'espace
{
	if (map.background != NULL)
	{
		SDL_DestroyTexture(map.background);
		map.background = NULL;
	}
}


int getX(void) // obtention des coo de depart du player
{
	map.beginX = 25;
	return map.beginX;
}

int getY(void)
{
	map.beginY = 415;
	return map.beginY;
}


void mapCollider(GameSprite* entity)
{
	entity->onGround = 1; // consideration que le player est en l'air jusqu'a ce qu'il touche le sol

	entity->x += entity->dirX;
	entity->y += entity->dirY;

	if (entity->x < 25) // contrainte de deplacement par rapport aux limites de l'ecran
	{
		entity->x = 25;
	}

	else if (entity->x + entity->w >= WINDOW_WIDTH - 25) // si on touche la limite de la window, on recule le player sur l'axe x
	{
		entity->x = (WINDOW_WIDTH - 25) - entity->w - 1;
	}

	if (entity->y < 0) // contrainte de deplacement par rapport aux limites de l'ecran
	{
		entity->y = 0;
	}

	else if (entity->y + entity->h >= 415) // si on touche la limite y = 415, on recule le player sur l'axe y 
	{
		entity->y = 415 - entity->w - 1;
	}
}