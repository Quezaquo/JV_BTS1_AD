#include "prototypes.h"


GameSprite player; // rename de la structure 
SDL_Texture* playerTileSet;

GameSprite* getPlayer(void)
{
	return &player;
}


void initPlayer(void) // divers parametres pour initialiser le player au lancement
{
	player.direction = LOOK_RIGHT; // vers où va la player
	player.etat = IDLE; // animation idle (afk)

	player.frameNumber = 0; // indiquation pour choisir le premier sprite à choisir

	player.frameTimer = TIME_FRAMES_PLAYER; // temps entre chaque frame pour la vitesse de l'animation

	player.frameMax = 4; // nombre de frame max dans l'animation IDLE (ligne 0)

	player.x = getX(); // recupere les coo
	player.y = getY();

	player.w = PLAYER_WIDTH; // definition de la hauteur & largeur du player
	player.h = PLAYER_HEIGTH;

	player.onGround = 0; // gestion de collision avec le sol
}


int getPlayerX(void) // renvoie la coo x du player
{
	return player.x;
}

int getPlayerY(void) // renvoie la coo y du player
{
	return player.y;
}


void initPlayerSprites(void) // initialisation des sprites de player
{
	playerTileSet = loadImage("./include/image/playerTileSet1.png");
}


void cleanPlayer(void) // clean du player
{
	if (playerTileSet != NULL)
	{
		SDL_DestroyTexture(playerTileSet);
		playerTileSet = NULL;
	}
}

void drawPlayer(void) // dessine le player a l'ecran
{
	if (player.frameTimer <= 0) // si le compteur de frame arrive à zero on reset 
	{
		player.frameTimer = TIME_FRAMES_PLAYER;
		player.frameNumber++;

		if (player.frameNumber >= player.frameMax) // si atteint la frame max, deja defini, alors on reset au debut
		{
			player.frameNumber = 0;
		}
	}
	else
	{
		player.frameTimer--;
	}

	SDL_Rect playerDest; // rectangle a dessiner 
	SDL_Rect playerSrc; // rectangle de la frame source

	playerDest.x = player.x; // affectation des coo a l'endroit ou le rect sera dessiner
	playerDest.y = player.y;
	playerDest.w = player.w;
	playerDest.h = player.h;

	playerSrc.x = player.frameNumber * player.w; // on recupere la largeur du sprite multiplie par le numero de la frame à afficher et donc obtenir la bonne image
	playerSrc.w = player.w;
	playerSrc.h = player.h;
	playerSrc.y = player.etat * player.h; // on recupere la bonne ligne de frame à dessiner grace aux definition dans le defs.h

	if (player.direction == LOOK_LEFT) // si le player regarde a gauche, on doit inverser le sens de l'animation grace au flip
		SDL_RenderCopyEx(getrenderer(), playerTileSet, &playerSrc, &playerDest, 0, 0, SDL_FLIP_HORIZONTAL); // on flip sur l'axe horizontal (x)
	else
		SDL_RenderCopyEx(getrenderer(), playerTileSet, &playerSrc, &playerDest, 0, 0, SDL_FLIP_NONE); // on ne flip pas car il regarde deja dans la bonne direction de l'animation
}

void updatePlayer(Input* input)
{

	player.dirX = 0;
	player.dirY += GRAVITY_SPEED; // initialisaiton de la gravite sur le player

	if (player.dirY >= MAX_FALL_SPEED) // blocage de la vitesse de chute à MAX_FALL_SPEED
		player.dirY = MAX_FALL_SPEED;

	if (input->left == 1) // si on detecte un appui sur la touche q
	{
		player.dirX -= PLAYER_SPEED;
		player.direction = LOOK_LEFT; // changement de sens donc du flip

		if (player.etat != WALK && player.onGround == 1) // si l'animation précedente n'etait WALK on l'initialise à la frame 0 du tile set
		{
			player.etat = WALK;
			player.frameNumber = 0;
			player.frameTimer = TIME_FRAMES_PLAYER;
			player.frameMax = 6;
		}
	}

	else if (input->right == 1) // si on detecte un appui sur la touche d
	{
		player.dirX += PLAYER_SPEED;
		player.direction = LOOK_RIGHT; // changement de sens donc du flip

		if (player.etat != WALK && player.onGround == 1) // si l'animation précedente n'etait WALK on l'initialise à la frame 0 du tile set
		{
			player.etat = WALK;
			player.frameNumber = 0;
			player.frameTimer = TIME_FRAMES_PLAYER;
			player.frameMax = 6;
		}
	}

	else if (input->right == 0 && input->left == 0 && player.onGround == 1) // si on ne dectecte aucun appui alors IDLE
	{
		if (player.etat != IDLE) // on test si l'animation IDLE n'est pas deja lancer sinon on l'initialise
		{
			player.etat = IDLE;
			player.frameNumber = 0;
			player.frameTimer = TIME_FRAMES_PLAYER;
			player.frameMax = 4;
		}
	}

	if (input->jump == 1) // si on appui sur la barre espace alors on joue l'animation et on met directement l'etat de la barre espace à 0
	{
		if (player.onGround == 1)
		{
			player.dirY = -JUMP_HEIGHT;
			player.onGround = 0;
			player.jump = 1;
			input->jump = 0;
		}
	}

	if (player.onGround == 0) // si le joueur saute il ne sera donc plus sur le sol donc on peut jouer l'animation 
	{
		if (player.jump == 1) // test de la valeur du saut pour generer l'animation
		{
			if (player.etat != JUMP)
			{
				player.etat = JUMP;
				player.frameNumber = 0;
				player.frameTimer = TIME_FRAMES_PLAYER;
				player.frameMax = 2;
			}
		}
	}

	mapCollider(&player); // on gere la collision avec la fenetre 

}