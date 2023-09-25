This readme file was generated on 2023-09-23 by Brian Francis & Juan Morales-Vargas

GENERAL INFORMATION

Title:

    COP 4634 Project, Creating Your Own Shell

Description:

    Part two of a two part project to implement program myshell. This program will
    implement a simplified/basic shell that parses a command entered by the user, 
    input redirection, output redirection and background execution.

Input/Output Redirection Format Fielded:

    Program does not accept spaces after the redirect token, it must be in a 
    format of ">testfile.txt" rather than "> testfile.txt".

Project Members:

    Name:           Juan Morales-Vargas
    Institution:    University of West Florida
    Email:          jdm161@students.uwf.edu
    
    Name:           Brian Francis
    Institution:    University of West Florida
    Email:          bf15@students.uwf.edu         

FILE OVERVIEW   

    File List:
        myshell.cpp
        parse.cpp
        parse.hpp
        Makefile
        slow.c
        slow.cZone.Identifier
        README

COMPILATION

The program compiles with the -Wall flag and produces no errors or warnings.

Launch/Makefile Instructions:

    Within Bash, enter the following command after the prompt, then hit enter:

    make myshell

    Note:  Make myshell will also create an additional executable from slow.c

    after that, at the prompt, enter the following command (No Debug):

    ./myshell

    Or instead you may, at the prompt enter the following command (Debug):

    ./myshell -Debug
    
    The program will enter Debug mode; see Program Behavior, item 5 for further details.

    Once the myshell program has exited (see Supported Commands below), you may delete 
    Files created by the command *make myshell*, at the prompt enter the following command:

    make clean


Supported Commands:

ls -l                       Shows a listing of files in the current directory
ls -l >testfile.txt         Writes a listing of files into the text testfiletxt
grep -i shell testfile.txt  List many lines containing the word shell in the prev file
cat <myshell.cpp            Displays the source code of the program on the screen
cat <myshell.cpp &          As above except the output will be displayed in the background
cat testfile.txt &          Displays the content of the text file testfile.txt on screen
                            In the background.
./slow &                    Runs the program slow from the current working directory
                            In the background.
exit                        The myshell program will exit and return the user to Bash.
                             

Program Behavior:

    1. Displays a prompt, $$$, on *stdout*.
    2. Accept a command as a string from the user (input string will terminate with
       a newline character. The program will exit when the command *exit* is entered
    3. Parse the input string into tokens, which are single words delimited by one
    or more spaces, tabs or newline characters.
    4. Tokens are stored in the fields of class *Param*.
    5. While in Debug mode, entering *printParams()* will print the contents of the
       fields stored in class *Param*.
    6. Return back to step 1

Sample Run with Debug mode enabled:

    ./myshell -Debug
    $$$ one two three <four >five &
    InputRedirect: [four]
    OutputRedirect: [five]
    Background: [1]
    ArgumentCount: [3]
    ArgumentVector[0]: [one]
    ArgumentVector[1]: [two]
    ArgumentVector[2]: [three]
