      ******************************************************************
      * Author: Joel Brewer
      * Date: 8/25/2022
      * Purpose: To create an implementation of the Rotaional Cipher
      * Tectonics: cobc
      ******************************************************************
      *
      * Create a string to keep track of letters that have been used
      * Iterate through each char of the sentence.
      * For each char, increment the corresponding char.
      * Check to see if the string has any chars greater than 1.
       IDENTIFICATION DIVISION.
       PROGRAM-ID. rotational-cipher.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-KEY PIC 9(2).
       01 WS-TEXT PIC X(128).
       01 WS-CIPHER PIC X(128).

       PROCEDURE DIVISION.
       ROTATIONAL-CIPHER.

