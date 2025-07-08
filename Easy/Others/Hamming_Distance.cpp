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