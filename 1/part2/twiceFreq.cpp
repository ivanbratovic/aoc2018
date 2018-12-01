#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
/**
	Program that reads changes of frequency from stdin that can be:
		+x
	or	-x
	where the first character of a line is the operator (+ or -),
	and the rest of the line is an integer to increment the frequency
	by.
	
	Loops the inpt until a given frequency has already appeared.
	Outputs the frequency that was the first to be reached twice.
*/
int main(void){
	int frequency = 0;
	std::string line;
	char op;
	int i;
	int lineValue;
	// vector to hold all reached frequencies, with initial member 0
	std::vector<int> reachedFreq = {0};
	// Vector to hold all the steps, so the input must only be read once
	std::vector<int> steps;
	// Integer value that counts the number of lines in the input.
	int maxLoops;


	// Generating the steps vector
	while(!std::cin.eof()){
		// Read lines while there is input
		getline(std::cin, line);

		// Parsing the line
		op = line.at(0);
		line.erase(0,1);
		lineValue = std::stoi(line);
		// Adding lineValue into steps based on the operator
		switch(op){
			case '+':
				steps.push_back(lineValue);
				break;
			case '-':
				steps.push_back(-lineValue);
				break;
		}
	}
	maxLoops = steps.size();
	i = 0;
	while(true){
		frequency += steps.at(i%maxLoops);
		i++;
		// Checking if the frequency was reached before
		if(std::find(reachedFreq.begin(), reachedFreq.end(), frequency) != reachedFreq.end()){
			// The vector reachedFreq contains the current frequency
			// We're done, print it and exit.
			std::cout << frequency << std::endl;
			break;
		} else {
			// Our vector doesn't contain the current frequency.
			// Add the frequency to the vector and keep calculating.
			reachedFreq.push_back(frequency);
		}
	}
	return 0;
}