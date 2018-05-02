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
		printf("������� ����� ������� ��� 0 ��� ������: ");
		scanf("%d", &nz);

		//1.	�������� ������� int f(int h, int m, int s), ������� ��������� ��� ����� ��������� (���� h, ������ m � ������� s)
		//� ���������� ���������� ������, ��������� � ������ ���
		if (nz == 1)
		{
			int h, m, s, sek;
			h = rand() % 24;
			m = rand() % 60;
			s = rand() % 60;

			sek = f(h, m, s);
			printf("����� %i:%i:%i � �������� ����� - %i\n", h, m, s, sek);
		}

		//2.	�������� ��� ������������ ���������� ������. ���������� �������� ����� ������������ �����, 
		//� ������� ����� ��� ������ ���� ���� ����� ����� ��� ��������� ���� ����. (���������� ������� ��� ������� ����� ���� ������������ �����.)
		else if (nz == 2)
		{
			int count = 0;
			for (int i = 100000; i < 1000000; i++)
				if (sumnum(i % 1000) == sumnum(i / 1000))
				{
					count++;
					printf("%i\t", i);
				}
			printf("\n����� %i ���������� �������!\n", count);
		}

		//4.	���� ����� ��������� �����. ���������� ������������ �� ���. 
		//(���������� �������, ��������� �������� �� ���� ��������� �����.)
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