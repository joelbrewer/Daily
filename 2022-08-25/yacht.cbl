      ******************************************************************
      * Author: Joel Brewer
      * Date: 8/25/2022
      * Purpose: To print the score of a yacht roll
      * Tectonics: cobc
      ******************************************************************
       IDENTIFICATION DIVISION.
       PROGRAM-ID. YACHT.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-RESULT PIC 99 VALUE 0.
       01 WS-CATEGORY PIC X(15).
       01 WS-DICE PIC 9(5).
       01 WS-DICE-PARSED.
           03 DICE-COUNTS PIC 9 VALUE 0 OCCURS 6 TIMES.
       01 WS-DICE-INDEX PIC 9(01).
       01 WS-CURRENT-DIE PIC 9(01).
       01 WS-DICE-STRING PIC X(5).
       01 WS-DIE-TO-SUM PIC 9 VALUE 0.
       01 WS-VALID-ROLL PIC 9 VALUE 0.
       01 WS-FH-SM PIC 9 VALUE 0.
       01 WS-FH-LG PIC 9 VALUE 0.
       01 WS-TEMP-SUM PIC 99 VALUE 0.

       PROCEDURE DIVISION.
           PERFORM MAIN.
           STOP RUN.

       MAIN.
           MOVE 55555 TO WS-DICE.
           MOVE 'yacht' TO WS-CATEGORY.
           DISPLAY "001-Main".
           PERFORM PARSE-DICE.
           PERFORM GET-SCORE.
           DISPLAY "SCORE: " WS-RESULT.
       MAIN-EXIT.

       PARSE-DICE.
      * Loop trough WS-DICE
           MOVE WS-DICE TO WS-DICE-STRING.
           MOVE 1 TO WS-DICE-INDEX.
      * Iteratively increment values in WS-DICE-TABLE
           PERFORM PARSE-DIE UNTIL WS-DICE-INDEX > 5.
      * Print table
           DISPLAY "PARSED DICE: " WS-DICE-PARSED.
       PARSE-DICE-EXIT.

       PARSE-DIE.
      * Get current dice value
           DISPLAY "DICE VALUE: " WS-DICE-STRING(WS-DICE-INDEX:1).
           MOVE WS-DICE-STRING(WS-DICE-INDEX:1) TO WS-CURRENT-DIE.
      * Increment table at index of the current dice value
           ADD 1 TO DICE-COUNTS(WS-CURRENT-DIE).
           ADD 1 TO WS-DICE-INDEX.
       PARSE-DIE-EXIT.

       GET-SCORE.
           MOVE 1 TO WS-DICE-INDEX.
           EVALUATE WS-CATEGORY
           WHEN "yacht"
               PERFORM CHECK-YACHT UNTIL WS-DICE-INDEX > 6
           WHEN "ones"
               MOVE 1 TO WS-DIE-TO-SUM
               PERFORM SUM-DIE
           WHEN "twos"
               MOVE 2 TO WS-DIE-TO-SUM
               PERFORM SUM-DIE
           WHEN "threes"
               MOVE 3 TO WS-DIE-TO-SUM
               PERFORM SUM-DIE
           WHEN "fours"
               MOVE 4 TO WS-DIE-TO-SUM
               PERFORM SUM-DIE
           WHEN "fives"
               MOVE 5 TO WS-DIE-TO-SUM
               PERFORM SUM-DIE
           WHEN "sixes"
              MOVE 6 TO WS-DIE-TO-SUM
              PERFORM SUM-DIE
           WHEN "full house"
               PERFORM CHECK-FULL-HOUSE UNTIL WS-DICE-INDEX > 6
               IF (WS-FH-SM = 1) AND (WS-FH-LG = 1) THEN
                   DISPLAY "WE HAVE A FULL HOUSE"
                   MOVE 1 TO WS-DICE-INDEX
                   PERFORM SUM-ALL-DICE UNTIL WS-DICE-INDEX > 6
               END-IF
           WHEN "four of a kind"
               PERFORM CHECK-FOUR-OF-A-KIND UNTIL WS-DICE-INDEX > 6
           WHEN "little straight"
               IF WS-DICE = 12345 THEN
                   DISPLAY "WE HAVE A LITTLE STRAIGHT"
                   MOVE 30 TO WS-RESULT
               END-IF
           WHEN "big straight"
               IF WS-DICE = 23456 THEN
                   DISPLAY "WE HAVE A BIG STRAIGHT"
                   MOVE 30 TO WS-RESULT
               END-IF
           WHEN "choice"
               MOVE 1 TO WS-DICE-INDEX
               PERFORM SUM-ALL-DICE UNTIL WS-DICE-INDEX > 6
           WHEN OTHER
             MOVE 0 TO WS-RESULT
           END-EVALUATE.
       GET-SCORE-EXIT.

       CHECK-YACHT.
      * Iterate through table and see if there is a value of 5
      * Check if current dice num is equal to 5
           IF DICE-COUNTS(WS-DICE-INDEX) = 5 THEN
               MOVE 7 TO WS-DICE-INDEX
               MOVE 50 TO WS-RESULT
           ELSE
               ADD 1 TO WS-DICE-INDEX
           END-IF.
       CHECK-YACHT-EXIT.

       CHECK-FOUR-OF-A-KIND.
           DISPLAY "CHECK-FOUR-OF-A-KIND"
      * Iterate through table and see if there is a value of 5
      * Check if current dice num is equal to 5
           IF DICE-COUNTS(WS-DICE-INDEX) = 4 THEN
               MOVE 1 TO WS-DICE-INDEX
               PERFORM SUM-ALL-DICE UNTIL WS-DICE-INDEX > 6
               MOVE 7 TO WS-DICE-INDEX
           ELSE
               ADD 1 TO WS-DICE-INDEX
           END-IF.
       CHECK-FOUR-OF-A-KIND-EXIT.

       SUM-DIE.
           MULTIPLY DICE-COUNTS(WS-DIE-TO-SUM) BY WS-DIE-TO-SUM GIVING
           WS-RESULT.
       SUM-DIE-EXIT.

       SUM-ALL-DICE.
           MULTIPLY DICE-COUNTS(WS-DICE-INDEX) BY WS-DICE-INDEX GIVING
           WS-TEMP-SUM.
           ADD WS-TEMP-SUM TO WS-RESULT.
           ADD 1 TO WS-DICE-INDEX.
       SUM-ALL-DICE-EXIT.

       CHECK-FULL-HOUSE.
           IF DICE-COUNTS(WS-DICE-INDEX) = 3 THEN
               MOVE 1 TO WS-FH-LG
           END-IF.

           IF DICE-COUNTS(WS-DICE-INDEX) = 2 THEN
               MOVE 1 TO WS-FH-SM
           END-IF.
           ADD 1 TO WS-DICE-INDEX.
       CHECK-FULL-HOUSE-EXIT.
       YACHT.
