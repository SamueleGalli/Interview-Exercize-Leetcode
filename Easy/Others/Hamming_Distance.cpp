/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

 

Example 1:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

Example 2:

Input: x = 3, y = 1
Output: 1

 

Constraints:

    * 0 <= x, y <= 2^31 - 1

 

Note: This question is the same as 2220: Minimum Bit Flips to Convert Number.

*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        if (x < 0 || y < 0)
            return (0);
        int result = x ^ y;
        //ottenere un numero binario con 1 gli elementi diversi fra (x,y)
        int dist = 0;
        //conteggio 1 del numero con n ipotetico e n - 1 
        //il totale diventa il nuovo numero esempio(30 & 29 = 28) 
        while (result)
        {
            result = result & (result - 1);
            dist += 1;
        }
        return (dist);
    }
};