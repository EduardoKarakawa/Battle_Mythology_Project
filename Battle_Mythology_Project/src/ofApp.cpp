#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//Pegando o tempo de execução do jogo
	before = ofGetElapsedTimef();


	//Definindo posição do mundo
	Mundo.x = 640 - 520;
	Mundo.y = -1055+360;


	//Inicializando o terreno
	terreno.sprite.loadImage("cenario/terrain.png");
	terreno.pos.x = Mundo.x;
	terreno.pos.y = Mundo.y;


	//Inicializando as decorações
	//------Dec Barreira primeiro plano--------
	decoracao[0].sprite.loadImage("cenario/dec_01.png");
	decoracao[0].pivo = decoracao[0].sprite.getHeight() / 2;
	decoracao[0].pos.x = Mundo.x + terreno.sprite.getWidth() / 2 - decoracao[0].sprite.getWidth() / 2 - 30;
	decoracao[0].pos.y = Mundo.y + 618 - decoracao[0].pivo;


	//Inicializando pontos de colisao
	IniciaParedes(&paredes[0],  0, 953, 355, 246);
	paredes[0].teste.loadImage("cenario/terreno.png");
	paredes[0].teste.resize(355, 246);
	/*IniciaParedes(&paredes[1], Mundo.x + 686, Mundo.y + 953, 355, 246);
	IniciaParedes(&paredes[2], Mundo.x + 321, Mundo.y + 1172, 400, 64);
	IniciaParedes(&paredes[3], Mundo.x + 99, Mundo.y + 765, 355, 216);
	IniciaParedes(&paredes[4], Mundo.x + 587, Mundo.y + 765, 355, 216);
	IniciaParedes(&paredes[5], Mundo.x + 0, Mundo.y + 629, 407, 188);
	IniciaParedes(&paredes[6], Mundo.x + 643, Mundo.y + 629, 398, 188);
	IniciaParedes(&paredes[7], Mundo.x + 0, 0, Mundo.y + 178, 678);*/

	//Iniciando o Player
	player.velocidadeAnimacao = 0.5f;
	player.posicao.x = Mundo.x + 520;
	player.posicao.y = Mundo.y + 1055;
	player.altura = 76;
	player.largura = 76;
	player.indexY = 3;	//Indica posição em Y do frame que sera exibido
	player.indexX = 0;	//Indica posição em X do frame que sera exibido
	
}


//--------------------------------------------------------------
void ofApp::update() {
	//Calculando o tempo de troca de frame
	gameTime = ofGetElapsedTimef() - before;
	before = ofGetElapsedTimef();

	player.frameTime += gameTime;

	//if (player.frameTime >= player.velocidadeAnimacao) {
	//	MudaFrame(&player);
	//}

	//Verificando colizao
	ColisaoPlayer(&player, &paredes[0], &Mundo, &keys);
	/*ColisaoPlayer(&player, &paredes[1], &Mundo);
	ColisaoPlayer(&player, &paredes[2], &Mundo);
	ColisaoPlayer(&player, &paredes[3], &Mundo);
	ColisaoPlayer(&player, &paredes[4], &Mundo);
	ColisaoPlayer(&player, &paredes[5], &Mundo);
	ColisaoPlayer(&player, &paredes[6], &Mundo);
	ColisaoPlayer(&player, &paredes[7], &Mundo);*/

	//Verifica a direção para onde o player esta andando
	SeeDirection(&player, &keys);

	//Verifica a ação que o player vai fazer
	SeeAction(&player, &keys);

	//Movimenta o player
	MovPlayer(&player, &keys, &Mundo, gameTime);




	std::cout	<< "Player x " << player.posicao.x << " y " << player.posicao.y << " VelX " << player.VelX << " VelY " << player.VelY
				<< " Time " << gameTime << " Before " << before << std::endl;
}


//--------------------------------------------------------------
void ofApp::draw(){

	//Desenhando o terreno
	terreno.sprite.draw(Mundo.x, Mundo.y);

	//Desenhando a decoração
	decoracao[0].sprite.draw(Mundo.x + terreno.sprite.getWidth() / 2 - decoracao[0].sprite.getWidth()/2 - 30, Mundo.y + 618 - decoracao[0].pivo);

	//Desenhando o player
	//Muda os frames e as animações
	DesenhaAnimation(&player, &keys);

	paredes[0].teste.draw(paredes[0].pos.x + Mundo.x, paredes[0].pos.y + Mundo.y);

	std::cout << " XX " << paredes[0].pos.x + Mundo.x << " YY " << paredes[0].pos.y + Mundo.y;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

//Verifica as teclas que estao sendo precionada, a variavel key eh reponsavel por
//armazenar essas teclas.
	if ((key == OF_KEY_UP) && (!keys.Up_Disable)){
		keys.Up = true;
	}
	if ((key == OF_KEY_DOWN) && (!keys.Down_Disable)){
		keys.Down = true;
	}
	if ((key == OF_KEY_LEFT) && (!keys.Left_Disable)){
		keys.Left = true;
	}
	if ((key == OF_KEY_RIGHT) && (!keys.Right_Disable)){
		keys.Right = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

//Verifica as teclas que foram soltas
	if (key == OF_KEY_UP) {
		keys.Up = false;
	}
	if (key == OF_KEY_DOWN) {
		keys.Down = false;
	}
	if (key == OF_KEY_LEFT) {
		keys.Left = false;
	}
	if (key == OF_KEY_RIGHT) {
		keys.Right = false;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
