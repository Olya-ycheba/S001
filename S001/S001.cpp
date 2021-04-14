// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include<iostream>

int main()
{

	char s[256];
	char s1[256];
	char s2[512];
	char fd[] = "%d\n";
	char f[] = "%s";

	_asm
	{
		lea ebx, s
		push ebx
		lea ecx, f
		push ecx
		call scanf
		add esp, 8

		lea ebx, s1
		push ebx
		lea ecx, f
		push ecx
		call scanf
		add esp, 8

		lea ebx, s
		mov ecx, -1
		dec ebx
		lea edx, s2
		dec edx

		b1 :
		inc ecx
			inc ebx
			inc edx
			mov al, [ebx]
			mov[edx], al
			cmp al, 0
			jnz b1

			lea ebx, s1
			dec edx
			dec ebx

			b2 :
		inc edx
			inc ebx
			mov al, [ebx];
		mov[edx], al
			cmp al, 0
			jnz b2

			lea ebx, s2
			push ebx
			lea ecx, f
			call printf
			add esp, 8

	}
	system("pause");
}

