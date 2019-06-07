#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

Employee* employee_new(void)
{
	return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* retorno=NULL;
	Employee* pAuxEmployee;

	if(idStr!=NULL &&
	   nombreStr!=NULL &&
	   horasTrabajadasStr!=NULL &&
	   sueldoStr!=NULL)
	{
		pAuxEmployee=employee_new();
		if(pAuxEmployee!=NULL)
		{
			if(	!employee_setIdStr(pAuxEmployee,idStr) &&
				!employee_setNombre(pAuxEmployee,nombreStr) &&
				!employee_setHorasTrabajadasStr(pAuxEmployee,horasTrabajadasStr) &&
				!employee_setSueldoStr(pAuxEmployee,sueldoStr) &&
				!employee_setEstado(pAuxEmployee,0))
			{
				retorno=pAuxEmployee;
			}
			else
			{
				employee_delete(pAuxEmployee);
			}
		}
	}
	return retorno;
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
    if(this != NULL && !isValidInt(id,10000,0))
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
    if(this != NULL && !isValidName(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
    if(this != NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
    if(this != NULL)
    {
        this->sueldo=sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_setEstado(Employee* this,int estado)
{
	int retorno = -1;
    if(this != NULL && !isValidInt(estado,1,0))
    {
        this->estado = estado;
        retorno = 0;
    }
    return retorno;
}

int employee_getEstado(Employee* this,int* estado)
{
	int retorno = -1;
    if(this != NULL && estado != NULL)
    {
        *estado = this->estado;
        retorno = 0;
    }
    return retorno;
}

int employee_setIdStr(Employee* this, char* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = employee_setId(this,atoi(id));
    }
    return retorno;
}

int employee_setHorasTrabajadasStr(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = employee_setHorasTrabajadas(this,atoi(horasTrabajadas));
    }
    return retorno;
}

int employee_setSueldoStr(Employee* this, char* sueldo)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = employee_setSueldo(this,atoi(sueldo));
    }
    return retorno;
}

int employee_getIdMax(LinkedList* pArray)
{
	int i;
	int id;
	int max;
	int flag=0;
	Employee* pAux;
	if(pArray!=NULL)
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			pAux=ll_get(pArray,i);
			employee_getId(pAux,&id);
			if(flag==0 || id>max)
			{
				max=id;
				flag=1;
			}
		}
	}
	return max;
}

int employee_getEmpById(LinkedList* pArray,int id,Employee* result)
{
	int i;
	int bufferId;
	int retorno=-1;

	if(pArray!=NULL)
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			result=ll_get(pArray,i);
			employee_getId(result,&bufferId);
			if(id==bufferId)
			{
				retorno=0;
			}
		}
	}
	return retorno;
}

int employee_compararPorNombre(void* this1,void* this2)//recibe dos void
{
	char bufferA[4096];
	char bufferB[4096];

	employee_getNombre((Employee*)this1,bufferA);
	employee_getNombre((Employee*)this2,bufferB);
	if(strcmp(bufferA,bufferB)>0)
		return 1;
	else if(strcmp(bufferA,bufferB)>0)
		return -1;
	return 0;
}

//int fun(int indice,int (*pFun) (void*,void*),float peso)
