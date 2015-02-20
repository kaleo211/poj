#include <stdio.h>


void swap(char *input, int i, int j) {
    char s = input[i];
    input[i] = input[j];
    input[j] = s;
}

void func2(char *input) {
    int i, j;
    for (i=0; input[i]!='\0'; i++) {
        for (j=i+1; input[j]!='\0'; j++) {
            if (input[j]<input[i])
                swap(input, i, j);
        }
    }
}

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
            func2(input+position+1);
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
