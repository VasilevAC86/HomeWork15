# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <algorithm>

// Глобальные константы и переменные
const short rows = 10, cols = 10; // Размеры матрицы
short array[rows][cols]{}; // Объявление матрицы
short lenght, lenght_Row; // Объявление переменных для хранения длины табуляции, введённой пользователем, и длины числа строки матрицы
short N = rows + 1; // Объявление переменной для хранения номера строки матрицы. Инициализируем исходное значение величиной, превышаюшей кол-во строк матрицы
char my_Choice; // Объявляем переменную для хранения выбора пользователя

// Поскольку вывод матрицы в задаче будет два раза, то, что бы не повторять один и тот же код, пишем подпрограмму для вывода матрицы в виде функции array_Output()
void array_Output() {
	for (short i = 0; i < rows; i++) { // Вложенный цикл для вывода массива в таблицу
		if (i == N) // Меняем цвет отсортированной строки N для удобства проверки
			if (my_Choice == '1')
				std::cout << "\033[91m";
			else
				std::cout << "\033[92m";
		else
			std::cout << "\033[0m";
		for (short j = 0; j <= cols; j++) {	// +1 столбец к cols для вывода наименовая строчек		
			std::cout << "\033[4m"; // Указываем escape-последовательность подчёркнутого вывода в консоль для формирования эффекта таблицы
			if (j) { // Вывод элемента массива
				std::cout << array[i][j - 1];
				for (short k = 0; k < lenght - std::to_string(array[i][j - 1]).length(); k++) // Дополнительный цикл для указанной пользователем табуляции элементов массива
					std::cout << ' ';
				if (j != cols) // Условие для вывода последнего столбца
					std::cout << "| ";
				else
					std::cout << "|";
			}
			else { // Вывод наименования строк (в зависимости от кратности rows табуляция таблицы не нарушается)				
				std::cout << "Row N " << i;
				for (short k = 0; k < (lenght_Row - std::to_string(i).length() + 1); k++)
					std::cout << ' ';
				std::cout << "| ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "\033[0m"; // Отменяем подчёркивание символов в консоли
}
int main() {
	//const short rows = 10, cols = 10; // Размеры матрицы
	//short array[rows][cols]{}; // Объявление матрицы
	short lenght_Max; // Объявление максимальной длины элемента массива	
	srand(time(NULL));
	for (short i = 0; i < rows; i++) { // Вложенный цикл для заполнение массива 
		for (short j = 0; j < cols; j++) 
			array[i][j] = rand() % 101; // [0...100]						
	}	
	lenght_Max = std::to_string(array[0][0]).length(); // Инициализируем значение максимальной длины элемента массива значением длины первого элемента
	for (short i = 0; i < rows; i++) // Вложенный цикл для определения максимальной длины элемента в массиве
		for (short j = 0; j < cols; j++) {
			short m = std::to_string(array[i][j]).length(); // Объявляем и инициализируем локальную переменную для хранения длины текущего элемента массива
			lenght_Max = m > lenght_Max ? m : lenght_Max; // Определяем длину максимального элемента массива
		}
	std::cout << "Enter the lenght of the TAB (in symbols) to form the table (at least " << lenght_Max << ") -> "; // Предоставляем пользователю выбор длины табуляции между элементамм матрицы
	std::cin >> lenght; 
	while (lenght < lenght_Max) { // Проверка введённого пользователем размера табуляции
		std::cout << "Input error!\nEnter the lenght of the TAB (in symbols) to form the table (at least " << lenght_Max << ") -> ";
		std::cin >> lenght;
	}
	lenght_Row = std::to_string(rows).length(); // Объявляем и инициализируем переменную для хранения длины числа константы rows
	std::cout << "\nSource array:\n\n";
	array_Output();
	
	// Задача 1. Сумма каждого ряда 
	std::cout << "\nTask 1. The sum of each row of the array\n\n";
	int arr_Sum[rows]{}; // Объявляем одномерный массив размером с кол-во строк матрицы array, все элементы этого массива инициализируем нулём	
	for (short i = 0; i < rows; i++) // Вложенный цикл для формирования массива arr_Sum 
		for (short j = 0; j < cols; j++)
			arr_Sum[i]+=array[i][j]; // Каждый элемент arr_Sum равен сумме всех элементов в соответствующей строке матрицы array
	std::cout << "\033[4m"; // Указываем подчёркивание текста для формирования эффекта таблицы в консоли
	for (short i = 0; i <= rows; i++) { // Циклы для формирования таблицы с данными массива arr_Sum
		for (short j = 0; j < 2; j++) { // Цикл формирования столбцов таблицы
			if (j == 0 && i == 0)
				std::cout << " Rows N |"; // Заголовок первого столбца
			else
				if (j == 0) { // Формирование наименований каждой строки таблицы
					std::cout << "  " << i - 1;
					for (short k = 0; k < 6 - std::to_string(i - 1).length(); k++)
						std::cout << " ";
					std::cout << "| ";
				}
				else
					if (i == 0) 
						std::cout << "   Sum   "; // Заголовок второго столбца таблицы
					else { // Вывод в таблицу данных массива arr_Sum
						std::cout << "  " << arr_Sum[i - 1];
						short m = std::to_string(arr_Sum[i - 1]).length();
						if (m < 6)
							for (short k = 0; k < 6 - m; k++)
								std::cout << " ";
					}
		}
		std::cout << std::endl;
	}
	std::cout << "\033[0m"; // Отмена подчёркивания текста

	// Задача 2. Сортировка рада массива с номером N
	std::cout << "\n\nTask 2. Sorting row of array with number N\n\n";
	std::cout << "Enter the number of row for sorting (from 0 to " << rows - 1 <<") -> ";
	std::cin >> N;
	while (N >= rows) {
		std::cout << "Input error!\nEnter the number of row for sorting (from 0 to " << rows - 1 << ") -> ";
		std::cin >> N;
	}
	short arr_N[cols]{}; // Объявляем и инициализируем нулями массив arr_N размером cols
	for (short i = 0; i < cols; i++) // Цикл формирования массива arr_N
		arr_N[i] = array[N][i]; // В массив arr_N записываем строку матрицы array с номером N				
	std::cout << "\nSelect the type of sorting for row " << N <<" of the matrix:\npress the '1' key to sort row " << N << " of the matrix in ascending order\npress any keys to sort row " << N << " of the matrix in descending order\n\nYour choise -> ";
	std::cin >> my_Choice;
	switch (my_Choice) { // Сортировка массива arr_N в зависимости выбора пользователя
	case '1':
		for (short i = 0; i < cols - 1; i++)
			std::sort(arr_N, arr_N + cols); // Сортировка массива arr_N по возрастанию элементов
		break;
	default:
		for (short i = cols - 1; i > 0; i--)
			for (short j = 0; j < i; j++)
				if (arr_N[j] < arr_N[j+ 1]) { // Сортировка массива arr_N по убыванию элементтов
					short tmp = arr_N[j];
					arr_N[j] = arr_N[j + 1];
					arr_N[j + 1] = tmp;
				}
	}
	for (short i = 0; i < cols; i++) // Перезаписываем исходную матрицу с отсортированной строкой N
		array[N][i] = arr_N[i];
	std::cout << "\nCorrected matrix:\n\n";
	array_Output(); // Выводим преобразаванную матрицу в консоль

	return 0;		
}