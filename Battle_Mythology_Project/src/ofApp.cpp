#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//Definindo posição do mundo
	Mundo.x = 0;
	Mundo.y = 0;


	//Inicializando o terreno
	terreno.sprite.loadImage("cenario/terreno.png");
	terreno.pos.x = Mundo.x;
	terreno.pos.y = Mundo.y;


	//Iniciando a decoração Pilar
	decPilar.sprite.loadImage("cenario/pilar.png");
	decPilar.pos.x = 500;
	decPilar.pos.y = 500;
	decPilar.pivo = 260;


	
	//Iniciando o Player
	player.Frame = 0;
	player.posicao.x = 640;
	player.posicao.y = 360;


	
}


//--------------------------------------------------------------
void ofApp::update(){

	


	//Verifica a direção para onde o player esta andando
	SeeDirection(&player, &keys);
	
	//Verifica a ação que o player vai fazer
	SeeAction(&player, &keys);

	//Verificando se o player esta colidindo com algo
	ColisaoPlayer(&player, &decPilar, &Mundo, &keys);
	
	//Movimenta o player
	MovPlayer(&player, &keys, &Mundo);




	std::cout << "Player x " << player.posicao.x << " y " << player.posicao.y << "VelX " << player.VelX << " y " << player.VelY << std::endl;
}



//--------------------------------------------------------------
void ofApp::draw(){
	player.FPS++;

	//Muda os frames e as animações
	Animation(&player, &keys);

	//Desenhando o terreno
	terreno.sprite.draw(Mundo.x, Mundo.y);

	//Desenhando o player
	player.Sprite.draw(640 - (player.Sprite.getWidth() / 2), 360 - (player.Sprite.getHeight() / 2));


	//Desenhando Pilar
	decPilar.sprite.draw(Mundo.x + decPilar.pos.x - (decPilar.sprite.getWidth() / 2), Mundo.y + decPilar.pos.y - decPilar.pivo);

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
