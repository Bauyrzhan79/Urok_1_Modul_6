#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>


int f(int h, int m, int s)
{
	return h * 3600 + m * 60 + s;
}

int sumnum(int a)
{
	int sum = 0, x = a;
	while (x > 0)
	{
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

int findMax(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int nz;

	do
	{
		printf("Введите номер задания или 0 для выхода: ");
		scanf("%d", &nz);

		//1.	Напишите функцию int f(int h, int m, int s), которая принимает три целых аргумента (часы h, минуты m и секунды s)
		//и возвращает количество секунд, прошедших с начала дня
		if (nz == 1)
		{
			int h, m, s, sek;
			h = rand() % 24;
			m = rand() % 60;
			s = rand() % 60;

			sek = f(h, m, s);
			printf("Время %i:%i:%i в секундах будет - %i\n", h, m, s, sek);
		}

		//2.	Получить все шестизначные счастливые номера. Счастливым называют такое шестизначное число, 
		//в котором сумма его первых трех цифр равна сумме его последних трех цифр. (Определить функцию для расчета суммы цифр трехзначного числа.)
		else if (nz == 2)
		{
			int count = 0;
			for (int i = 100000; i < 1000000; i++)
				if (sumnum(i % 1000) == sumnum(i / 1000))
				{
					count++;
					printf("%i\t", i);
				}
			printf("\nВсего %i счастливых номеров!\n", count);
		}

		//4.	Даны шесть различных чисел. Определить максимальное из них. 
		//(Определить функцию, находящую максимум из двух различных чисел.)
		else if (nz == 3)
		{
			int arr[6] = { 0 };			

			for (size_t i = 0; i < 6; i++)
			{
				arr[i] = rand() % 1000;
				printf("%d\t", arr[i]);
			}

			int maxx = arr[0];

			for (size_t i = 0; i < 5; i++)
			{
				maxx = findMax(maxx, arr[i+1]);
			}

			printf("\nMax = %d\n", maxx);
		}


	} while (nz!=0);
}