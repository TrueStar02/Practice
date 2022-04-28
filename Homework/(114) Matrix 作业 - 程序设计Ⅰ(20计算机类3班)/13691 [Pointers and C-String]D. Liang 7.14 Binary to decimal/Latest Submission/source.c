int parseBinary(const char * const binaryString) 
{   char **ptr=&binaryString;
    return (int)strtol(binaryString,ptr,2);

}