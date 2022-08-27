      ******************************************************************
      * Author: Joel Brewer
      * Date: 8/25/2022
      * Purpose: To determine if a sentence is a pangram.
      * Tectonics: cobc
      ******************************************************************
      *
      * Create a bit string to keep track of letters that have been used
      * Iterate through each char of the sentence.
      * Convert a to 1
      * Convert A to 1
      * For each char, bit flip the corresponding bit to 1
      * Check to see if the bit string is all 1s

       IDENTIFICATION DIVISION.
       PROGRAM-ID. PANGRAM.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-SENTENCE PIC X(60).
       01 WS-RESULT PIC 9.
       01 WS-INDEX PIC 99.
       01 WS-TEMP1 PIC 999.
       01 WS-PARSED PIC X(26) VALUE '00000000000000000000000000'.
       PROCEDURE DIVISION.
           PANGRAM.
               MOVE 0 TO WS-RESULT.
               MOVE 'a quick movement of the enemy will jeopardize five
      -         'gunboats' TO WS-SENTENCE.
               MOVE FUNCTION LOWER-CASE(WS-SENTENCE) TO WS-SENTENCE.
               MOVE 1 TO WS-INDEX.
               DISPLAY "WS-SENTENCE: " WS-SENTENCE.
               PERFORM PARSE-SENTENCE UNTIL WS-INDEX > 60.
               DISPLAY "Alphabet : abcdefghijklmnopqrstuvwxyz".
               DISPLAY "WS-PARSED: " WS-PARSED.
               PERFORM CHECK-FOR-PANGRAM.
               DISPLAY "RESULT: " WS-RESULT.

           PARSE-SENTENCE.
               MOVE FUNCTION ORD(WS-SENTENCE(WS-INDEX:1)) TO WS-TEMP1.
               SUBTRACT 97 FROM WS-TEMP1 GIVING WS-TEMP1.
               IF WS-TEMP1 <= 26 THEN
                   MOVE 1 TO WS-PARSED(WS-TEMP1:1)
               END-IF
               ADD 1 TO WS-INDEX.

           CHECK-FOR-PANGRAM.
               IF WS-PARSED = '11111111111111111111111111' THEN
                   MOVE 1 TO WS-RESULT
               ELSE
                   MOVE 0 TO WS-RESULT
               END-IF.
