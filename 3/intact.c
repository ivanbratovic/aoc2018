#include<stdio.h>
#include<malloc.h>

// Function declarations
unsigned countOverlap(unsigned*, int);
void printField(unsigned*, int);

// Defined a struct for a claim
typedef struct {
	unsigned id, posX, posY, lenX, lenY;
} claim;

int main(void){
	//// DATA STRUCTURES:
	// The field representing the fabric
	unsigned *field;
	// Numbers limiting the size of the fabric, and the number of claims
	unsigned fieldSize, claimNo;
	// Claim elements
	unsigned id, posX, posY, lenX, lenY;
	// Array to store potential intact claims
	claim* intactPotential;

	// Reading the limits from the modified input file
	scanf("%u %u\n", &fieldSize);
	// Allocating the memory, given the limits
	field = (unsigned*) malloc(sizeof(unsigned) * fieldSize * fieldSize);
	intactPotential = (claim*) malloc(sizeof(claim) * claimNo);
	// Pointer to the topmost free claim in the intactPotential array
	claim* topmostClaim = intactPotential;

	// Read input from stdin
	while(scanf("#%u @ %u,%u: %ux%u\n", &id, &posX, &posY, &lenX, &lenY) != EOF){
		// Logical variable that turns false if the read claim is definitely not intact
		bool intact = true;
		// Ye olde for loop to put the claim in the field
		for (int i = posX; i < posX+lenX; ++i){
			for (int j = posY; j < posY+lenY; ++j){
				// Deciding what to put in the cell [i][j]
				if(*(field+j*fieldSize+i) == 0){
					// Put the id in a free cell
					*(field+j*fieldSize+i) = id;
				} else {
					// Put 9999 in a taken cell
					// 9999 marks a cell as claimed two or more times
					*(field+j*fieldSize+i) = 9999;
					intact = false;
				}
			}
		}
		// Add the potential claim to intactPotential 
		if(intact){
			*topmostClaim = {id, posX, posY, lenX, lenY};
			topmostClaim++;
		}
		// Print the complete field if it's small enough
		if(fieldSize < 10)
			printField((unsigned*)field,fieldSize);
	}	
	printf("PART I: Number of overlaps: %u\n", countOverlap((unsigned*)field, fieldSize));
	
	printf("PART II: Non-overlapped claims:\n");
	// Iterate through intactPotential and find the only intact claim
	for(claim* it = intactPotential; it < topmostClaim; it++){
		// Read elements from the iterator
		id = it->id;
		posX = it->posX;
		posY = it->posY;
		lenX = it->lenX;
		lenY = it->lenY;
		// Logical variable that turns false if the read claim is definitely not intact
		bool intact = true;
		// Ye olde for-loop
		for (int i = posX; i < posX+lenX; ++i){
			for (int j = posY; j < posY+lenY; ++j){
				if(*(field+j*fieldSize+i) != id){
					intact = false;
					break;
				}
			}
		}
		// Print the claim elements
		if(intact){
			printf("#%u @ %u,%u: %ux%u\n", id, posX, posY, lenX, lenY);
		}
	}
	return 0;
}
// Counts overlapping cells in a claim field
unsigned countOverlap(unsigned* field, int fieldDim){
	// It's a... counter :)
	unsigned counter = 0;

	// Ye olde for-loop	
	for (int i = 0; i < fieldDim; ++i){
		for (int j = 0; j < fieldDim; ++j){
			// If the cell is 9999, that means it was claimed twice
			if(*(field+j*fieldDim+i) == 9999){
				counter++;
			}
		}
	}
	return counter;
}

// Prints the field of claims
/*
Example:
|  . |  . |  . |  . |  . |  . |  . |  . |
|  . |  . |  . |   1|   1|   1|   1|  . |
|  . |  . |  . |   1|   1|   1|   1|  . |
|  . |   2|   2|XXXX|XXXX|   1|   1|  . |
|  . |   2|   2|XXXX|XXXX|   1|   1|  . |
|  . |   2|   2|   2|   2|   3|   3|  . |
|  . |   2|   2|   2|   2|   3|   3|  . |
|  . |  . |  . |  . |  . |  . |  . |  . |
*/
void printField(unsigned* field, int fieldDim){
	for (int i = 0; i < fieldDim; ++i){
		for (int j = 0; j < fieldDim; ++j){
			unsigned c = *(field+j*fieldDim+i);
			if(c==0)
				printf("|  . ");
			else if(c < 9999)
				printf("|%4u",c);
			else
				printf("|XXXX");
		}
		printf("|\n");
	}
	printf("\n");
}