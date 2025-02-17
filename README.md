# Cyber-Project-1

* Ask user for password to encrpyt and decrpyt
* Password needs to be at least 8 characters long, no spaces
* The program then uses the 8th character in the password to adjust the new alphabet 
* Only characters from ascii decimal 32 (space) to 126 (~)
* The 8th character of the password is now made the space and the rest of the characters are shifted accordingly
* The password is then also hashed with this new alphabet and is placed at the bottom of the file
* To then decrpyt the file, you just need to enter the correct password, which matches the hashing at the bottom

* Possible password: WindRunner
* 8th character is n
* n is now space
* Password hashed is: i{ vd)  w&
