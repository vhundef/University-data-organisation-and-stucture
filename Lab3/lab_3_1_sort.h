//
// Created by vhundef on 21.05.19.
//

#ifndef UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_LAB_3_1_SORT_H
#define UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_LAB_3_1_SORT_H


#include <chrono>

class Lab3_1_Sort {
public:
	void insertionSort(int *, int);
	void binInsertionSort(int *, int);

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> t_start;
	std::chrono::time_point<std::chrono::high_resolution_clock> t_end;


	void setTStart();

	void setTEnd();

	double calcTimeDiffInMs(){
		return std::chrono::duration<double, std::milli>(t_end-t_start).count();
	}
};

void Lab3_1_Sort::insertionSort(int *arrayPtr, int length) {
	setTStart();
	int temp, // временная переменная для хранения значения элемента сортируемого массива
			item; // индекс предыдущего элемента
	for (int counter = 1; counter < length; counter++) {
		temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 &&
		       arrayPtr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
			arrayPtr[item] = temp;
			item--;
		}
	}
	setTEnd();
	std::cout<<"Сортировка заняла "<<calcTimeDiffInMs()<<" мс"<<std::endl;
	if(calcTimeDiffInMs()<1)
		throw std::runtime_error("Кто-то не отчистил память?");
	//return ;

}
void Lab3_1_Sort::binInsertionSort (int* data, int size){
	setTStart();
	int i;
	for (i = 0; i < size; i++) {
		int pos = -1;
		int start = 0;
		int end = i - 1;
		int numToInsert = data[i];
		// Находим место вставки с помощью бинарного поиска
		while (start <= end && pos == -1) {
			int middle = (start + end) / 2;
			if (numToInsert > data[middle]) {
				start = middle + 1;
			} else if (numToInsert < data[middle]) {
				end = middle - 1;
			} else {
				pos = middle;
			}
		}
		if(end < 0){
			// определяем позицию в случае если элемент меньше всех отсортированных
			pos = 0;
		} else if(start >= i){
			// определяем позицию в случае если элемент больше всех отсортированных
			pos = i;
		}
		if (pos < i) {
			// сдвигаем элементы вправо на одну позицию
			int j;
			for (j = i; j > pos; j--) {
				data[j] = data[j - 1];
			}
			data[pos] = numToInsert;
		}
	}
	setTEnd();
	calcTimeDiffInMs();
	std::cout<<"Сортировка заняла "<<calcTimeDiffInMs()<<" мс"<<std::endl;
}

void Lab3_1_Sort::setTStart() {
	t_start = std::chrono::high_resolution_clock::now();
}

void Lab3_1_Sort::setTEnd() {
	t_end = std::chrono::high_resolution_clock::now();
}


#endif //UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_LAB_3_1_SORT_H
