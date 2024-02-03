/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

void input (int *buffer, int *length);
void output (int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main()
{
    int data[NMAX], n;
	int num = 0;
	int data1[NMAX];
 	input(data, &n);
    sum_numbers(data, n);
	output(data, n);
	find_numbers(data, n,  num, data1);
    return 0;
}


/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
void input (int *buffer, int *length){
	if (scanf("%d", length) != 1 && *length <= 10) {
    printf("n/a");
  };
  for (int *p = buffer; p - buffer < *length; p++) {
    if (scanf("%d", p) != 1) {
      printf("n/a\n");
    };
  }
}

void output (int *buffer, int length){
	printf("%d ", sum_numbers(buffer, length));
	printf("\n");
}




int sum_numbers(int *buffer, int length)
{
	int sum = 0;
	
	for (int i = 0; i < length; i++)
	{
		if (buffer[i] % 2 == 0)
		{
			sum = sum + buffer[i];
		}
	}
	return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers)
{
	int j = 0;
	for(int i = 0; i < length; i++){
		if(buffer[i] != 0 && sum_numbers(buffer, length) % buffer[i] == 0){
			number = buffer[i];
			numbers[j] = number;
			j++;
		}
	}


for(int i = 0; i < j; i++){
	printf("%d ", numbers[i]);
}
	return 0;

}

