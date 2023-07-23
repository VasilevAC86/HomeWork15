# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <algorithm>

// ���������� ��������� � ����������
const short rows = 10, cols = 10; // ������� �������
short array[rows][cols]{}; // ���������� �������
short lenght, lenght_Row; // ���������� ���������� ��� �������� ����� ���������, �������� �������������, � ����� ����� ������ �������
short N = rows + 1; // ���������� ���������� ��� �������� ������ ������ �������. �������������� �������� �������� ���������, ����������� ���-�� ����� �������
char my_Choice; // ��������� ���������� ��� �������� ������ ������������

// ��������� ����� ������� � ������ ����� ��� ����, ��, ����� �� ��������� ���� � ��� �� ���, ����� ������������ ��� ������ ������� � ���� ������� array_Output()
void array_Output() {
	for (short i = 0; i < rows; i++) { // ��������� ���� ��� ������ ������� � �������
		if (i == N) // ������ ���� ��������������� ������ N ��� �������� ��������
			if (my_Choice == '1')
				std::cout << "\033[91m";
			else
				std::cout << "\033[92m";
		else
			std::cout << "\033[0m";
		for (short j = 0; j <= cols; j++) {	// +1 ������� � cols ��� ������ ���������� �������		
			std::cout << "\033[4m"; // ��������� escape-������������������ ������������� ������ � ������� ��� ������������ ������� �������
			if (j) { // ����� �������� �������
				std::cout << array[i][j - 1];
				for (short k = 0; k < lenght - std::to_string(array[i][j - 1]).length(); k++) // �������������� ���� ��� ��������� ������������� ��������� ��������� �������
					std::cout << ' ';
				if (j != cols) // ������� ��� ������ ���������� �������
					std::cout << "| ";
				else
					std::cout << "|";
			}
			else { // ����� ������������ ����� (� ����������� �� ��������� rows ��������� ������� �� ����������)				
				std::cout << "Row N " << i;
				for (short k = 0; k < (lenght_Row - std::to_string(i).length() + 1); k++)
					std::cout << ' ';
				std::cout << "| ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "\033[0m"; // �������� ������������� �������� � �������
}
int main() {
	//const short rows = 10, cols = 10; // ������� �������
	//short array[rows][cols]{}; // ���������� �������
	short lenght_Max; // ���������� ������������ ����� �������� �������	
	srand(time(NULL));
	for (short i = 0; i < rows; i++) { // ��������� ���� ��� ���������� ������� 
		for (short j = 0; j < cols; j++) 
			array[i][j] = rand() % 101; // [0...100]						
	}	
	lenght_Max = std::to_string(array[0][0]).length(); // �������������� �������� ������������ ����� �������� ������� ��������� ����� ������� ��������
	for (short i = 0; i < rows; i++) // ��������� ���� ��� ����������� ������������ ����� �������� � �������
		for (short j = 0; j < cols; j++) {
			short m = std::to_string(array[i][j]).length(); // ��������� � �������������� ��������� ���������� ��� �������� ����� �������� �������� �������
			lenght_Max = m > lenght_Max ? m : lenght_Max; // ���������� ����� ������������� �������� �������
		}
	std::cout << "Enter the lenght of the TAB (in symbols) to form the table (at least " << lenght_Max << ") -> "; // ������������� ������������ ����� ����� ��������� ����� ���������� �������
	std::cin >> lenght; 
	while (lenght < lenght_Max) { // �������� ��������� ������������� ������� ���������
		std::cout << "Input error!\nEnter the lenght of the TAB (in symbols) to form the table (at least " << lenght_Max << ") -> ";
		std::cin >> lenght;
	}
	lenght_Row = std::to_string(rows).length(); // ��������� � �������������� ���������� ��� �������� ����� ����� ��������� rows
	std::cout << "\nSource array:\n\n";
	array_Output();
	
	// ������ 1. ����� ������� ���� 
	std::cout << "\nTask 1. The sum of each row of the array\n\n";
	int arr_Sum[rows]{}; // ��������� ���������� ������ �������� � ���-�� ����� ������� array, ��� �������� ����� ������� �������������� ����	
	for (short i = 0; i < rows; i++) // ��������� ���� ��� ������������ ������� arr_Sum 
		for (short j = 0; j < cols; j++)
			arr_Sum[i]+=array[i][j]; // ������ ������� arr_Sum ����� ����� ���� ��������� � ��������������� ������ ������� array
	std::cout << "\033[4m"; // ��������� ������������� ������ ��� ������������ ������� ������� � �������
	for (short i = 0; i <= rows; i++) { // ����� ��� ������������ ������� � ������� ������� arr_Sum
		for (short j = 0; j < 2; j++) { // ���� ������������ �������� �������
			if (j == 0 && i == 0)
				std::cout << " Rows N |"; // ��������� ������� �������
			else
				if (j == 0) { // ������������ ������������ ������ ������ �������
					std::cout << "  " << i - 1;
					for (short k = 0; k < 6 - std::to_string(i - 1).length(); k++)
						std::cout << " ";
					std::cout << "| ";
				}
				else
					if (i == 0) 
						std::cout << "   Sum   "; // ��������� ������� ������� �������
					else { // ����� � ������� ������ ������� arr_Sum
						std::cout << "  " << arr_Sum[i - 1];
						short m = std::to_string(arr_Sum[i - 1]).length();
						if (m < 6)
							for (short k = 0; k < 6 - m; k++)
								std::cout << " ";
					}
		}
		std::cout << std::endl;
	}
	std::cout << "\033[0m"; // ������ ������������� ������

	// ������ 2. ���������� ���� ������� � ������� N
	std::cout << "\n\nTask 2. Sorting row of array with number N\n\n";
	std::cout << "Enter the number of row for sorting (from 0 to " << rows - 1 <<") -> ";
	std::cin >> N;
	while (N >= rows) {
		std::cout << "Input error!\nEnter the number of row for sorting (from 0 to " << rows - 1 << ") -> ";
		std::cin >> N;
	}
	short arr_N[cols]{}; // ��������� � �������������� ������ ������ arr_N �������� cols
	for (short i = 0; i < cols; i++) // ���� ������������ ������� arr_N
		arr_N[i] = array[N][i]; // � ������ arr_N ���������� ������ ������� array � ������� N				
	std::cout << "\nSelect the type of sorting for row " << N <<" of the matrix:\npress the '1' key to sort row " << N << " of the matrix in ascending order\npress any keys to sort row " << N << " of the matrix in descending order\n\nYour choise -> ";
	std::cin >> my_Choice;
	switch (my_Choice) { // ���������� ������� arr_N � ����������� ������ ������������
	case '1':
		for (short i = 0; i < cols - 1; i++)
			std::sort(arr_N, arr_N + cols); // ���������� ������� arr_N �� ����������� ���������
		break;
	default:
		for (short i = cols - 1; i > 0; i--)
			for (short j = 0; j < i; j++)
				if (arr_N[j] < arr_N[j+ 1]) { // ���������� ������� arr_N �� �������� ����������
					short tmp = arr_N[j];
					arr_N[j] = arr_N[j + 1];
					arr_N[j + 1] = tmp;
				}
	}
	for (short i = 0; i < cols; i++) // �������������� �������� ������� � ��������������� ������� N
		array[N][i] = arr_N[i];
	std::cout << "\nCorrected matrix:\n\n";
	array_Output(); // ������� ��������������� ������� � �������

	return 0;		
}