#include <iostream>
#include <vector>

/// Simple tic-tac-toe game to practice basic C++ concepts
/// Two players take turns writing a number where an X or O will be placed

void generate_table(std::vector<char> position) {
	std::cout << "Player 1 : <X>\nPlayer 2 : <O>\n\n";
	std::cout << " " << position[0] << " " << "| " << position[1] << " |" << " " << position[2] << " \n";
	std::cout << "--- --- --- \n";
	std::cout << " " << position[3] << " " << "| " << position[4] << " |" << " " << position[5] << " \n";
	std::cout << "--- --- --- \n";
	std::cout << " " << position[6] << " " << "| " << position[7] << " |" << " " << position[8] << " \n\n";
}

bool horizontal_cond(std::vector<char> position) {
	if ((position[0] == position[1]) && (position[1] == position[2]))
		return true;
	else if ((position[3] == position[4]) && (position[4] == position[5]))
		return true;
	else if ((position[6] == position[7]) && (position[7] == position[8]))
		return true;
	else
		return false;
}
bool vertical_cond(std::vector<char> position) {
	if ((position[0] == position[3]) && (position[3] == position[6]))
		return true;
	else if ((position[1] == position[4]) && (position[4] == position[7]))
		return true;
	else if ((position[2] == position[5]) && (position[5] == position[8]))
		return true;
	else
		return false;
}
bool diagonal_cond(std::vector<char> position) {
	if ((position[0] == position[4]) && (position[4] == position[8]))
		return true;
	else if ((position[2] == position[4]) && (position[4] == position[6]))
		return true;
	else
		return false;
}

bool check_win(std::vector<char> position) {
	if (vertical_cond(position) || horizontal_cond(position) || diagonal_cond(position))
		return true;
	else
		return false;
}

std::vector<char> get_new_pos(std::vector<char> position, int player) {
	int number_to_change;

jump:
	std::cout << "Player " << player + 1 << ", pick position: ";
	std::cin >> number_to_change;
	std::cout << "--------------------------\n\n";

	// Control the input
	if (number_to_change < 1 || number_to_change>9) {
		std::cout << "Position out of bounds, give another number. \n";
		goto jump;
	}
	if (position[number_to_change - 1] == 'X' || position[number_to_change - 1] == 'O') {
		std::cout << "Position not empty, give another number. \n";
		goto jump;
	}

	// Update the vector
	position[number_to_change - 1] = (player == 0) ? 'X' : 'O';

	return position;

}

int main() {
	int board_full = 0, player = board_full % 2;
	bool three_in_a_row = false;
	std::vector<char> position = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	generate_table(position);

	while (!three_in_a_row && board_full != 9) {

		position = get_new_pos(position, player); // Gets the vector with updated positions
		generate_table(position);
		three_in_a_row = check_win(position);
		board_full += 1;

		if (three_in_a_row) {
			std::cout << "Congratulations, player " << player + 1 << "!\n";
			break;
		}
		if (board_full == 9) {
			std::cout << "The board is full, try playing one more time!\n";
			break;
		}
		player = board_full % 2;
	}
}