0010010
1101001
0101001
1010101

So count number of bits in the row. Then count its mid point. 

while(bitmap[row][count])
{
    count++
    bitmap[row][count] = bitmap[row][count] >> 1;
}

int right_low = count/2;
int right_high = count;
int left_low = width -1;
int left_high = count -1;
for(row = 0; row < count; row++)

then get num1, and num2, take half of the bit stream from left in num1 and remaining in the num2.

so num1 = 010
and num2 = 0010

reverse bit stream in num1 and num2 by
num3 = ((num1 & 0x01) << (right_high - i))
num4 = ((num2 & 0x01) << (left_high - i))

so num3 = 01000000
and num4 = 00000100

OR num3 and num4 = 01000100

repeat this for all row