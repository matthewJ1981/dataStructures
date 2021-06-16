#include <iostream>
#include <vector>

//Convert 1d position to 2d position, y is first.
std::pair<size_t, size_t> convertToCoords(size_t pos, size_t width)
{
	return { pos / width + 1, pos % width + 1 };
}

//check to see if a move from the current position is a valid position on the board.
//Starting attempt is positive x, subsequent attempts go counter clockwise.
bool validMove(size_t dirIndex, size_t boardPos, size_t width, size_t height)
{
	//Check where the current position is
	bool topRow = boardPos < width;
	bool bottomRow = boardPos >= width * height - width;
	bool rightColumn = (boardPos + 1) % width == 0;
	bool leftColumn = boardPos % width == 0;

	//Check if a move from the current position in the attempted direction is on the board
	//Eg. dirIndex = 0 is the positive x direction, right column means the current position 
	//is in the right column and so the move is invalid
	if ((dirIndex == 0 && rightColumn)					||
		(dirIndex == 1 && (rightColumn || topRow))		||
		(dirIndex == 2 && topRow)						||
		(dirIndex == 3 && (leftColumn || topRow))		||
		(dirIndex == 4 && leftColumn)					||
		(dirIndex == 5 && (leftColumn || bottomRow))	||
		(dirIndex == 6 && bottomRow)					||
		(dirIndex == 7 && (rightColumn || bottomRow))
		)
		return false;
	else
		return true;
}

//find the starting and ending positions of all the words in the word list
std::vector<std::vector<std::pair<size_t, size_t>>> findWord(std::vector<char>& board, size_t width, std::vector<std::string>& wordList)
{
	//Array to hold the positions of each character of each word
	std::vector<std::vector<std::pair<size_t, size_t>>> positions{ wordList.size() };
	//Array to hold the computation performed on the current 1d position on the board to get to the next position.
	//directions 0 = positive x direction, subsequent directions go counter clockwise
	std::vector<int> directions{ 1, -((int)width - 1), -(int)width, -((int)width + 1), -1, ((int)width - 1), (int)width, ((int)width + 1) };
	//Array to keep track of which words have been found
	std::vector<bool> found( wordList.size(), false);

	//Iterate over every letter on the board
	for (size_t i = 0; i < board.size(); i++)
	{
		//Check each word to see if the current letter is the start of the word
		for (size_t j = 0; j < wordList.size(); j++)
		{
			//If the current letter does not stat the word, or the word has already been found then ignore the word.
			if (board[i] != wordList[j][0] || found[j] == true)
				continue;

			//Iterate over every direction looking for the word
			for (size_t k = 0; k < directions.size(); k++)
			{
				//Keep track of position on the board as we search for letters
				size_t positionOnBoard = i;
				//Keep current position in the word for comparison
				size_t positionInWord = 0;
				//Remember if a move has been made to determine if we have gone past the end of the word
				//to see if we need to move backwards later
				bool moved = false;
				//Keep moving in the current direction until we find the word or don't
				while(board[positionOnBoard] == wordList[j][positionInWord])
				{
					//Move to next letter in the word
					positionInWord++;
					//reset the moved flag
					moved = false;
					//Check to see if a move in the current direction is valid and if so move to the next position
					if (validMove(k, positionOnBoard, width, board.size() / width))
					{
						//Adjust the board position
						positionOnBoard += directions[k];
						//Set the moved flag
						moved = true;
					}
				}

				//If we find a letter not in the word, either we found the whole word if the positioninWord = the size of the word
				//or we didn't find the word
				if (positionInWord == wordList[j].size())
				{
					//convert and add the y,x coordinates of the words starting position
					positions[j].push_back(convertToCoords(i, width));
					//convert and add the y,x coordinates of the words ending position
					positions[j].push_back(convertToCoords(positionOnBoard - (int)moved * directions[k], width) );
					//Set found flag for the word so we can stop looking for it
					found[j] = true;
					//Exit the k loop
					break;
				}
			}
		}
	}

	return positions;
}