
bool sudoku(int b[9][9])
{   int x,y,z,w,add1,mul1,add2,mul2;
    for(x=0;x<9;x++)
    {   add1=add2=0;
        mul1=mul2=1;
        for(y=0;y<9;y++)
        {   add1+=b[x][y];
            add2+=b[y][x];
            mul1*=b[x][y];
            mul2*=b[y][x];
        }
        if(add1!=45||add2!=45||mul1!=362880||mul2!=362880)
            return 0;
    }
    for(x=0;x<9;x+=3)
    for(y=0;y<8;y+=3)
    {  add1=0;
        mul1=1;
         for(z=0;z<3;z++)
      
        for(w=0;w<3;w++)
        {   add1+=b[x+z][y+w];
            
            mul1*=b[x+z][y+w];
           
        }
        if(add1!=45||mul1!=362880)
            return 0;
    }
    return 1;

}
