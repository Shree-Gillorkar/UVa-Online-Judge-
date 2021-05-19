import sys
from sys import stdin
import math
from decimal import Decimal

def main():
    num_students=int(stdin.readline()) 
    while num_students!=0: 
        i=num_students 
        total_spending=0
        student_spending=[] 
        pos_difference=0 
        neg_difference=0 
        for i in range(i):
            current_spending=float(stdin.readline())
            student_spending.append(current_spending)
            total_spending+=current_spending
        average_spending=total_spending/num_students 
        
        lower_average_spending=math.floor(average_spending*100)/100  
        upper_average_spending=math.ceil(average_spending*100)/100
        for element in student_spending:
            if element>average_spending:
                pos_difference=pos_difference+element-upper_average_spending
            else:
                neg_difference=neg_difference+lower_average_spending-element 
        amount_exchanged=Decimal(max(neg_difference,pos_difference))
        amount_exchanged=round(amount_exchanged,2)
        print("$",amount_exchanged,sep="")            
        num_students=int(stdin.readline())


    return 
main()
sys.exit(0)