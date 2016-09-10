#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	player.Frame = 0;
	player.Vivo = false;

	//player.Sprite.loadImage("players/Johanna_Reference.png");

}

//--------------------------------------------------------------
void ofApp::update(){
		SeeDirection(&player, &keys);
		SeeAction(&player, &keys);
		//sdrwasda
}

//--------------------------------------------------------------
void ofApp::draw(){
	player.FPS++;

	Animation(&player, &keys);

	player.Sprite.draw(500, 500);
	//	.drawSubsection(posX, posY, tamanhoX, TamanhoY, LocalDaSpriteX, LocalDaSpriteY);
	//player.Sprite.drawSubsection(0, 0, 100, 100, mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		player.Vivo = true;
	}
	if (key == OF_KEY_UP) {
		keys.Up = true;
	}
	if (key == OF_KEY_DOWN) {
		keys.Down = true;
	}
	if (key == OF_KEY_LEFT) {
		keys.Left = true;
	}
	if (key == OF_KEY_RIGHT) {
		keys.Right = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
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
