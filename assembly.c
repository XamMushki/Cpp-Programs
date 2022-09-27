    #include<stdio.h>  
    void main() {  
       int a = 10, b = 20, c;  
       
       _asm {  
          mov ax,a  
          mov bx,b  
          add ax,bx  
          mov c,ax  
       }   
    }  