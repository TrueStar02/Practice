char * convertDecimalToHex(int value)
{   char *str=(char *)malloc(10*sizeof(char));
    
     sprintf(str,"%X",value);
        
   
    return str;
}