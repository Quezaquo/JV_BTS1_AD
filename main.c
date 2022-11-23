#include "prototypes.h" // pour inclure toutes les libs, proto, struct, etc..

Input input;


int main(int argc, char* argv[])
{
	int run;

	init("The Game : Python for the future"); // initialisation de la fenetre de jeu

	loadGame(); // on va charger notre jeu
	initPlayer(); // puis on init le player

	run = 1;

	while (run == 1) // on fait tourner le jeu en boucle
	{
		gestionInputs(&input); // gestion input clavier

		updatePlayer(&input); // appel de l'update du joueur 

		drawGame();
	}

	cleanup(); // appelle de fonction pour supprim� les donn�es

	system("pause");
	return 0;
}


// ============================================================================================


void gestionInputs(Input* input)
{
	getInput(input);
}

void getInput(Input* input)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

		case SDL_QUIT:
			exit(0);
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				exit(0);
				break;

			case SDLK_SPACE: // barre espace
				input->jump = 1;
				break;

			case SDLK_a: // touche a pour attaquer
				input->attack = 1;
				break;

			case SDLK_q: // touche q pour aller a gauche
				input->left = 1;
				break;

			case SDLK_d: // touche d pour aller a droite
				input->right = 1;
				break;

			default:
				break;
			}
			break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_SPACE:
				input->jump = 0;
				break;

			case SDLK_q:
				input->left = 0;
				break;

			case SDLK_d:
				input->right = 0;
				break;

			default:
				break;
			}
			break;
		}
	}
}