 #include  <stdlib.h>
#include <stdio.h>
#include <ctype.h>


struct Node{
    struct Node * Next;
    struct Node*nodeDoulbe;

};
struct nodeDoulbe{
    int data;
    struct nodeDoulbe*prev;
    struct nodeDoulbe*next;
};
struct nodeDoulbe* re (struct nodeDoulbe*h){
    struct nodeDoulbe * re = h ;
    struct nodeDoulbe*next=NULL;
    struct nodeDoulbe*prev = NULL;


    while (re!= NULL){
        next=re->next;
        re->next=prev;
        re->prev=next;
        prev=re;
        re=next;

    }
    if (prev!=NULL){
        h=prev;
        prev->prev=h;

        if (h->data < 0){

            h->data=-(h->data);
        }
    }
    return h;

}
void printlist(struct nodeDoulbe*h){

    struct nodeDoulbe* p =h;


    while (p!=NULL && p->data==0) {
        p = p->next;
    }

    if (p!=NULL){
        printf("%d",p->data);
        p=p->next;


    }
    while (p!=NULL){

        printf("%d",p->data);
        p=p->next;

    }


    printf("\n");

}


struct nodeDoulbe*add(struct nodeDoulbe*List1,struct nodeDoulbe*list2){
    struct nodeDoulbe*result=NULL;
    struct nodeDoulbe*L1=List1;
    struct nodeDoulbe*L2=list2;
    struct nodeDoulbe*t = NULL;
    int carry;

    while (L1!=NULL&&L2!=NULL){
        int sum = carry;

        if (L1!=NULL){
            sum += L1->data;
            L1=L1->next;




        }if(L2!=NULL){

            sum+=L2->data;
            L2=L2->next;

        }

        carry=sum/10;
        sum=sum%10;

        struct nodeDoulbe*new = (struct nodeDoulbe*) malloc(sizeof (struct nodeDoulbe));
        new->data=sum;
        new->next=NULL;
        if (result == NULL){

            result=new;
            t=new;

        } else{

            t->next=new;
            new->prev=t;
            t=new;

        }
    }
    if (carry !=NULL) {
        struct nodeDoulbe *new = (struct nodeDoulbe *) malloc(sizeof(struct nodeDoulbe));
        new->data = carry;
        new->next = NULL;
        t->next = new;
        new->prev = t;
    }

    return result;

}
int getleght(struct nodeDoulbe*l){
    int leght = 0 ;
    struct nodeDoulbe* g = l;
    while (g!=NULL){
        leght++;
        g=g->next;


    }
    return leght;



}
int compar(struct nodeDoulbe*list1,struct nodeDoulbe*list2){

    if (list1==NULL &&list2==NULL){

        return 0;
    }
    if ( list1==NULL){

        return -1;

    }if (list2==NULL){

        return 1;

    }

    int L1= getleght(list1);
    int L2= getleght(list2);

    if (L1 >L2){

        return 1;

    }
    if (L1<L2){
        return -1;

    }

    struct nodeDoulbe*L3=list1;
    struct nodeDoulbe*L4=list2;

    while (L3!=NULL && L4!=NULL){
        if (L3->data > L4->data){
            return 1;
        }
        if (L3->data < L4->data){

            return -1;
        }
        L3=L3->next;
        L4=L4->next;

    }
    return 0;

}
struct nodeDoulbe*sub(struct nodeDoulbe*list1,struct nodeDoulbe*list2){
    struct nodeDoulbe*result =NULL;
    struct nodeDoulbe*max=NULL;
    struct nodeDoulbe*min = NULL;
    struct nodeDoulbe*t = NULL;

    int carry =0;

    int x = compar(list1,list2);
    if (x==1){
        max=list1;
        min =list2;


    } else{
        max = list2;
        min = list1;

    }


