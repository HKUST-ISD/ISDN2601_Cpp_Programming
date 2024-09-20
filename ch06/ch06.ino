#include "Arduino.h"
 
void setup(){

}

struct Person {
  char name[50];
  int age;
  float height;
};
 
void loop() {
  // Basic data types
  char character = 'A';
  int integer = 42;
  long longInteger = 1234567890L;
  float floatNumber = 3.14159;
  double doubleNumber = 2.718281828459045;
  bool boolean = true;
  
  // String
  String message = "Hello, World!";
  
  // Array
  int numbers[] = {1, 2, 3, 4, 5};
  
  // Custom structure
  Person person = {"John Doe", 30, 1.75};
  
  // Printing different types of values
  Serial.println("\n--- Printing Different Types ---");
  Serial.print("Character: ");
  Serial.println(character);
  
  Serial.print("Integer: ");
  Serial.println(integer);
  
  Serial.print("Long Integer: ");
  Serial.println(longInteger);
  
  Serial.print("Float: ");
  Serial.println(floatNumber, 6);  // 6 decimal places
  
  Serial.print("Double: ");
  Serial.println(doubleNumber, 10);  // 10 decimal places
  
  Serial.print("Boolean: ");
  Serial.println(boolean ? "true" : "false");
  
  Serial.print("String: ");
  Serial.println(message);
  
  // Printing array
  Serial.println("\n--- Printing Array ---");
  for (int i = 0; i < 5; i++) {
    Serial.print("numbers[");
    Serial.print(i);
    Serial.print("] = ");
    Serial.println(numbers[i]);
  }
  
  // Printing custom structure
  Serial.println("\n--- Printing Custom Structure ---");
  Serial.print("Name: ");
  Serial.println(person.name);
  Serial.print("Age: ");
  Serial.println(person.age);
  Serial.print("Height: ");
  Serial.println(person.height, 2);  // 2 decimal places
  
  // Formatted output
  Serial.println("\n--- Formatted Output ---");
  char buffer[100];
  snprintf(buffer, sizeof(buffer), 
           "Person: %s, Age: %d, Height: %.2f m", 
           person.name, person.age, person.height);
  Serial.println(buffer);
  
  // Tabular output
  Serial.println("\n--- Tabular Output ---");
  Serial.println("| Type    | Value          |");
  Serial.println("|---------|----------------|");
  snprintf(buffer, sizeof(buffer), "| Char    | %-14c |", character);
  Serial.println(buffer);
  snprintf(buffer, sizeof(buffer), "| Int     | %-14d |", integer);
  Serial.println(buffer);
  snprintf(buffer, sizeof(buffer), "| Float   | %-14.2f |", floatNumber);
  Serial.println(buffer);
  snprintf(buffer, sizeof(buffer), "| Boolean | %-14s |", boolean ? "true" : "false");
  Serial.println(buffer);
  
  // Hexadecimal and binary output
  Serial.println("\n--- Hexadecimal and Binary Output ---");
  Serial.print("42 in hexadecimal: 0x");
  Serial.println(integer, HEX);
  Serial.print("42 in binary: 0b");
  Serial.println(integer, BIN);
  
  // Add a longer delay to make the output more readable
  delay(5000);  // Wait for 5 seconds before the next iteration
}