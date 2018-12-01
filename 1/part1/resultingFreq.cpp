#include<iostream>
#include<string>
/**
	Program that reads changes of frequency from stdin that can be:
		+x
	or	-x
	where the first character of a line is the operator (+ or -),
	and the rest of the line is an integer to increment the frequency
	by.

	Outputs the resulting frequency at the end of the input.
*/
int main(void){
	int frequency = 0;
	std::string line;
	char op;
	int lineValue;

	while(!std::cin.eof()){
		// Read lines while there is input
		getline(std::cin, line);

		// Parsing the line
		op = line.at(0);
		line.erase(0,1);
		lineValue = std::stoi(line);
		// Incrementing frequency based on the operator
		switch(op){
			case '+':
				frequency += lineValue;
				break;
			case '-':
				frequency -= lineValue;
				break;
		}
	}
	// Output the final frequency
	std::cout << frequency << std::endl;
	return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> b71be9aeb8d903931db61bd2c86705e23ca644d0
