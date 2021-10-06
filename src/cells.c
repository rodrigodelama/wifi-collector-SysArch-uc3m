#include <stdbool.h> 
void print_X();
void print_all();

//boolean function to check to validate the MCA input(Draft)
//!!!!!!PROBLEM with Mac_input(line 8 and 15) (to review)   
bool MAC_check(char Mac_input[16]){
    
    bool accepted = true;

    if((!Mac_input[2].equals('-')&&!Mac_input[5].equals('-')&&!Mac_input[8].equals('-')&&!Mac_input[11].equals('-')&&!Mac_input[14].equals('-'))||(!Mac_input[2].equals(':')&&!Mac_input[5].equals(':')&&!Mac_input[11].equals(':')&&!Mac_input[14].equals(':')))
    {
       accepted = false; 
       return accepted;
    }

    int j=0;
    for (int i=0; i<16; i++){
        
        if(i==2||i==5||i==8||i==11||i==14)
        {
            i++;
        }

        if(!Mac_input[i].equals('-')||!Mac_input[i].equals(':'))
        {
            j++;
        }

        if(j==11)
            accepted = false;
            
    }
   return accepted;

}
