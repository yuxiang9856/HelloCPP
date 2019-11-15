#include <stdio.h>
union uTyp
{
	char cVar;
	int iVar;
};

int main()
{
	uTyp uVar;
	uVar.iVar = 0x1234;
	printf("iVar = %x\n", uVar.iVar);//hex
	printf("cVar = %x\n", uVar.cVar);
	printf("iVar = %d\n", uVar.iVar);//decimal
	printf("cVar = %d\n", uVar.cVar);
	return 0;
}






