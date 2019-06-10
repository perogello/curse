#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <clocale>
#include <windows.h>
#include <iostream>

struct elementWord {                                 //Структура для элементов последовательности слов
    char *word;
    int is_read;                    // флаг прочтения//Слово
    struct elementWord *nextPointer;                //Указатель на следуюший элемент
} *pointer, *firstPointer;
int ReadBalance;
int endofsequence;
void wordsList();                                   //Функция для вывода списка с рабочим указателем
void mainMenu();
void menu();

//Функции для работы с последовательностью
void makeSequenceEmpty();
void checkUnread();
void checkSequenceList();
void skipSequenceItem();
void addLastElement();
void showSequenceElement();
void readSequenceItem();
void changeElement();
void setEndSequencePtr();
void outputSequence();
void quitSequence();
void setBeginSequencePtr();

int main()
{
    setlocale(LC_ALL,"Rus");        //Чтобы выводить букавы в консоль на русском языке как белый человек
    firstPointer = NULL;
    ReadBalance=0;
    endofsequence=0;
    mainMenu();                 //Вызов главного меню
    system("cls");
    printf("Заходите ещё!");
    return 0;       //Конец программы
}

void wordsList()
{
    if(endofsequence==0)
    {
    if (firstPointer == NULL) printf("          The list of words is empty!\n");
    else {
        struct elementWord *ptr;
        ptr = firstPointer;
        printf("\n          >Words list: ");
        while (ptr->nextPointer != NULL)
        {
            if (ptr == pointer)
                if(ptr->is_read==0)
                {
                    printf("->%s|", ptr->word);
                    printf(", ");
                }
                else
                {
                    printf("->%s", ptr->word);
                    printf(", ");
                }
            else
                if(ptr->is_read==0)
                {
                    printf("%s|", ptr->word);
                    printf(", ");
                }
                else
                {
                    printf("%s", ptr->word);
                    printf(", ");
                }
            ptr = ptr->nextPointer;

        }
        if(ptr==pointer)
        {
            if(ptr->is_read==0)
            {
                printf("->%s|.\n", ptr->word);
            }
            else
            {
                printf("->%s.\n", ptr->word);
            }
        }
        else
        {
            if(ptr->is_read==0)
            {
                printf("%s|.\n", ptr->word);
            }
            else
            {
                printf("%s.\n", ptr->word);
            }
        }
    }
    }
    else
        printf("          end of sequence. Please, set pointer in begining\n");
}

void mainMenu()
{
    short int choice;

    while (choice != 2) {
        printf("        Привет, Пользователь!\n\n");
        printf("Начать работу с последовательностью-(L1)-( 1 )\n");
        printf("Выход------------------------------------( 2 )\n\n");
        printf("Ващ выбор: ");
        scanf("%d", &choice);
        while (choice > 2 || choice < 1) {
            printf("Постарайтесь больше не делать ошибок: ");
            scanf("%d", &choice);
        }

        switch (choice){
        case 1: {
            system("cls");
            menu();
            break;
        }
        case 2: {

            exit(0);
        }
        }
    }
}

