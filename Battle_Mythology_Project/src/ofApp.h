#pragma once

#include "ofMain.h"
#include <string>

#define MAXSPEED 10
#define PLAYERATRITO 0.1f
#define PLAYERSPEED 1.f

struct PlayerType {
	ofImage Sprite;
	ofPoint posicao;
	int Vida;
	int Direcao = 1;
	char Acao[9] = "idle";
	int Frame, FPS;
	float VelX, VelY;
	bool Vivo;
};

struct KeyInput {
	bool mov = true;
	bool Up_Disable = false;
	bool Up = false;
	bool Down_Disable = false;
	bool Down = false;
	bool Left_Disable = false;
	bool Left = false;
	bool Right_Disable = false;
	bool Right = false;
};

struct BackgroundType {
	ofPoint pos;
	ofImage sprite;
	int pivo;
};



class ofApp : public ofBaseApp{

	ofPoint Mundo;
	BackgroundType terreno;
	BackgroundType decPilar;
	KeyInput keys;
	PlayerType player;
	
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		

		void SeeDirection(PlayerType *ply, KeyInput *tecla) {
		// Funcao para verificar se para qual direcao o player esta indo:
			/*				  	
						   2   3   4	 
							\  |  /
						1 --- key --- 5
						    /  |  \
						   8   7   6
			*/


			int aux = ply->Direcao;	//salva a direcao anterior, para continuar na mesma posicao se nao tiver apertado nada.
			ply->Direcao = 0;		//zera a direcao para iniciar uma nova contagem

			if (tecla->Left) {
				ply->Direcao = 1;
			}
			if (tecla->Up) {
				ply->Direcao = 3;
			}
			if (tecla->Right) {
				ply->Direcao = 5;
			}
			if (tecla->Down) {
				ply->Direcao = 7;
			}
			if (tecla->Left && tecla->Up) {
				ply->Direcao = 2;
			}
			if (tecla->Right && tecla->Up) {
				ply->Direcao = 4;
			}
			if (tecla->Right && tecla->Down) {
				ply->Direcao = 6;
			}
			if (tecla->Left && tecla->Down) {
				ply->Direcao = 8;
			}
			if ((ply->Direcao == 0) || (ply->Direcao > 11)) {	//Se nenhuma tecla tiver sido precionada ou a soma das teclas 
				ply->Direcao = aux;								//for maior que 11, ply->Direcao recebe a direcao anterior.
			}
		}


		void SeeAction(PlayerType *ply, KeyInput *tecla) {
		//Funcao para gerenciar as acoes do player:
		//andando, ataque1, ataque2, ataque3, levadano, dash

			//se alguma das setas do teclado tiver precionada, sera atribuido "andando"
			//na variavel ply->Acao.
			if (tecla->Down || tecla->Up || tecla->Left || tecla->Right) {
				strcpy_s(ply->Acao, "andando");
			}
			if (!tecla->Down && !tecla->Up && !tecla->Left && !tecla->Right) {
				strcpy_s(ply->Acao, "idle");
			}

			//colocar acoes novas aki:

		}


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
			snprintf(anim, sizeof(anim), "players/%s/%d/%d.png", ply->Acao,ply->Direcao, 0); //juntando tudo
			ply->Sprite.loadImage(anim);
		}
		

		void SpeedPlayer(PlayerType *ply, KeyInput *tecla) {
		//Funcao que incrementa a velocidade do player gradualmente
			if (ply->VelX < MAXSPEED && tecla->Right) {
				ply->VelX+= PLAYERSPEED;
			}
			if (ply->VelX > -MAXSPEED && tecla->Left) {
				ply->VelX -= PLAYERSPEED;
			}
			if (ply->VelY > -MAXSPEED && tecla->Up) {
				ply->VelY -= PLAYERSPEED;
			}
			if (ply->VelY < MAXSPEED && tecla->Down) {
				ply->VelY += PLAYERSPEED;
			}
		}


		void MovPlayer(PlayerType *ply, KeyInput *tecla, ofPoint *mnd) {

			//Atualiza da velocidade que do player
			SpeedPlayer(ply, tecla);

			//Subtrai a velocidade de Mundo para o mundo ser desenhado no lugar certo
				mnd->x -= ply->VelX;
				mnd->y -= ply->VelY;
			//Soma na posição do player para ele andar no mundo
				ply->posicao.x += ply->VelX;
				ply->posicao.y += ply->VelY;
			//Reduz a velocidade gradualmente do player quando ele nao estiver andando
				if (ply->Acao == "idle");
					DecreVelo(ply);
		}


		void DecreVelo(PlayerType *ply) {
			//Função de atrito do personagem, ela faz o personagem ir reduzindo de velocidade gradualmente quando estiver parando de andar
			if (ply->VelX > 0) {
				ply->VelX -= PLAYERATRITO;
				if (ply->VelX < 0) {
					ply->VelX = 0;
				}
			}
			if (ply->VelX < 0) {
				ply->VelX += PLAYERATRITO;
				if (ply->VelX > 0) {
					ply->VelX = 0;
				}
			}
			if (ply->VelY > 0) {
				ply->VelY -= PLAYERATRITO;
				if (ply->VelY < 0) {
					ply->VelY = 0;
				}
			}
			if (ply->VelY < 0) {
				ply->VelY += PLAYERATRITO;
				if (ply->VelY > 0) {
					ply->VelY = 0;
				}
			}
		}


		void ColisaoPlayer(PlayerType *ply, BackgroundType *obstaculo, ofPoint *mnd, KeyInput *tecla) {

			//Calcula a distancia entre os dois objetos
			float distancia = obstaculo->sprite.getWidth() / 2 + ply->Sprite.getWidth() / 2;

			//Verifica se o player esta encostando ou embaixo do objeto
			if (obstaculo->pos.distance(ply->posicao) < distancia) {
				
				/*Desabilida os inputs de direção para impedir o que o jogador ande para baixo do
				objeto, mas deixa liberado as teclas que tirao ele de baixo do objeto*/
				if (obstaculo->pos.x < ply->posicao.x) {
					if(ply->VelX < 0)
						ply->VelX = 0;
					tecla->Left_Disable = true;
					tecla->Left = false;
				}

				if (obstaculo->pos.x > ply->posicao.x) {
					if (ply->VelX > 0)
						ply->VelX = 0;
					tecla->Right_Disable = true;
					tecla->Right = false;
				}

				if (obstaculo->pos.y < ply->posicao.y) {
					if (ply->VelY < 0)
						ply->VelY = 0;
					tecla->Up_Disable = true;
					tecla->Up = false;
				}

				if (obstaculo->pos.y > ply->posicao.y) {
					if (ply->VelY > 0)
						ply->VelY = 0;
					tecla->Down_Disable = true;
					tecla->Down = false;
				}
			}


			/*Caso o player não estaja encostando em nada, nenhuma tecla de movimentação é travada*/
			else {
				tecla->Up_Disable = false;
				tecla->Down_Disable = false;
				tecla->Left_Disable = false;
				tecla->Right_Disable = false;
			}
		}

};
