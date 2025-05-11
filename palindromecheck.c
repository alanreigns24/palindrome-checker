#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    int len = strlen(str);
    printf("Reversed String: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    reverse(str);
    
    if (isPalindrome(str))
        printf("It is a palindrome.\n");
    else
        printf("It is not a palindrome.\n");

    return 0;
}
