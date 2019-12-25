// Program converts STRING to INT with assembly code. For example: STRING "5245345" --> INT 5245345
#include <iostream>
#include <stdio.h>
#include <typeinfo>

using namespace std;

int main(int argc, char** argv)
{
	int iOut = 0;
	char* pcInp;

	if (argc < 2) {
		cout << " Missing parameter!\n";
		return(0);
	}

	pcInp = argv[1];

	__asm {
		push eax
		push ebx
		push ecx

		xor ecx, ecx // result will be stored here (starting with 0)
		mov ebx, pcInp // full adress of string

		strloop:
		mov al, byte ptr[ebx] // adress of one char
		inc ebx // increasing address for going to next char

		cmp al, 0 // if zero byte (string end) then exit     
		jz finished //Jump Equal or Jump Zero

		imul ecx, 10
		sub eax, 48 // ASCII (from char ASCII integer we subtract 48 to get decimal integer)

		add ecx, eax

		jmp strloop // back to strloop

		finished:
		mov iOut, ecx // store result into iOut

		pop ecx
		pop ebx
		pop eax

	}
	cout << "The number was processed.\nString value: " << pcInp << " Type: " << typeid(pcInp).name();
	cout << "\nInteger value: " << iOut << " Type: " << typeid(iOut).name();
}
