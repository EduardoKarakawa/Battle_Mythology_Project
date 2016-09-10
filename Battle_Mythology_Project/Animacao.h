#pragma once
#pragma managed
#include "ofApp.h"


ref class ConsoleHelper
{
public:
	void Animation(PlayerType *ply, KeyInput *tecla) {
		//Funcao que controla o load dos sprites do player, conforme a Acao e Direcao, alem de mudar os frames.

		if (ply->FPS >= 10) {	//ply tem uma var que conta os fps, aki se ela for menor igual a 10
			ply->FPS = 0;		//ela eh zerada e a variavel frame soma 1.
			ply->Frame++;
		}
		if (ply->Frame > 3) {	//aki ocorre o mesmo que com o fps, mas com os frames, quando Frame passar de 3
			ply->Frame = 0;		//o Frame eh zerado.
		}

		//Aki eh onde sera juntado a variavel Acao, Direcao e Frame, para poder carregar os frames de acordo com o 
		//o jogador esta fazendo.
		char anim[50];	//tudo sera juntado nessa variavel
		snprintf(anim, sizeof(anim), "players/%s/%d/%d.png", ply->Acao, ply->Direcao, 0); //juntando tudo
		std::cout << anim;
		ply->Sprite.loadImage(anim);
	}
}