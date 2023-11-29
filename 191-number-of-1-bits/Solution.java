public class Solution 
{
    /**
     * Calculates the Hamming weight of a given integer.
     * The Hamming weight is the number of '1' bits in the binary representation of the integer.
     *
     * @param n The integer for which to calculate the Hamming weight. This integer is treated as unsigned.
     * @return The number of '1' bits in the binary representation of the integer.
     */
    public int hammingWeight(int n) 
    {
        String binary = Integer.toBinaryString(n);
        long count = binary.chars().filter(letter -> letter == '1').count();

        return (int)count;
    }
}