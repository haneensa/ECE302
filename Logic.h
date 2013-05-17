/**
 ECE302 final project
 Logic.h
 @author Haneen Mohammed& Amal Mukhtar
 @brief Functions for logical operations [AND,OR,NOR,NAND]
 */
string AND(string, string);
string OR(string, string);
string NAND(string, string);
string NOR(string, string);
bool AND(bool,bool);
bool OR(bool, bool);
bool NAND(bool, bool);
bool NOR(bool, bool);

string AND(string x, string y)
{
    unsigned long len = x.length();
    string z;
    for (int i = 0; i<len;i++)
    {
        if( x[i]=='1'&& y[i]=='1' )
            z.append("1");
        else
            z.append("0");
    }
    return z;
} 

string OR(string x, string y)
{
    unsigned long len = x.length();
    string z;
    for (int i = 0; i<len;i++)
    {
        if( x[i]=='1'|| y[i]=='1' )
            z.append("1");
        else
            z.append("0");
    }
    return z;
}

string NAND(string x, string y)
{
    unsigned long len = x.length();
    string z;
    for (int i = 0; i<len;i++)
    {
        if( x[i]=='1'&& y[i]=='1' )
            z.append("0");
        else
            z.append("1");
    }
    return z;
}

string NOR(string x, string y)
{
    unsigned long len = x.length();
    string z;
    for (int i = 0; i<len;i++){
        if( x[i]=='1'|| y[i]=='1' )
            z.append("0");
        else
            z.append("1");
    }
    return z;
}

bool AND(bool x, bool y)
{
        return x && y;
}

bool OR(bool x, bool y)
{
        return x || y;
}
    
bool NAND(bool x, bool y)
{
        return !(x && y);
    }
    bool NOR(bool x, bool y){
        return !(x || y);
}
