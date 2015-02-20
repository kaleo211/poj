#include <stdio.h>



int func(char *input, int length) {
        char tail = input[length-1];
        int    flag = 0, position = -1, i;

        for (i=length-2; i>=0; i--) {
            if (input[i]<tail) {
                flag = 1;
                position = i;
                break;
            }
        }

        if (flag) {
            for (i=length-1; i>position; i--) {
                input[i] = input[i-1];
            }
            input[position] = tail;
            return 1;

        } else {
            return 0;
        }
}

int main() {
    char input[51];

    while (1) {
        scanf("%s", input);

        int i=0;
        while (input[i]!='\0') {i+=1;}
        int length = i;

        if (length==0 || input[0]=='#')
            break;

        if (length==1) {
            printf("No Successor\n");

        } else {
            int result = 0;
            for (i=length; i>1; i--) {
                result = func(input, i);
                if (result) break;
            }
            if (result) {
                printf("%s\n", input);
            } else {
                printf("No Successor\n");
            }
        }
    }
}
