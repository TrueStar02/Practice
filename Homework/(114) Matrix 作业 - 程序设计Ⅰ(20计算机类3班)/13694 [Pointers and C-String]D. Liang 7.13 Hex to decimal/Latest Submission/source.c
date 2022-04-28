int parseHex(const char * const hexString) 
{   char **ptr=&hexString;
    return (int)strtol(hexString,ptr,16);

}