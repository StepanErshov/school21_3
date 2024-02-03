#include <math.h>
#include <stdio.h>

void encodeToHex(char ch) {
  int firstDigit = ch / 16;
  int secondDigit = ch % 16;
  printf("%X%X ", firstDigit, secondDigit);
}

void decodeFromHex(char firstDigit, char secondDigit) {
  int num = 0;
  if (firstDigit >= '0' && firstDigit <= '9') {
    num += (firstDigit - '0') * 16;
  } else if (firstDigit >= 'A' && firstDigit <= 'F') {
    num += (firstDigit - 'A' + 10) * 16;
  }
  if (secondDigit >= '0' && secondDigit <= '9') {
    num += (secondDigit - '0');
  } else if (secondDigit >= 'A' && secondDigit <= 'F') {
    num += (secondDigit - 'A' + 10);
  }
  printf("%c ", num);
}

int main() {
  int choice;
  char ch;

  printf("Terminal arguments(0 or 1): ");
  scanf(" %d", &choice);

  if (choice == 0) {
    printf("Enter the text to encode: ");
    while (scanf(" %c", &ch) == 1 && ch != '\n') {
      encodeToHex(ch);
    }
  } else if (choice == 1) {
    printf("Enter the hexadecimal string to decode: ");
    char first, second;
    while (scanf(" %c%c", &first, &second) == 2 && ch != '\n') {
      decodeFromHex(first, second);
    }
  } else {
    printf("Invalid choice\n");
    return 1;
  }

  return 0;
}