#finding factorial of number 
#!/bin/bash
echo enter the number
read num
fact=1

for((i=2;i<=0;i++))
{
   fact=$((fact*i))
}
echo $fact

#area of rectangle
#!/bin/bash

echo enter the side of square 
read num
result= `expr $num \* $num`
echo Area of the square is: $result

#given number perfect square or not
#!/bin/bash

echo "Enter a number"
read no  
i=1
ans=0
for i in 1 2 3 4 5 .. no  
do
        if [[ $((no%i)) -eq 0  ]]  
        then
            ans=$((ans + i))
            
fi
i=`expr $i + 1`
done

if [ $no -eq $ans ]  
then
        echo "$no is perfect"
        else
        echo "$no is NOT perfect"
fi


# prime number
#!/bin/bash

echo "enter number"
read num
function prime
{
for((i=2; i<=num/2; i++))
do
  if [ $((num%i)) -eq 0 ]
  then
    echo "$num is not a prime number."
    exit
  fi
done
echo "$num is a prime number."
}
r=`prime $number`
echo "$r"


# circumfarence of circle
#!/bin/bash

echo "Enter the radius of circle \c"
read RADIUS
PI=3.141
CIRCUM=$(echo "(2*$PI*$RADIUS)"|bc)
echo "\nCircumference of a circle is $CIRCUM"


# celcious to faren heat
#!/bin/bash

echo -n "Enter temperature (F) : "
read tf	
tc=$(echo "scale=2;(5/9)*($tf-32)"|bc)
echo "$tf = $tc"
	
	
#shell script to check whether a number is positive or negative
#!/bin/bash
echo "Enter a Number"
read num

if [ $num -lt 0 ]
then
    echo "Negative"
elif [ $num -gt 0 ]
then
    echo "Positive"
else
    echo "Neither Positive Nor Negative"
fi

#area of triangle
#!/bin/bash
echo -n "Enter base of a triangle : "
read b
 
echo -n "Enter height of a triangle : "
read h
area=$(echo "scale=2;(1/2) * $b * $h"|bc)
echo "Area of a triangle is $area"

#is it armstrong
#!/bin/bash
echo ”enter the number”
read n
q=$n
a=0
while [ $q – gt 0 ]
do
r= `expr $q % 10 `
q= `expr $q / 10 `
a=`expr $a + $r /* $r /*$r `
done
if [ $a=$n ]
then
echo “the number $n is armstrong number”
else
echo “the number $n is not armstrong number”
fi

#shell script to find the greatest of two numbers
#!/bin/bash
echo "Enter Num1"
read num1
echo "Enter Num2"
read num2

if [ $num1 -gt $num2 ]
then
    echo $num1
else
    echo $num2
fi

#printing 10 natural numbers
#!/bin/bash
echo "Using for loop to print"
for (( i=1; i<=10; i++ ))
do
   echo -n "$i "
done

#fibonic series
#!/bin/bash
N=6
a=0
b=1
echo "The Fibonacci series is : "
for (( i=0; i<N; i++ ))
do
	echo -n "$a "
	fn=$((a + b))
	a=$b
	b=$fn
done

#area and circumfernce of circle
#!/bin/bash
echo -n "Enter the radius of a circle : "
read r
area=$(echo "scale=2;3.14 * ($r * $r)" | bc)
d=$(echo "scale=2;2 * $r"|bc)
circumference=$(echo "scale=2;3.14 * $d"| bc)
echo "Area of circle is $area"
echo "Circumference of circle is $circumference"

#date
#!/bin/bash
date
date +'%m/%d/%Y'
var=$(date)
var=`date`
echo "$var"

#area of rectangle
#!/bin/bash
read -p "Enter a length: " length
read -p "Enter a width: " width
area=$[$length*$width]
echo "The area of the rectangle is $area"

#printing even prime
#!/bin/bash
echo -n "Number : "
read num;

for i in $(seq 0 $num)
do
   if [ $(expr $i % 2) == 0 ]
   then
        echo $i
   fi
done


