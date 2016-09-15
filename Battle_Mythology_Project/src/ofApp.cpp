#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	Mundo.x = 0;
	Mundo.y = 0;

	


	terreno.sprite.loadImage("cenario/teste.jpg");
	terreno.pos.x = terreno.sprite.getWidth()/2 - Mundo.x;
	terreno.pos.y = terreno.sprite.getHeight() /2 - Mundo.y;

	decPilar.sprite.loadImage("cenario/pilar.png");
	decPilar.pos.x = 1041;
	decPilar.pos.y = 775;
	

	player.Frame = 0;
	player.Vivo = false;
	player.posicao.x = Mundo.x + terreno.pos.x + 200;
	player.posicao.y = Mundo.y + terreno.pos.y + 200;

}//1512 783
//1988 963

//--------------------------------------------------------------
void ofApp::update(){
	keys.mov = true;
	
	RefreshWorld(&terreno, 0, 0);
	RefreshWorld(&decPilar, 1850, 854);

	std::cout << ofGetUnixTime() << "||";

	SeeDirection(&player, &keys);
	SeeAction(&player, &keys);
	keys.mov = Collision(&player, &terreno, Mundo);
	
	std::cout << "MOV" << keys.mov << "||";

	MovPlayer(&player, &keys, &Mundo);

	std::cout << Mundo.x << "," << Mundo.y << "||" << decPilar.pos.x << "," << decPilar.pos.y;
	std::cout << "||" << terreno.sprite.getWidth() << std::endl;
}



//--------------------------------------------------------------
void ofApp::draw(){
	player.FPS++;

	Animation(&player, &keys);

	terreno.sprite.draw(terreno.pos.x, terreno.pos.y);
	player.Sprite.draw(player.posicao.x, player.posicao.y);
	decPilar.sprite.draw(decPilar.pos.x, decPilar.pos.y);
	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

//Verifica as teclas que estao sendo precionada, a variavel key eh reponsavel por
//armazenar essas teclas.
	if (key == ' ') {
		player.Vivo = true;
	}
	if ((key == OF_KEY_UP) && keys.mov) {
		keys.Up = true;
	}
	if ((key == OF_KEY_DOWN) && keys.mov) {
		keys.Down = true;
	}
	if ((key == OF_KEY_LEFT) && keys.mov) {
		keys.Left = true;
	}
	if ((key == OF_KEY_RIGHT) && keys.mov) {
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
