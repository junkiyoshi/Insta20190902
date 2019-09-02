#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto radius = 300;
	auto noise_step = 0.001;

	for (auto deg = 0; deg < 360; deg += 1) {

		vector<glm::vec3> vertices;

		// point 1

		auto location = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 0);
		auto noise_seed_x = location.x * 0.001;
		auto noise_seed_y = location.y * 0.001;
		auto noise_seed_z = location.z;

		auto angle_x = ofMap(ofNoise(noise_seed_x, ofGetFrameNum() * noise_step), 0, 1, -PI * 2, PI * 2);
		auto angle_y = ofMap(ofNoise(noise_seed_y, ofGetFrameNum() * noise_step), 0, 1, -PI * 2, PI * 2);
		auto angle_z = ofMap(ofNoise(noise_seed_z, ofGetFrameNum() * noise_step), 0, 1, -PI * 2, PI * 2);

		auto rotation_x = glm::rotate(glm::mat4(), angle_x, glm::vec3(1, 0, 0));
		auto rotation_y = glm::rotate(glm::mat4(), angle_y, glm::vec3(0, 1, 0));
		auto rotation_z = glm::rotate(glm::mat4(), angle_z, glm::vec3(0, 0, 1));
		location = glm::vec4(location, 0) * rotation_z * rotation_y * rotation_x;

		vertices.push_back(location);

		// point 2

		location = glm::vec3(radius * cos((deg + 1) * DEG_TO_RAD), radius * sin((deg + 1) * DEG_TO_RAD), 0);
		noise_seed_x = location.x * 0.001;
		noise_seed_y = location.y * 0.001;
		noise_seed_z = location.z;

		angle_x = ofMap(ofNoise(noise_seed_x, ofGetFrameNum() * noise_step), 0, 1, -PI * 2, PI * 2);
		angle_y = ofMap(ofNoise(noise_seed_y, ofGetFrameNum() * noise_step), 0, 1, -PI * 2, PI * 2);
		angle_z = ofMap(ofNoise(noise_seed_z, ofGetFrameNum() * noise_step), 0, 1, -PI * 2, PI * 2);

		rotation_x = glm::rotate(glm::mat4(), angle_x, glm::vec3(1, 0, 0));
		rotation_y = glm::rotate(glm::mat4(), angle_y, glm::vec3(0, 1, 0));
		rotation_z = glm::rotate(glm::mat4(), angle_z, glm::vec3(0, 0, 1));
		location = glm::vec4(location, 0) * rotation_z * rotation_y * rotation_x;

		vertices.push_back(location);

		// point 3

		location = glm::vec3(radius * cos((deg + 1) *DEG_TO_RAD), radius * sin((deg + 1) * DEG_TO_RAD), 0);
		noise_seed_x = location.x * 0.001;
		noise_seed_y = location.y * 0.001;
		noise_seed_z = location.z;

		angle_x = ofMap(ofNoise(noise_seed_x, (ofGetFrameNum() + 8) * noise_step), 0, 1, -PI * 2, PI * 2);
		angle_y = ofMap(ofNoise(noise_seed_y, (ofGetFrameNum() + 8) * noise_step), 0, 1, -PI * 2, PI * 2);
		angle_z = ofMap(ofNoise(noise_seed_z, (ofGetFrameNum() + 8) * noise_step), 0, 1, -PI * 2, PI * 2);

		rotation_x = glm::rotate(glm::mat4(), angle_x, glm::vec3(1, 0, 0));
		rotation_y = glm::rotate(glm::mat4(), angle_y, glm::vec3(0, 1, 0));
		rotation_z = glm::rotate(glm::mat4(), angle_z, glm::vec3(0, 0, 1));
		location = glm::vec4(location, 0) * rotation_z * rotation_y * rotation_x;

		vertices.push_back(location);
		
		// point 4

		location = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 0);
		noise_seed_x = location.x * 0.001;
		noise_seed_y = location.y * 0.001;
		noise_seed_z = location.z;

		angle_x = ofMap(ofNoise(noise_seed_x, (ofGetFrameNum() + 8) * noise_step), 0, 1, -PI * 2, PI * 2);
		angle_y = ofMap(ofNoise(noise_seed_y, (ofGetFrameNum() + 8) * noise_step), 0, 1, -PI * 2, PI * 2);
		angle_z = ofMap(ofNoise(noise_seed_z, (ofGetFrameNum() + 8) * noise_step), 0, 1, -PI * 2, PI * 2);

		rotation_x = glm::rotate(glm::mat4(), angle_x, glm::vec3(1, 0, 0));
		rotation_y = glm::rotate(glm::mat4(), angle_y, glm::vec3(0, 1, 0));
		rotation_z = glm::rotate(glm::mat4(), angle_z, glm::vec3(0, 0, 1));
		location = glm::vec4(location, 0) * rotation_z * rotation_y * rotation_x;

		vertices.push_back(location);


		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}