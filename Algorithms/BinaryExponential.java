public class BinaryExponential {
    private static long MOD = 1000000007;
    public static void main(String[] args) {
        long  base = 2;
        long exponent = 10;
        long result = binaryExponential(base, exponent);
        System.out.println(base + " raised to the power of " + exponent + " is: " + result);
    }

    public static long binaryExponential(long x, long y){
        if(y == 0)
            return 1;
        long result = 1;
        while(y > 0){
            if((y & 1) == 1){
                result = (result * x) % MOD;
            }
            x = (x * x) % MOD;
            y >>= 1;
        }
        return result;
    }
}
