
char getRandomUpperCaseLetter()
{  srand((unsigned int)rand(0));
    char v;
     v=rand()%26+65; 
    return v;
}
char getRandomLowerCaseLetter()
{  srand((unsigned int)rand(0));
    char v;
     v=rand()%26+97; 
    return v;
}
char getRandomDigitCharacter()
{  srand((unsigned int)rand(0));
    char v;
     v=rand()%10+48; 
    return v;
}
char getRandomCharacter()
{   srand((unsigned int)rand(0));
    char v;
     v=rand()%95+32; 
    return v;

}