      ******************************************************************
      * Author: Joel Brewer
      * Date: 8/25/2022
      * Purpose: To create an implementation of the Rotaional Cipher
      * Tectonics: cobc
      ******************************************************************
      *
      * Always capitalize
      * EG: ROT13
      * A(1) -> N(13)
      * Z(26) -> M(12)

      * 1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16
      * 13  14  15  16  17  18  19  20  21  22  23  24  25  26  1   2 
      * +12 +12                                             +12 -14 -14

      * 17  18  19  20  21  22  23  24  25  26  1   2   3   4   5   6
      * 3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18 
      * -14 -14                                                 -14 -14

      * ROT 5
      * 1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16
      * 5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20
      * +4  +4  +4  +4  +4  +4  +4  +4

      * 17  18  19  20  21  22  23  24  25  26
      * 21  22  23  24  25  26  1   2   3   4  
      *                     +4  -22 -22 -22 -22
      *
      * If plain is less than total keys - cipher rotation+1, add cipher
      * rotation - 1
      * 
      * If plain is greater than 

       IDENTIFICATION DIVISION.
       PROGRAM-ID. rotational-cipher.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-KEY PIC 9(2).
       01 WS-TEXT PIC X(128).
       01 WS-CIPHER PIC X(128).

       PROCEDURE DIVISION.
       ROTATIONAL-CIPHER.