    while (max !=NULL ||min !=NULL){



        int diff = carry;

        if (min->next==NULL){
            diff-=10;

        }

        if (max!=NULL){
            diff+= max->data;
            max=max->next;



        }
        if (min !=NULL){
            diff-= min->data;
            min=min->next;


        }
        if (diff < 0 ){
            carry = -1 ;
            diff+=10;


        } else{

            carry=0;

        }



        struct nodeDoulbe* new  = (struct nodeDoulbe*)malloc(sizeof(struct nodeDoulbe));
        new->data = diff;
        new->next = NULL;

        if (result == NULL) {
            result = new;
            t = new;


        } else {
            t->next = new;
            new->prev = t;
            t = new;
        }

    }

    while (t!=NULL && t->data==0){

        struct nodeDoulbe*new = t->prev;
        free(t);

        t=new;
        if (t!=NULL){

            t->next=NULL;
        }



    }





    return result;



}

void creaet(int data, struct nodeDoulbe* head) {
    struct nodeDoulbe* new_node = (struct nodeDoulbe*)malloc(sizeof(struct nodeDoulbe));

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;



    if (head->next == NULL) {
        head->next = new_node;
        new_node->prev = head;


    } else {
        struct  nodeDoulbe *current = head->next;
        while (current->next != NULL) {
            current = current->next;


        }
        current->next = new_node;
        new_node->prev = current;

        head->next->prev = NULL;
    }
}

struct nodeDoulbe* find_last(struct nodeDoulbe* head) {
    if (head == NULL)
        return NULL;

    struct nodeDoulbe* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    return current;
}
struct nodeDoulbe* createNode(int data)
{
    struct nodeDoulbe* newNode = malloc(sizeof(struct nodeDoulbe));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}



struct nodeDoulbe* multiply(struct nodeDoulbe* list1, struct nodeDoulbe* list2) {
    struct nodeDoulbe* result = NULL;
    struct nodeDoulbe* num1 = find_last(list1);
    struct nodeDoulbe* num2 = NULL;
    struct nodeDoulbe* temp_result = NULL;
    int carry = 0;
    int position = 0;

    if (list1 == NULL || list2 == NULL) {
        return NULL;
    }



    while (num1!=NULL && num1->data==0){

        struct nodeDoulbe*new = num1->prev;
        free(num1);

        num1=new;
        if (num1!=NULL){

            num1->next=NULL;
        }



    }

    while (num2!=NULL && num2->data==0){

        struct nodeDoulbe*new = num2->prev;
        free(num2);

        num2=new;
        if (num2!=NULL){

            num2->next=NULL;
        }



    }


    while (num1 != NULL) {
        num2 = find_last(list2);
        carry = 0;
        int i;

        for (i = 0; i < position; i++) {
            struct nodeDoulbe* zero = createNode(0);

            if (temp_result == NULL) {
                result = zero;
                temp_result = result;
            } else {
                temp_result->next = zero;
                zero->prev = temp_result;
                temp_result = zero;
            }
        }

        while (num2 != NULL) {
            int product = (num1->data) * (num2->data) + carry;
            carry = product / 10;
            product %= 10;

            struct nodeDoulbe* new_node = createNode(product);

            if (temp_result == NULL) {
                temp_result = new_node;
                result = temp_result;
            } else {
                temp_result->next = new_node;
                new_node->prev = temp_result;
                temp_result = new_node;
            }

            num2 = num2->prev;
        }

        if (carry > 0) {
            struct nodeDoulbe* carry_node = createNode(carry);

            temp_result->next = carry_node;
            carry_node->prev = temp_result;
            temp_result = carry_node;
        }

        num1 = num1->prev;
        position++;

        while (temp_result != NULL && temp_result->data == 0) {
            struct nodeDoulbe* prev_node = temp_result->prev;
            free(temp_result);
            temp_result = prev_node;
            if (temp_result != NULL) {
                temp_result->next = NULL;
            }
        }
    }
    result = re(result);

    return result;
}

struct nodeDoulbe* divideLists(struct nodeDoulbe* dividend, struct nodeDoulbe* divisor, int** remainder) {
    struct nodeDoulbe* result = NULL;
    struct nodeDoulbe* current = NULL;
    struct nodeDoulbe* tempDividend = NULL;
    struct nodeDoulbe* tempRemainder = NULL;


    struct nodeDoulbe* dividendPtr = dividend;
    while (dividendPtr != NULL) {
        creaet(dividendPtr->data,&tempDividend );
        dividendPtr = dividendPtr->next;
    }


