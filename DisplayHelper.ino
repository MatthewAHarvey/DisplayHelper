#include "DisplayHelper.h"
#include "arduino.h"

uint8_t arrayLen = 8;

// DisplayHelper message2("[12345678.9]"); // 12 slots (13 to include null terminator)

void setup(){
    Serial.begin(250000);
    Serial.println("Connected to DisplayHelper.ino");
    DisplayHelper message1(arrayLen);
    Serial.print("Message1: ");
    Serial.print("[");
    Serial.print(message1.get());
    Serial.println("]");

    message1.set("Testing");
    Serial.print("Message1: ");
    Serial.print("[");
    Serial.print(message1.get());
    Serial.println("]");
    
    Serial.println(message1.update("ed.", 4));
    Serial.print("Message1: ");
    Serial.print("[");
    Serial.print(message1.get());
    Serial.println("]");

    Serial.println(message1.set("123.45"));
    Serial.print("Message1: ");
    Serial.print("[");
    Serial.print(message1.get());
    Serial.println("]");

    Serial.print("n: ");
    int n = message1.available();
    uint8_t* indices = message1.getIndices();
    char* c = message1.getChars();
    Serial.println(n);
    for(int i = 0; i < n; i++){
        Serial.print("i: ");
        Serial.print(indices[i]);
        Serial.print(", ");
        Serial.println(c[i]);    
    }
    Serial.println();

    n = message1.available();
    for(int i = 0; i < n; i++){
        int index = message1.popIndex();
        char c = message1.popChar();
        Serial.print("Index: ");
        Serial.print(index);
        Serial.print(", ");
        Serial.print("Char: ");
        Serial.println(c);
    }

    n = message1.update(543210);
    Serial.println(n);
    Serial.println(message1.get());
    for(int i = 0; i < n; i++){
        int index = message1.popIndex();
        char c = message1.popChar();
        Serial.print("Index: ");
        Serial.print(index);
        Serial.print(", ");
        Serial.print("Char: ");
        Serial.println(c);
    }

    // Serial.print("Message1: ");
    // Serial.print(message1.getIndices());

}

void loop(){
    
}