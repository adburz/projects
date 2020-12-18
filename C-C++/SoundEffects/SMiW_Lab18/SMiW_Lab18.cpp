#include <iostream> 
#include <string> 
#include <fstream> 
#include <vector> 
#include <stdio.h>
const std::string INPUT_PATH = "E:\\OneDrive\\OneDrive - Politechnika Œl¹ska\\STUDIA\\SEM 5\\SMiW-laby\\temat18\\Sound.raw";
const std::string OUTPUT_PATH = "E:\\OneDrive\\OneDrive - Politechnika Œl¹ska\\STUDIA\\SEM 5\\SMiW-laby\\temat18\\outSound.raw";

const int SOUND_BREAK = 44100; //const value used to set break in sound 
const int SILENCE_VOLUME = 0; //volume used to end infinity echo 
const int TRIPPLE_ECHO = 3;
int i = 0;
std::vector<short int> sound; //vector containing sound

//Task 1 
//Adding echo effect to the sound file. 
std::vector<short int> firstTask() {
	std::vector<short int> editedSound;
	for (short int tmp : sound) { //copying original sound into edited one 
		editedSound.push_back(tmp);
	}
	for (int i = 0; i < SOUND_BREAK; i++) { //adding sound break 
		editedSound.push_back(0);
	} for (short int tmp : sound) { //adding echo, so adding additional original sound 
		editedSound.push_back(tmp);
	}
	return editedSound; //returns edited sound 
}


//Task 2 
//Adding tripple echo effect. 
std::vector<short int> secondTask() {
	std::vector<short int> editedSound;
	for (short int tmp : sound) { // copying original sound 
		editedSound.push_back(tmp);
	}
	for (int n = 0; n < TRIPPLE_ECHO; n++) { //tripple called for loop, for tripple echo 
		for (int i = 0; i < SOUND_BREAK; i++) { //adding sound break
			editedSound.push_back(0);
		} for (short int sample : sound) { // adding echo, so adding additional original sound 
			editedSound.push_back(sample);
		}
	} return editedSound; //returns edited sound 
}


//Task 3 
//Adding a blanking infinity echo
//function used to cound average sound value 
short int averageVolume()
{
	int sum = 0;
	for (short int tmp : sound)
	{
		sum += abs(tmp);
	} return sum / sound.size();
}
std::vector<short int> thirdTask() {
	std::vector<short int> editedSound; for (short int tmp : sound)
	{ // copying original sound 
		editedSound.push_back(tmp);
	}
	while (abs(averageVolume()) > SILENCE_VOLUME) { //adding a blanking echo
		for (int i = 0; i < SOUND_BREAK; i++) {//adding sound break 
			editedSound.push_back(0);
		}
		for (int i = 0; i < sound.size(); i++) { //adding echo sound[i] = sound[i] / 2; editedSound.push_back(sound[i]); 
		}
	}
	return editedSound;
}

//Free function
std::vector<short int> reverseEcho() {

	std::vector<short int> editedSound;

	for (short int tmp : sound) { //adding echo, so adding additional original sound
		editedSound.push_back(tmp);
	}

	for (int i = 0; i < SOUND_BREAK; i++) { //adding sound break
		editedSound.push_back(0);
	}

	for (std::vector<short int>::reverse_iterator iter = sound.rbegin(); iter != sound.rend(); iter++) {
		editedSound.push_back(*iter);
	}

	return editedSound;	//returns edited sound
}

int main() {
	std::ifstream input; input.open(INPUT_PATH, std::ios::binary);
	std::ofstream output; output.open(OUTPUT_PATH, std::ios::binary); short int singleSample;
	//reading .raw file, and loading it into sound vector 
	while (input.read(reinterpret_cast<char*>(&singleSample), sizeof(short int))) 
	{ 
		sound.push_back(singleSample); 
	}
	//sound = firstTask();
	//sound = secondTask(); 
	sound = thirdTask();
	for (short int sample : sound) // saving edited sound to file 
	{ 
		output.write(reinterpret_cast<char*>(&sample), sizeof(short int)); 
	} 
	input.close(); 
	output.close(); 
}