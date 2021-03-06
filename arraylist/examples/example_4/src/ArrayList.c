#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void* pElements;
    pList = (ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;
            pList->len=al_len;
            pList->set=al_set;
            pList->remove=al_remove;
            pList->clear=al_clear;
            pList->clone=al_clone;
            pList->get=al_get;
            pList->contains=al_contains;
            pList->push=al_push;
            pList->indexOf=al_indexOf;
            pList->isEmpty=al_isEmpty;
            pList->pop=al_pop;
            pList->subList=al_subList;
            pList->containsAll=al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pList, void* pElement)
{

    void* pAux;
    if(pList!=NULL&&pElement!=NULL)
    {
        pList->pElements[pList->size]=pElement;//size marca el indice vacio
        pList->size++;
    }
    else
    {
        return -1;
    }
    if(pList->size >=pList->reservedSize)//si el nro reservado es igual a lo que esta cargado
    {

        pList->reservedSize+=10;
        pAux = (void*)realloc(pAux,sizeof(void*)*pList->reservedSize);//reservo mas memora con un puntero auxiliar
        if(pAux==NULL)
        {
            printf("No hay espacio en memoria");
            return -1;
        }
        else
        {
            pList->pElements=pAux;//si hay espacio le paso el espacio de realloc a plist
        }
    }
    return 0;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList)
{



    if(pList!=NULL)
    {
        return 0;
        pList=NULL;
    }
    else
    {
        return -1;

    }
    return 1;

}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */




int al_len(ArrayList* pList)
{

    int returnAux=-1;

    if(pList!=NULL)
    {
        return pList->size;

    }
    else
    {
        return returnAux;

    }



}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */



void* al_get(ArrayList* pList, int index)
{

    void* returnAux=NULL;

    if(pList!=NULL)
    {
        if(index>=0&&index<pList->size)
        {

            return pList->pElements[index];
        }


    }
    return returnAux;

}



/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElements)
{
    int returnAux =0;
    int i;

    if(pList!=NULL&&pElements!=NULL)
    {

        for(i=0; i<pList->size; i++)
        {
            if(pList->pElements[i]==pElements)
            {

                returnAux= 1;
                break;
            }



        }

    }
    else
    {
        returnAux=-1;

    }
    return returnAux;

}

/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElements)
{


    int returnAux=-1;

    if(pList!=NULL&&pElements!=NULL)
    {

        if(index>=0&&index<pList->size)
        {


            pList->pElements[index]=pElements;
            returnAux =0;


        }


    }


    return returnAux;
}






/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pList,int index)
{
    int returnAux=-1;
    if(pList!=NULL)
    {
        if(index>=0&&index<pList->size)
        {


            pList->pElements[index]=NULL;
            pList->size--;
            returnAux= 0;


        }
    }

    return returnAux;

}

/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList, void* pElements)
{


    if(pList!=NULL)
    {

        pElements=NULL;
        pList->pElements=pElements;
        pList->size=0;

        return 0;

    }
    else
    {


        return -1;

    }


}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* pList)
{
    ArrayList* returnAux = NULL;

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement)
{

    int returnAux = -1;

    if(pList!=NULL&&pElement!=NULL)
    {
        if(index>=0&&index<pList->reservedSize)
        {
            pList->size ++;

            resizeUp(pList);
            expand(pList,index);
            al_set(pList,index,pElement);


            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* pElement)
{

    int index;
    int returnAux=-1;

    if(pList!=NULL&&pElement!=NULL)
    {

        for(index=0; index<pList->size; index++)
        {

            if(pList->pElements[index]==pElement)
            {

                return index;

                break;

            }


        }



    }

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList)
{



    if(pList!=NULL)
    {

        if(pList->size>0)
        {

            return 0;
        }
        return 1;

    }

    return -1;


}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList,int index)
{
    void* returnAux=NULL;

    if(pList!=NULL)
    {
        if(index>=0&&index<pList->size)
        {

            returnAux=al_get(pList,index);

            al_remove(pList,index);

        }
    }


    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* pList,int from,int to)
{
    void* returnAux=NULL;

    if(pList!=NULL)
    {


    }

    return returnAux;

}


/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2)
{

    int returnAux= -1;
    int index;

    if(pList!=NULL&&pList2!=NULL)
    {
        returnAux =1;

        for(index=0; index<pList2->size-1; index++)
        {


            if(!al_contains(pList,pList2->pElements[index]))
            {
                returnAux = 0;
                break;
            }

        }

    }
    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pList, int (*pFunc)(void*,void*), int order)
{

    int returnAux=-1;
    int i;
    int j;
    void* pAux=NULL;

    if(pList!=NULL&&pFunc!=NULL)
    {
        if(order==0||order==1)
        {

            for(i=0; i<pList->size-1; i++)
            {

                for(j=i+1; j<pList->size; j++)
                {

                    if(pFunc(pList->pElements[i],pList->pElements[j])==1&&order==1)
                    {
                        pAux=pList->pElements[i];
                        pList->pElements[i]=pList->pElements[j];
                        pList->pElements[j]=pAux;

                    }
                    else if(pFunc(pList->pElements[i],pList->pElements[j])==-1&&order==0)
                    {

                        pAux=pList->pElements[i];
                        pList->pElements[i]= pList->pElements[j];
                        pList->pElements[j]=pAux;

                    }
                }

            }

            returnAux=0;
        }


    }

    return returnAux;

}




/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pList)
{

    void* pAux=NULL;
    if(pList!=NULL)
    {


        if(pList->size==pList->reservedSize)
        {

            pList->reservedSize+=AL_INCREMENT;
            pAux = (void*)realloc(pAux,sizeof(void*)*pList->reservedSize);
            if(pAux==NULL)
            {
                printf("No hay espacio en memoria");
                return -1;
            }
            else
            {
                pList->pElements=pAux;
            }
        }


        return 0;

    }
    return -1;



}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index)
{

    int i;
    if(pList!=NULL&&index>=0&&index<pList->size)
    {
        for(i=pList->size; i>index; i--)
        {

            pList->pElements[i+1]=pList->pElements[i];


        }
        return 0;
    }

    return -1;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index)
{
    int returnAux = -1;

    return returnAux;
}


