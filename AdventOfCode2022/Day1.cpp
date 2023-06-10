#include "AoCHeader.h"

class sortedLinkedList;

dayResult day1Main(char* inputData, int dataLength){

	for (int counter = 0; counter < dataLength; counter++) {

		int numStart = 0;

		sortedLinkedList bagList = sortedLinkedList(dataLength / 3);

		if (inputData[counter] != 0xA) {
			//Do nothing, let counter increment until we find a line end
		} else {

			





		}

	}

	dayResult output;
	output.part1 = "no";
	output.part2 = "yes";

	return output;
}

class sortedLinkedList {

public:
	sortedLinkedList(long long maxLength) {
		list = new int[2 * maxLength];

		allocated = new bool[maxLength];
		for (int i = 0; i < maxLength; i++) {
			allocated[i] = false;
		}

		nextWrite = 0;
		headAdr = -1;
	}

	void addItem(int item) {
		if (headAdr = -1) {
			list[2 * nextWrite] = item;
			list[2 * nextWrite + 1] = -1;
			allocated[nextWrite] = true;
			nextWrite += 1;
			headAdr = nextWrite;
		} else {

			//Search for a non-allcoated slot to use
			while (allocated[nextWrite]) { nextWrite += 1; }

			//Now, traverse the list, looking for the first element less than the element we're attempting to insert


		}
	}

	int head() {
		if (headAdr != -1) {
			return list[headAdr];
		} else {
			throw exception("Tried to access head of empty list");
		}
	}

	
private:
	int* list;
	bool* allocated;
	int nextWrite;

	int headAdr;

};