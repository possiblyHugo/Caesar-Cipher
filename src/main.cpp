#include <cctype>
#include <string>
#include <iostream>

char GetLowerOrUpperCharacter(int combinedDistance, int offset) {
	if (combinedDistance > 25) {
		return char((combinedDistance) % 26) + offset;
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
		combinedDistance = (int(character) - 65) + key;
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

	int lowerStart = 97;
	int lowerEnd = 122;

	int upperStart = 65;
	int upperEnd = 90;


	for (auto character : phrase) {
		std::cout << GetCharacter(character, key);
	}

	return 0;
}