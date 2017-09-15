#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *x;
    int y;
} XY; /*
        Allows me to create objects of type "XY" without "struct XY".
        With this style of creating structs, it does not allow you
        to create objects within the struct declearation 
     */

typedef struct tupleAB tupleAB;  //Allows me to define the type as "tupleAB" not "struct tupleAB"

struct tupleAB{
    int *a;
    int b;
} *object1, object2; //Creates two objects



int main()
{
    int *intp = malloc(sizeof(int));
    tupleAB o1 = {intp, 5};
    object1 = &o1; //The object is created, but initially pointed to nothing
    *(object1->a) = 6;
    printf("%i %i\n", *(object1->a), object1->b);
    
    XY o2 = {intp, 2}; /*
                    You cannot create objects on struct decleration before,
                    now you have to create them
                    */
    *(o2.x) = 10; /*
                    Not a pointer to a struct.
                    (*object1).a = 6; is equivilent to object1->a = 6;
                    */
    printf("%i %i", *o2.x, o2.y);
    

    return 0;
}
