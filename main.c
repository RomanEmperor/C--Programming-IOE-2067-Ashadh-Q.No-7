//
//  main.c
//  resturentBilling
//
//  Created by Notorious MAC on 7/2/16.
//  Copyright © 2016 NotoriousMAC. All rights reserved.
//

//WAP to open a file named Record.txt for n number of data where cost, service charge 5%, VAT 15% and total cost must be calculated by program itself.

#include <stdio.h>
#include <stdlib.h> // includes standard library

// structure define here
struct record {
    char icode[10];
    char des [20];
    float rate ;
    int qty;
    float cost ;
    
}r;

int main(int argc, const char * argv[]) {
    // insert code here...
    FILE *fp;
    int n,i;
    float vat, schar, tcost, t=0;
    
    // open file in write mode
    
    fp=fopen("RECORD.txt", "w");
    
    // check for error here
    
    if (fp == NULL) {
        printf("\nFile cannot be opened");
        exit(1);
    }
    
    printf("\nEnter number of records ");
    scanf("%d",&n);
    
    for (i=0; i<n; i++) {
        printf("\nEnter itemCode, description, rate and quantity");
        scanf("%s%s%f%d",r.icode,r.des,&r.rate,&r.qty);
        r.cost = r.rate * r.qty;
        fwrite(&r, sizeof(r), 1, fp);
    }
    fclose(fp);
    
    
    // open file in read mode
    fp = fopen("RECORD.txt", "r");
    
    // check for error here
    
    if (fp == NULL) {
        printf("\nFile cannot be opened");
        exit(1);
    }
    
    printf("\n Item Code \t Description \t Rate \t Quantity \t cost");
    while (fread(&r, sizeof(r), 1, fp)==1) {
        t=t+r.cost;
    
    
    printf("\n%s \t\t\t %s \t\t\t %f \t %d \t %f",r.icode,r.des,r.rate,r.qty,r.cost);
}
    
    vat = 0.15*t;
    schar = 0.05*t;
    tcost = t+vat+schar;
    printf("\nVAT = %f",vat);
    printf("\Service Charge = %f",schar);
    printf("\nTotal cost = %f",tcost);
    fclose(fp);
    

    
    return 0;
}
