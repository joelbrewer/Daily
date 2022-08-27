      ******************************************************************
      * Author: Joel Brewer
      * Date: 8/25/2022
      * Purpose: To determine if a sentence is a pangram.
      * Tectonics: cobc
      ******************************************************************
      *
      * Create a string to keep track of letters that have been used
      * Iterate through each char of the sentence.
      * For each char, increment the corresponding char.
      * Check to see if the string has any chars greater than 1.

       IDENTIFICATION DIVISION.
       PROGRAM-ID. ISOGRAM.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-PHRASE PIC X(60).
       01 WS-RESULT PIC 99.
       01 WS-INDEX PIC 99.
       01 WS-TEMP1 PIC 999.
       01 WS-TEMP2 PIC 9.
       01 WS-PARSED PIC X(26) VALUE '00000000000000000000000000'.
       PROCEDURE DIVISION.
           ISOGRAM.
               MOVE 1 TO WS-RESULT.
               MOVE 'subdermatoglyphic' TO WS-PHRASE
               MOVE FUNCTION LOWER-CASE(WS-PHRASE) TO WS-PHRASE.
               MOVE 1 TO WS-INDEX.
               PERFORM PARSE-PHRASE UNTIL WS-INDEX > 60.
               MOVE 1 TO WS-INDEX.
               PERFORM CHECK-FOR-ISOGRAM UNTIL WS-INDEX > 26.
               DISPLAY "RESULT: " WS-RESULT.

           PARSE-PHRASE.
               MOVE FUNCTION ORD(WS-PHRASE(WS-INDEX:1)) TO WS-TEMP1.
               SUBTRACT 97 FROM WS-TEMP1 GIVING WS-TEMP1.
               IF WS-TEMP1 <= 26 THEN
                   MOVE WS-PARSED(WS-TEMP1:1) TO WS-TEMP2
                   ADD 1 TO WS-TEMP2
                   MOVE WS-TEMP2 TO WS-PARSED(WS-TEMP1:1)
               END-IF.
               ADD 1 TO WS-INDEX.

           CHECK-FOR-ISOGRAM.
               IF WS-PARSED(WS-INDEX:1) > 1 THEN
                 MOVE 27 TO WS-INDEX
                 MOVE 0 TO WS-RESULT
               END-IF.
               ADD 1 TO WS-INDEX.
