#include <cctype>
#include <string>
#include <iostream>

char GetLowerOrUpperCharacter(int combinedDistance, int offset) { // Returns the lower or uppercase varient depending on the ascii offset
	if (combinedDistance > 25) {
		return char((combinedDistance) % 26) + offset; // % 26 is there to account for character wrapping if the character + key goes beyond Z
	}
	else {
		return char((combinedDistance)+offset);
	}
}

char GetCharacter(char character, int key) {
	if (!isalpha(character)) {
		return character;
	}
	int combinedDistance = 0;

	if (isupper(character)) {
		combinedDistance = (int(character) - 65) + key; // 65 is the starting point for the capital A. Subtracting 65 from the character gets its position in the alphabet from A.
		return GetLowerOrUpperCharacter(combinedDistance, 65);
	}
	else {
		combinedDistance = (int(character) - 97) + key;
		return GetLowerOrUpperCharacter(combinedDistance, 97);
	}
}

int main() {
	std::string phrase;
	int key = 0;

	std::cout << "String to encode: ";
	getline(std::cin, phrase);
	
	std::cout << "Key amount: ";
	std::cin >> key;

	for (auto character : phrase) {
		std::cout << GetCharacter(character, key);
	}

	return 0;
}