void menu()
{
    short int choice;

    while(choice!=11)
    {
        system("cls");
        printf("\n          Welcome to Text Sequence!\n\n");
        wordsList();
        printf(">Make the sequence empty-------------------( 1 )\n"); //Сделать посдедовательность пустой
        printf(">Is the Sequence empty?--------------------( 2 )\n"); //Проверка: Посдедовательность пуста?
        printf(">Show item value---------------------------( 3 )\n"); //Показать значение очередного элемента
        printf(">Skip item---------------------------------( 4 )\n"); //Пропустить очередной элемент посдедовательности
        printf(">Read item---------------------------------( 5 )\n"); //Прочитать очередной элемент последовательности
        printf(">Change the value of an element------------( 6 )\n"); //Изменить значение очередного элемента
        printf(">Add an element to the end of the sequence-( 7 )\n"); //Добавить элемент в конец последовательности
        printf(">Set the pointer to the end of the sequence( 8 )\n"); //Установить указатель в конец последовательности
        printf(">Are there any unread items?---------------( 9 )\n"); //Проверка: есть ли непрочитанные элементы
        printf(">Output the Sequence-----------------------( 10 )\n"); //Распечатать структуру данных
        printf(">Quit--------------------------------------( 11 )\n");
        printf(">Set pointer in begining-------------------( 12 )\n");
        //Закончить работу с последовательностью
        printf("Your choice: ");
        scanf("%d", &choice);
        while (choice > 12 || choice < 1) {
            printf("Make your choice again rightly: ");
            scanf("%d", &choice);
        }

        switch (choice){
        case 1: {
            if(endofsequence==0)
            {
            system("cls");
            makeSequenceEmpty();
            break;
        }
            else
            {
                system("cls");
                printf("end of sequence");
                getch();
                        break;
            }
        }
        case 2: {
            if(endofsequence==0)
            {
            system("cls");
            checkSequenceList();
            break;
            }
            else
            {
                system("cls");
                printf("end of sequence");
                getch();
                        break;
            }
        }
        case 3: {
            if(endofsequence==0)
            {
            system("cls");
            showSequenceElement();
            break;
            }
            else
            {
                system("cls");
                printf("end of sequence");
                getch();
                        break;
            }
        }
        case 4: {
            
            system("cls");
            if(endofsequence==0)
            {
            if (firstPointer == NULL) {
                printf("\n      Now sequence is empty!\n");
                printf("\nPush any key to back to menu\n");
                getch();
            }
            else {
                if(endofsequence==1)
                {
                    system("cls");
                    printf("end of sequence. U cant move");
                    getch();
                }
                            else
                {
                if (pointer->nextPointer == NULL) {
                    endofsequence=1;
                    printf("This is the last element of sequence!\n");
                    
                    if(ReadBalance==0)
                        printf("We haven't unreaded elements");
                    else
                        printf("We have %d unreaded elements", ReadBalance);
                    printf("\nPush any key to back to menu\n");
                    getch();
                }
                else skipSequenceItem();
                    }
            }
            break;
        }
            else
            {
                system("cls");
                printf("end of sequence");
                getch();
                break;
            }
        }
        case 5: {
            system("cls");
            if(endofsequence==0)
            {
            if (firstPointer == NULL) {
                printf("\n      Now sequence is empty!\n");
                printf("\nPush any key to back to menu\n");
                getch();
            }
            else {
                showSequenceElement();
                skipSequenceItem();
            }
            break;
            }
            else
            {
                system("cls");
                printf("end of sequence");
                getch();
                break;
            }
        }
        case 6: {
            system("cls");
            if(endofsequence==0)
            {
            changeElement();
            break;
            }
            else
            {
                system("cls");
                printf("end of sequence");
                getch();
                        break;
            }
        }
        case 7: {
            system("cls");
            if(endofsequence==0)
            {
            addLastElement();
            break;
            }
            else
            {
                system("cls");
                printf("end of sequence");
                getch();
                        break;
            }
        }
        case 8: {
            system("cls");
            if(endofsequence==0)
            {
            setEndSequencePtr();
            break;
            }
            else
            {
                system("cls");
                printf("end of sequence");
                getch();
                        break;
            }
        }
        case 9: {
            system("cls");
            if(endofsequence==0)
            {
            checkUnread();
            break;
            }
            else
            {
                system("cls");
                printf("end of sequence");
                getch();
                        break;
            }
        }
        case 10: {
            system("cls");
            if(endofsequence==0)
            {
            outputSequence();
            break;
            }
            else
            {
                system("cls");
                printf("end of sequence");
                getch();
                break;
            }
        }
        case 11: {
            system("cls");
            mainMenu();
            break;
        }
        case 12:
        {
            system("cls");
            setBeginSequencePtr();
            break;
        }
        }
    }


}
void checkUnread()
{
    if (firstPointer == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else
        if(ReadBalance==0)
        {
            printf("We haven't unreaded elements");
            getch();
        }
        else
        {
            printf("We have %d unreaded elements", ReadBalance);
            printf("\nPush any key to back to menu\n");
            getch();
        }
}

void makeSequenceEmpty()
{
    {
        if (firstPointer == NULL) {
            printf("\n      Now sequence is empty!\n");
            printf("\nPush any key to back to menu\n");
            getch();
        }

        else {
            struct elementWord *toDelete, *flag;
            if (firstPointer->nextPointer != NULL) {
                flag = firstPointer->nextPointer;
                while (flag->nextPointer != NULL) {
                    toDelete = flag;
                    free(toDelete);
                    flag = flag->nextPointer;
                }
                free(toDelete);
                free(firstPointer);
                firstPointer = NULL;
                pointer = NULL;
            }
            else {
                free(firstPointer);
                firstPointer = NULL;
                pointer = NULL;
            }
            ReadBalance=0;
            printf("\n      Now sequence is empty!\n");
            printf("\nPush any key to back to menu\n");
            getch();
        }
    }
}

void checkSequenceList()
{
    if (firstPointer == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else {
        printf("\nThe sequence is not empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }
}

void skipSequenceItem()
{
    if (firstPointer == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else
    {
        if(endofsequence==1)
        {
            printf("end of sequence. U cant move");
            getch();
        }
                    else
    {
        if (pointer->nextPointer == NULL)
        {endofsequence=1;
            
            printf("\n      End of sequence\n");
            
            if(ReadBalance==0)
                printf("We haven't unreaded elements");
            else
                printf("We have %d unreaded elements", ReadBalance);
            printf("\nPush any key to back to menu\n");
            getch();
        }
        else

        {
            pointer = pointer->nextPointer;
        }
    }
    }
}

void addLastElement()
{
    struct elementWord *newWord, *ptr;
    char *word;

    if (firstPointer == NULL) {
        newWord = (struct elementWord*)malloc(sizeof(struct elementWord));
        if(!newWord)
        {
           printf("error with memory");
           getch();
        }
        else
        {
        word = (char*)calloc(10, sizeof(char));
        newWord->word = word;
        newWord->is_read = 0;
        ReadBalance++;
        printf("Enter the word: ");
        scanf("%s", word);
        newWord->nextPointer = NULL;
        firstPointer = newWord;
        pointer = firstPointer;
    }
    }

    else {
        ptr = firstPointer;
        while (ptr->nextPointer != NULL) ptr = ptr->nextPointer;
        newWord = (struct elementWord*)malloc(sizeof(struct elementWord));
        if(!newWord)
        {
           printf("error with memory");
           getch();

        }
        else
        {
        word = (char*)calloc(10, sizeof(char));
        newWord->word = word;
        newWord->is_read = 0;
        ReadBalance++;
        printf("Enter the word: ");
        scanf("%s", word);
        newWord->nextPointer = NULL;
        ptr->nextPointer = newWord;
    }
    }
}

void showSequenceElement()
{
    if (firstPointer == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else {
        if (pointer->is_read==0) {//если не был прочитан
            ReadBalance--;
            pointer->is_read=1;
            printf ("Prochitan element %s \n", pointer->word);
        } else {
            if (ReadBalance==0) {
                printf ("Neprochitanih elementov net\n");
            }else{
                printf ("Element %s uge prochitan \n", pointer->word);
            }
        }
        if (pointer->nextPointer==NULL)
         {
            printf("Vi nahodites v konce posledovatelnosti, dvijenie ne vozmojno\n");

        }
        printf("\nPush any key to back to menu\n");
        getch();
    }
}



void changeElement()
{
    if (firstPointer == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else {
        if(pointer->is_read==1)
            ReadBalance++;
        printf("Enter the word: ");
        scanf("%s", pointer->word);
        pointer->is_read=0;

        printf("\nPush any key to back to menu\n");
        getch();
    }
}

void setEndSequencePtr()
{
    if (firstPointer == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else while (pointer->nextPointer != NULL)
    {
        pointer = pointer->nextPointer;

}
}

void outputSequence()
{
    if (firstPointer == NULL) {
        printf("\nThe sequence is empty!\n");
        printf("\nPush any key to back to menu\n");
        getch();
    }

    else {
        struct elementWord *ptr;
        ptr = firstPointer;
        printf("\nWords sequence: ");
        while (ptr->nextPointer != NULL)
        {
            if(ptr->is_read==0)
            {
                printf("%s|,", ptr->word);
            }
            else
            {
                printf("%s,", ptr->word);

            }
            ptr = ptr->nextPointer;
        }
        if(ptr->is_read==0)
        {
            printf("%s|.\n", ptr->word);
            printf("\nPush any key to back to menu\n");
            getch();
        }
        else
        {
            printf("%s.\n", ptr->word);
            printf("\nPush any key to back to menu\n");
            getch();
        }
    }
}

void setBeginSequencePtr()
{
if (firstPointer == NULL) {
    printf("\n      Now sequence is empty!\n");
    printf("\nPush any key to back to menu\n");
    getch();
}
else
{
pointer = firstPointer;
ReadBalance=0;
while (pointer->nextPointer != NULL)
    {

        pointer ->is_read=0;
        ReadBalance++;
        pointer = pointer->nextPointer;

}
if(pointer->nextPointer == NULL)
    {

        pointer ->is_read=0;
        ReadBalance++;


}
pointer = firstPointer;
endofsequence=0;
printf("\n      Pointer has replaced on begin of sequence\n");
printf("\nPush any key to back to menu\n");
getch();
}
}

/*if (pointer->nextPointer != NULL) skipSequenceItem();
else if (pointer->nextPointer == NULL) {
    pointer = firstPointer;
    printf("\n      End of sequence\n");
    printf("\n      Pointer has replaced on begin of sequence\n");
    if(ReadBalance==0)
        printf("We haven't unreaded elements");
                else
                printf("We have %d unreaded elements", ReadBalance);
    printf("\nPush any key to back to menu\n");
    getch();

{
    Element *elem = (Element *)malloc(sizeof(Element));//Выделение памяти
    if (!elem) {//Если не удалось выделить память
        return -1;
    }
}*/
