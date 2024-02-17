#include <stdio.h>
#include <string.h>

void caesar_cipher(char *text, int key, int choice) {
  int length = strlen(text);
  for (int i = 0; i < length; i++) {
    char current_char = text[i];
    if (current_char >= 'a' && current_char <= 'z') {
      if (choice == 0) {
        current_char = (current_char - 'a' + key) % 26 + 'a';
      } else {
        current_char = (current_char - 'a' - key + 26) % 26 + 'a';
      }
    } else if (current_char >= 'A' && current_char <= 'Z') {
      if (choice == 0) {
        current_char = (current_char - 'A' + key) % 26 + 'A';
      } else {
        current_char = (current_char - 'A' - key + 26) % 26 + 'A';
      }
    }
    text[i] = current_char;
  }
}

int main() {
  char message[100];
  int key, choice;

  scanf("%s", message);
  scanf("%d", &key);
  scanf("%d", &choice);

  caesar_cipher(message, key, choice);

  printf("%s", message);

  return 0;
}