    while (tempDividend != NULL) {
        int quotient = 0;

        while (tempDividend != NULL && compar(tempDividend, divisor) >= 0) {
            int dividendDigit = tempDividend->data;

            if (quotient != 0) {
                creaet(quotient,&result);
                quotient = 0;
            }

            quotient *= 10;
            quotient += dividendDigit;
            (&result, 0);

            tempDividend = tempDividend->next;
        }

        if (tempDividend == NULL) {
            break;
        }

        int dividendDigit = tempDividend->data;

        if (quotient != 0) {
            creaet(quotient,&result );
            quotient = 0;
        }

        quotient *= 10;
        quotient += dividendDigit;
        creaet(  quotient / divisor->data,&result);
        quotient = quotient % divisor->data;

        tempDividend = tempDividend->next;
    }

    // تعيين الباقي
    if (tempDividend != NULL) {
        tempRemainder = tempDividend;
    }

    *remainder = &(tempRemainder->data);
    return result;
}

void reedFile(FILE* fptr, struct nodeDoulbe* h[], int size, int max) {
    char number[1000];
    int r;
    int z = 0;

    if (fptr == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    while (fgets(number, 1000, fptr) != NULL && z < size) {
        h[z] = (struct nodeDoulbe*)malloc(sizeof(struct nodeDoulbe));
        h[z]->next = NULL;
        h[z]->prev = NULL;

        int startIndex = 0;

        if (number[0] == '-') {
            h[z]->data = -1;
            startIndex = 1;
        } else {
            h[z]->data = 0;
        }

        int numCount = 0;
        for (int i = startIndex; number[i] != '\n' && number[i] != '\0' && numCount < max; i++) {
            if (isdigit(number[i])) {
                r = number[i] - '0';
                if (!(r == 0 && numCount == 0)) {
                    creaet(r, h[z]);

                    numCount++;
                }

            }
        }

        z++;
    }

    fclose(fptr);
}


struct nodeDoulbe* remove0(struct nodeDoulbe* h) {
    struct nodeDoulbe* temp = h;


    if (temp != NULL && temp->data < 0) {
        temp->data *= -1;
    }

    return h;
}
void printFile(struct nodeDoulbe* head, const char* filename) {
    FILE* outputFile = fopen(filename, "w");
    if (outputFile == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    struct nodeDoulbe* current = head;
    while (current != NULL) {
        fprintf(outputFile, "%d", current->data);
        current = current->next;
    }
    fprintf(outputFile, "\n"); // إضافة سطر فارغ بين القوائم

    fclose(outputFile);
}
int main() {
    char name[90];
    printf("enter the name of file ;");
    scanf("%s", &name);
    FILE* file_ptr = fopen(name, "r");

    if (file_ptr == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    int maxLines = 0;
    char line[1000];

    while (fgets(line, 1000, file_ptr) != NULL) {
        maxLines++;
    }

    rewind(file_ptr);

    int size = maxLines;       // عدد المصفوفة من رؤوس القوائم المتسلسلة
    int maxElements = 5;       // الحد الأقصى لعدد الأرقام المقروءة في كل قائمة

    // إنشاء مصفوفة من رؤوس القوائم المتسلسلة
    struct nodeDoulbe* List[size];
    for (int i = 0; i < size; i++) {
        List[i] = NULL;

    }

    reedFile(file_ptr, List, size, maxElements);

    struct nodeDoulbe*L8;


    for (int i = 0; i < size; i++) {
        printf("List %d: ", i);





        printlist(List[i]);
    }





    int x ;
    while (1){
        printf("\n");
        printf("  enter  opertion  you need \n");
        printf("\n");

        printf("1_addition\n");
        printf("2_subtraction\n");
        printf("3_multiplication\n");
        printf("4_division\n");
        printf("5_exit\n");
        scanf("%d", &x);
        int i;
        int j ;
        if (x==1){


            struct nodeDoulbe* result = NULL;



            printf("enter the numper of  list  ;  ");
            scanf("%d", &i);
            printf("enter the numper of  list   ;  ");
            scanf("%d", &j);



            if (List[i]->data > 0 ){

                struct nodeDoulbe*L1= NULL;
                struct nodeDoulbe*L2=NULL;

                L2= remove0(List[j]);


                result= sub(List[i],L2);

                if (L2->data > List[i]){
                    printf("-");
                    printlist(result);
                } else {

                    printlist(result);

                }


            } else {


                result = add(List[i], List[j]);



                printlist(List[i]);
                printlist(List[j]);


                printlist(result);
            }
            int z ;

            printf("if you need save the result in file  pleas  enter 1 \n");
            printf("if you need continue pleas enter 2 \n");
            scanf("%d", &z);
            if (z==1){


                printFile(result,"output.txt");


            } else
                continue;



        } else if (x==2){

            struct node*result ;
            struct nodeDoulbe*L1= NULL;
            struct nodeDoulbe*L2=NULL;
            printf("enter numper of list  ; ");
            scanf("%d",&i);
            printf("enter numper of list  ; ");
            scanf("%d",&j);


            if (List[j]->data  <  0  ) {
                printlist(List[i]);

                printlist(List[j]);

                L1= remove0(List[j]);

                // printlist(L1);
                result= add(List[i],L1);
                //  printlist(List[i]);
                // printlist(List[j]);
                printlist(result);



            } else if (List[i]->data > 0 ){




                printlist(List[i]);
                printlist(List[j]);
                struct nodeDoulbe*L3=NULL;
                struct nodeDoulbe*L4=NULL;

                L3 = remove0(List[i]);

                result = add(L3,List[j]);
                //  L4 = addNegativeNode(result);
                printf("-");
                printlist(result);





            }



            else {
                printlist(List[i]);
                printlist(List[j]);
                result = sub(List[i], List[j]);


                printlist(result);


            }

            int z ;

            printf("if you need save the result in file  pleas  enter 1\n ");
            printf("if you need continue pleas enter 2 \n");
            scanf("%d", &z);
            if (z==1){


                printFile(result,"output.txt");
            } else
                continue;


        } else if (x==3){

            struct nodeDoulbe* result = NULL;
            struct nodeDoulbe*L1=NULL;
            struct nodeDoulbe*L2=NULL;

            printf("enter the numper of  list  ;  ");
            scanf("%d", &i);
            printf("enter the numper of  list   ;  ");
            scanf("%d", &j);


            if (List[i]->data  < 0 ) {

                printlist(List[i]);
                printlist(List[j]);
                L1 = remove0(List[i]);


                result = multiply(L1, List[j]);

                printf("-");
                printlist(result);

            } else if (List[j]->data < 0){
                printlist(List[i]);
                printlist(List[j]);
                L2= remove0(List[j]);
                result = multiply(List[i], L2);
                printf("-");
                printlist(result);


            } else {
                struct nodeDoulbe*L3=NULL;
                struct nodeDoulbe*L4=NULL;
                //L3= re(List[i]);
                //L4=re(List[j]);

                //L1= L3);
                //L2= remove0(L4);
                result = multiply(List[i], List[j]);
                printlist(List[i]);
                printlist(List[j]);
                printlist(result);
            }
            int z ;

            printf("if you need save the result in file  pleas  enter 1 \n");
            printf("if you need continue pleas enter 2 \n");
            scanf("%d", &z);
            if (z==1){
                printFile(result,"output.txt");

            } else
                continue;

        } else if (x==4){

            struct nodeDoulbe* result = NULL;


            printf("enter the numper of  list  ;  ");
            scanf("%d", &i);
            printf("enter the numper of  list   ;  ");
            scanf("%d", &j);
            int r ;
            result= divideLists(List[i],List[j],&r);

            printlist(List[i]);
            printlist(List[j]);
            printf("%d",r);
            printlist(result);
            int z ;

            printf("if you need save the result in file  pleas  enter 1 \n");
            printf("if you need continue pleas enter 2 \n");
            scanf("%d", &z);
            if (z==1){
                printFile(result,"output.txt");
            } else
                continue;

        } else {
            printf("thnek you ,I hope you like The calculator \n ");
            break;
        }


    }
    return 0;
}